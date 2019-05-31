#include "KafkaProducer.h"
#include <stdlib.h>
#include <memory.h>
#include <string.h>
using namespace std;

CKafkaProducer::CKafkaProducer()
{
	m_kafka_handle = NULL;
	m_kafka_topic = NULL;
	m_kafka_conf = NULL;
	m_kafka_topic_conf = NULL;
	m_kafka_topic_partition_list = NULL;

	m_partition = RD_KAFKA_PARTITION_UA;
	memset(m_err, ERR_BUFFER_LEN, 0);
}

CKafkaProducer::~CKafkaProducer()
{
	rd_kafka_flush(m_kafka_handle, 10 * 1000); //wait for max 10 seconds

	rd_kafka_topic_destroy(m_kafka_topic);
	rd_kafka_destroy(m_kafka_handle);
	rd_kafka_topic_partition_list_destroy(m_kafka_topic_partition_list);
}

int CKafkaProducer::init(char* topic, char* brokers, int partition, 
	const std::map<std::string, std::string>& kafka_extend_conf,
	const std::map<std::string, std::string>& topic_extend_conf,
	lp_dr_msg_cb drcb, lp_log_cb logcb, lp_err_cb ecb, 
	lp_throttle_cb tcb, lp_offset_commit_cb ocb, lp_stats_cb scb)
{
	int ret = 0;
	rd_kafka_conf_res_t ret_conf = RD_KAFKA_CONF_OK;
	char errstr[ERR_BUFFER_LEN] = { 0 };

	m_kafka_conf = rd_kafka_conf_new();

	rd_kafka_conf_set_dr_msg_cb(m_kafka_conf,drcb);
	rd_kafka_conf_set_log_cb(m_kafka_conf, logcb);
	rd_kafka_conf_set_error_cb(m_kafka_conf, ecb);
	rd_kafka_conf_set_throttle_cb(m_kafka_conf, tcb);
	rd_kafka_conf_set_offset_commit_cb(m_kafka_conf, ocb);
	rd_kafka_conf_set_stats_cb(m_kafka_conf, scb);

	//---------Producer config-------------------
	ret_conf = rd_kafka_conf_set(m_kafka_conf, "queue.buffering.max.messages", "500000", errstr, sizeof(errstr));
	if (ret_conf != RD_KAFKA_CONF_OK) 
	{ 
		snprintf(m_err, ERR_BUFFER_LEN, "Error: rd_kafka_conf_set() failed 1; ret_conf=%d; errstr:%s", ret_conf, errstr);
		return -1; 
	}

	ret_conf = rd_kafka_conf_set(m_kafka_conf, "message.send.max.retries", "3", errstr, sizeof(errstr));
	if (ret_conf != RD_KAFKA_CONF_OK) 
	{ 
		snprintf(m_err, ERR_BUFFER_LEN, "Error: rd_kafka_conf_set() failed 2; ret_conf=%d; errstr:%s", ret_conf, errstr);
		return -1; 
	}

	ret_conf = rd_kafka_conf_set(m_kafka_conf, "retry.backoff.ms", "500", errstr, sizeof(errstr));
	if (ret_conf != RD_KAFKA_CONF_OK) 
	{ 
		snprintf(m_err, ERR_BUFFER_LEN, "Error: rd_kafka_conf_set() failed 3; ret_conf=%d; errstr:%s", ret_conf, errstr);
		return -1; 
	}

	ret_conf = rd_kafka_conf_set(m_kafka_conf, "message.timeout.ms", "500", errstr, sizeof(errstr));
	if (ret_conf != RD_KAFKA_CONF_OK)
	{
		snprintf(m_err, ERR_BUFFER_LEN, "Error: rd_kafka_conf_set() failed 3; ret_conf=%d; errstr:%s", ret_conf, errstr);
		return -1;
	}

	//扩展配置
	for (map<string, string>::const_iterator it = kafka_extend_conf.begin(); 
		it != kafka_extend_conf.end(); ++it)
	{
		ret_conf = rd_kafka_conf_set(m_kafka_conf, it->first.c_str() , it->second.c_str(), errstr, sizeof(errstr));
		if (ret_conf != RD_KAFKA_CONF_OK)
		{
			snprintf(m_err, ERR_BUFFER_LEN, "Error: rd_kafka_conf_set() failed 7; ret_conf=%d; errstr:%s", ret_conf, errstr);
			return -1;
		}
	}

	//---------Kafka topic config-------------------
	m_kafka_topic_conf = rd_kafka_topic_conf_new();

	ret_conf = rd_kafka_topic_conf_set(m_kafka_topic_conf, "auto.offset.reset", "earliest", errstr, sizeof(errstr));
	if (ret_conf != RD_KAFKA_CONF_OK) 
	{ 
		snprintf(m_err, ERR_BUFFER_LEN, "Error: rd_kafka_conf_set() failed 4; ret_conf=%d; errstr:%s", ret_conf, errstr);
		return -1;
	}
	//扩展topic配置
	for (map<string, string>::const_iterator it = topic_extend_conf.begin();
		it != topic_extend_conf.end(); ++it)
	{
		ret_conf = rd_kafka_topic_conf_set(m_kafka_topic_conf, it->first.c_str(), it->second.c_str(), errstr, sizeof(errstr));
		if (ret_conf != RD_KAFKA_CONF_OK)
		{
			snprintf(m_err, ERR_BUFFER_LEN, "Error: rd_kafka_conf_set() failed 3; ret_conf=%d; errstr:%s", ret_conf, errstr);
			return -1;
		}
	}


	m_kafka_topic_partition_list = rd_kafka_topic_partition_list_new(1);

	rd_kafka_topic_partition_list_add(m_kafka_topic_partition_list, topic, partition); //可以add一个以上的topic

	m_partition = partition;

	//---------Create Kafka handle-------------------
	m_kafka_handle = rd_kafka_new(RD_KAFKA_PRODUCER, m_kafka_conf, errstr, sizeof(errstr));

	if (m_kafka_handle == NULL)
	{
		snprintf(m_err, ERR_BUFFER_LEN, "Error: Failed to create Kafka producer: %s", errstr);
		return -5;
	}

	//---------Add broker(s)-------------------
	if (brokers && rd_kafka_brokers_add(m_kafka_handle, brokers) < 1)
	{
		snprintf(m_err, ERR_BUFFER_LEN, "Error: No valid brokers specified");
		return -6;
	}

	m_kafka_topic = rd_kafka_topic_new(m_kafka_handle, topic, m_kafka_topic_conf); //Explicitly create topic to avoid per-msg lookups

	return ret;
}

