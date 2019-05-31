//copy�ڣ�http://www.voidcn.com/article/p-anyqvhip-boa.html
//http://suntus.github.io/2016/07/07/librdkafka--kafka%20C%20api%E4%BB%8B%E7%BB%8D/

#ifndef __KAFAK_PRODUCER_H__
#define __KAFAK_PRODUCER_H__

#include "rdkafka.h"
#include <map>
#include <string>

class CKafkaProducer
{
public:
	//�������ش����ʱ��ִ�еĻص�
	typedef void(*lp_err_cb)			(rd_kafka_t* rk, int err, const char* reason, void* opaque); 

	// producer������Ϣ��consumerȡ��Ϣʱ����broker��������ʱ��ʱ�Ļص��������Ƿ���һ��ʱ�仹�Ƿ���0(����ȡ��)
	typedef void(*lp_throttle_cb)		(rd_kafka_t* rk, const char* broker_name, int32_t broker_id, int throttle_time_ms, void* opaque);

	//commit��ʱ��Ļص�����rd_kafka_consumer_poll()���ʹ��
	typedef void(*lp_offset_commit_cb)	(rd_kafka_t* rk, rd_kafka_resp_err_t err, rd_kafka_topic_partition_list_t* offsets, void* opaque);

	//ͳ��ʱ�ص�����rd_kafka_poll()ÿ��statistics.interval.ms(��Ҫ��������)����
	typedef int(*lp_stats_cb)			(rd_kafka_t* rk, char* json, size_t json_len, void* opaque);

	//������־����Ļص���Ĭ���Ǵ�ӡ��stderr�����õ�log_cb��rd_kafka_log_print(),
	typedef void(*lp_log_cb)			(const rd_kafka_t* rk, int level,const char* fac, const char* buf);

	//��Ϣ�ݽ������callback
	typedef void(*lp_dr_msg_cb)			(rd_kafka_t* rk, const rd_kafka_message_t* rkmessage, void* opaque);

public:
	CKafkaProducer();
	~CKafkaProducer();



	int init(char* topic, char* brokers, int partition,
		const std::map<std::string,std::string>& kafka_extend_conf = std::map<std::string, std::string>(),
		const std::map<std::string, std::string>& topic_extend_conf = std::map<std::string, std::string>(),
		lp_dr_msg_cb drcb = dr_msg_cb,
		lp_log_cb logcb = log_cb,
		lp_err_cb ecb = err_cb,
		lp_throttle_cb tcb = throttle_cb,
		lp_offset_commit_cb ocb = offset_commit_cb,
		lp_stats_cb	scb = stats_cb
	);

	int sendMessage(char* str, int len); //��kafka������������Ϣ

	int poll(int timeout_ms);

	char* getLastError();

	enum 
	{
		ERR_BUFFER_LEN = 1024
	};

public:
	static void err_cb				(rd_kafka_t* rk, int err, const char* reason, void* opaque);
	static void throttle_cb			(rd_kafka_t* rk, const char* broker_name, int32_t broker_id, int throttle_time_ms, void* opaque);
	static void offset_commit_cb	(rd_kafka_t* rk, rd_kafka_resp_err_t err, rd_kafka_topic_partition_list_t* offsets, void* opaque);
	static int  stats_cb			(rd_kafka_t* rk, char* json, size_t json_len, void* opaque);
	static void log_cb				(const rd_kafka_t* rk, int level, const char* fac, const char* buf);
	static void dr_msg_cb			(rd_kafka_t* rk, const rd_kafka_message_t* rkmessage, void* opaque);

	//topic="my_test"; brokers="192.168.1.42:9092"; partition=0;
	
private:
	rd_kafka_t*							m_kafka_handle;			//kafka��Ϣ�����߾��
	rd_kafka_topic_t*					m_kafka_topic;			//kafka��Ϣ��������
	rd_kafka_conf_t*					m_kafka_conf;			//kafka��Ϣ����
	rd_kafka_topic_conf_t*				m_kafka_topic_conf;
	rd_kafka_topic_partition_list_t*	m_kafka_topic_partition_list;
	int									m_partition;
	char								m_err[ERR_BUFFER_LEN];

};

#endif