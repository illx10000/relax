#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <unistd.h>
#include "KafkaProducer.h"

int main(int argc, char* argv[])
{

	CKafkaProducer kp;

	char topic[] = "test";
	char brokers[] = "192.168.2.73:9092";
	int partition = 0;

	char str_msg[] = "Hello Kafka!";
	int ret = 0;

	ret = kp.init(topic, brokers, partition);
	if (ret != 0)
	{
		printf("Error: kp.init(): ret=%d; %s\n", ret, kp.getLastError());
		return 0;
	}

	ret = kp.sendMessage(str_msg, strlen(str_msg)); //向kafka服务器发送消息
	if (ret != 0)
	{
		printf("Error: kp.sendMessage(): ret=%d; %s\n", ret, kp.getLastError());
		return 0;
	}


	kp.poll(-1);

}