int CKafkaProducer::sendMessage(char* str, int len)
{
	int ret = 0;

	if (str == NULL) { return -1; }
	if (len <= 0) { return -2; }

	//char* topic = m_kafka_topic_partition_list->elems[0].topic;
	int partition = m_kafka_topic_partition_list->elems[0].partition;

	//	char * buf = (char *)malloc(len);
	//	memcpy(buf, str, len);

   //------------向kafka服务器发送消息----------------
	ret = rd_kafka_produce(m_kafka_topic, partition, RD_KAFKA_MSG_F_COPY | RD_KAFKA_MSG_F_FREE, str, len, NULL, 0, NULL);

	if (ret == -1)
	{
		rd_kafka_resp_err_t err = rd_kafka_last_error();

		if (err == RD_KAFKA_RESP_ERR__UNKNOWN_PARTITION)
		{
			snprintf(m_err, ERR_BUFFER_LEN, "Error: No such partition: %d\n", partition);
			
		}
		else
		{
			snprintf(m_err, ERR_BUFFER_LEN, "Error: produce error: %s%s\n", rd_kafka_err2str(err), err == RD_KAFKA_RESP_ERR__QUEUE_FULL ? " (backpressure)" : "");
		}

		rd_kafka_poll(m_kafka_handle, 10); //Poll to handle delivery reports

		return -10002; //覆盖原来的错误码
	}

	rd_kafka_poll(m_kafka_handle, 0);

	return ret;
}

char* CKafkaProducer::getLastError()
{
	return m_err;
}

int CKafkaProducer::poll(int timeout_ms)
{
	return rd_kafka_poll(m_kafka_handle, timeout_ms);
}

void CKafkaProducer::err_cb(rd_kafka_t* rk, int err, const char* reason, void* opaque)
{
	printf("%% ERROR CALLBACK: %s: %s: %s\n", rd_kafka_name(rk), rd_kafka_err2str((rd_kafka_resp_err_t)err), reason);
}

void CKafkaProducer::throttle_cb(rd_kafka_t* rk, const char* broker_name, int32_t broker_id, int throttle_time_ms, void* opaque)
{
	printf("%% THROTTLED %d ms by %s (%d)\n", throttle_time_ms, broker_name, broker_id);
}

void CKafkaProducer::offset_commit_cb(rd_kafka_t* rk, rd_kafka_resp_err_t err, rd_kafka_topic_partition_list_t* offsets, void* opaque)
{
	int i;
	int verbosity = 1;

	if (err || verbosity >= 2)
	{
		printf("%% Offset commit of %d partition(s): %s\n", offsets->cnt, rd_kafka_err2str(err));
	}

	for (i = 0; i < offsets->cnt; i++)
	{
		rd_kafka_topic_partition_t* rktpar = &offsets->elems[i];

		if (rktpar->err || verbosity >= 2)
		{
			printf("%s %u %ulld: %s\n", rktpar->topic, rktpar->partition, rktpar->offset, rd_kafka_err2str(err));
		}
	}
}

int CKafkaProducer::stats_cb(rd_kafka_t* rk, char* json, size_t json_len, void* opaque)
{
	printf("%s\n", json);
	return 0;
}

void CKafkaProducer::log_cb(const rd_kafka_t* rk, int level, const char* fac, const char* buf)
{
	printf("%s\n", fac);
}

void CKafkaProducer::dr_msg_cb(rd_kafka_t* rk, const rd_kafka_message_t* rkmessage, void* opaque)
{
	if (rkmessage->err)
	{
		printf("%% Message delivery failed: %s\n", rd_kafka_err2str(rkmessage->err));
	}
	else
	{
		printf("Message delivered (%zd bytes, partition %d)\n",rkmessage->len, rkmessage->partition);
	}
		
}
