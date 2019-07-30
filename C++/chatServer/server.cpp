
/*


   progrm thet illustrate the 

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace std;



struct Node
{


};


void *clientHandler(void *args)
{}

int main()
{

	pthread_t tId;
	pthread_attr_t attributes;

	int sockId;
	sockId = socket(AF_INET,SOCK_STREAM,0);
	if (sockId == 0)
	{
		fprintf(stderr,"Failed to create Socket\n");
		perror("");
		return 0;

	}

	struct sockaddr_in sockAddress;
	memset(&sockAddress,'\0',sizeof(sockAddress));
	sockAddress.sin_family  = AF_INET;
	sockAddress.sin_addr.s_addr = htonl(INADDR_ANY);
	sockAddress.sin_port = htons(2222);

	bind(sockId,(struct sockaddr*)&sockAddress,sizeof(sockAddress));
	listen(sockId,20);

	int clientID;

	while (1)
	{
		clientID = accept(sockId,(struct sockaddr*)NULL,NULL);
		fprintf(stderr,"socket id == [ %d ]\n",clientID);

		pthread_create(&tId,&attributes,clientHandler,&clientID);


	}

	pthread_join(tId,NULL);


	return 0;
}


void *clientHandler(void *args)
{

	int clientID = *(int*)args;

	fprintf(stderr,"socket id in thread == [ %d ]\n",clientID);

}
