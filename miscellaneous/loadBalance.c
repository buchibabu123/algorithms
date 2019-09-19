#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define LOAD_BALANCED_FILE "LB.txt"
#define SRV_FILE "srv.txt"

typedef struct Primary
{
	int priority;
	int weight;
	int LB_Weight;
}Primary;

typedef struct LoadBalanced_Data
{
	unsigned short priority;
	unsigned short weight;
	unsigned int srv_ttl;
	char srv_name[128];
	char srv_target[128];
	unsigned long int now;
	unsigned short port;
	unsigned int lbWeight;
	struct LoadBalanced_Data *link;
}LoadBalanced_Data;

struct LoadBalanced_Data *srv_head = NULL;
struct LoadBalanced_Data *LB_head = NULL;
struct LoadBalanced_Data *extraNodes = NULL;

int createUpdate(char *dest,const char*src,char *primary,const char *secondary)
{

	FILE *fp = fopen(dest,"w");
	if(fp == NULL)
	{
		perror("\n");
		printf("file opened fial == [%s ]\n",dest);
		return -1;
	}

	FILE *sr = fopen(src,"r");
	if(sr == NULL)
	{

		perror("\n");
		printf("file opened fial == [%s ]\n",src);
		fclose(fp);
		return -1;
	}

	char *buff = (char*)malloc(sizeof(char));
	size_t len =0;

	char s[128],d[128];
	unsigned short int  pr,w,po;
	unsigned long int now;
	unsigned int sttl;
	unsigned char bufferO[128];
	int count=0;
	while(getline(&buff,&len,sr) != -1)
	{
		memset(bufferO,'\0',sizeof(bufferO));
		printf("line == [ %s ]\n",buff);
		sscanf(buff,"%[^,],%u,%[^,],%hu,%hu,%hu,%lu",s,&sttl,d,&w,&po,&pr,&now);
		if(!strcmp(s,primary) || !strcmp(s,secondary))
		{
			count =1;
		}
		else
			count =0;
		sprintf(bufferO,"%s,%d,%s,%d,%d,%d,%ld,%d\n",s,sttl,d,w,po,pr,now,count);
		//sprintf(bufferO,"%s\n",buff);
		printf("buffer == [ %s ]\n",bufferO);
		//		fwrite(bufferO,len+1,1,fp);
		fputs(bufferO,fp);

	}
	free(buff);
	fclose(fp);
	fclose(sr);
	return 0;
}




int addList(const struct LoadBalanced_Data obj,LoadBalanced_Data **head)
{
	printf("adding list\n");
	LoadBalanced_Data *node = (LoadBalanced_Data*)malloc(sizeof(LoadBalanced_Data));
	memset(node,'\0',sizeof(LoadBalanced_Data));
	//memcpy(node,obj,sizeof(obj));
	strcpy(node->srv_name,obj.srv_name);
	strcpy(node->srv_target,obj.srv_target);
	node->priority = obj.priority;
	node->srv_ttl = obj.srv_ttl;
	node->now  = obj.now ;
	node->port = obj.port ;
	node->weight = obj.weight;
	node->lbWeight = obj.lbWeight;
	node->link =  NULL;
	if(*head == NULL)
	{
		printf("head is null\n");
		*head = node;
		return 0;

	}
	LoadBalanced_Data *temp = *head;
	while(temp->link!=NULL)
	{
		temp = temp->link;
	}

	temp->link = node;

}

void printList(LoadBalanced_Data *head)
{

	LoadBalanced_Data *node = head;

	while(node != NULL)
	{

		printf("record data == [ %s ] lbWeight == [ %d ],prio == [ %d ],weight == [ %d ],address == [ %lu ]\n",node->srv_name,node->lbWeight,node->priority,node->weight,node);
		node = node->link;
	}

}

int createList(char *file,bool flag,LoadBalanced_Data **head)
{

	FILE *fp = fopen(file,"r");
	if(fp == NULL)
	{
		printf("failed to open file == [ %s ]\n",file);
		perror("\n");
		return -1;

	}

	char *buff = (char*)malloc(sizeof(char));
	size_t len =0;

	char s[128],d[128];
	unsigned short int  pr,w,po;
	unsigned long int now;
	unsigned int sttl;
	char bufferO[128];
	int count=0;
	unsigned int weight=0;

	while(getline(&buff,&len,fp) != -1)
	{

		LoadBalanced_Data obj;
		memset(&obj,'\0',sizeof(LoadBalanced_Data));
		printf("line == [ %s ]\n",buff);
		if(flag == 0)
			sscanf(buff,"%[^,],%u,%[^,],%hu,%hu,%hu,%lu",s,&sttl,d,&w,&po,&pr,&now);

		else
			sscanf(buff,"%[^,],%u,%[^,],%hu,%hu,%hu,%lu,%u",s,&sttl,d,&w,&po,&pr,&now,&weight);


		strcpy(obj.srv_name,s);
		strcpy(obj.srv_target,d);
		obj.srv_ttl = sttl;
		obj.now = now;
		obj.weight = w;
		obj.port = po;
		obj.priority = pr;
		obj.lbWeight = weight;
		addList(obj,head);
	}

	fclose(fp);
	free(buff);
	printf("list 1 done printing srv,txt \n");
	printList(*head);
	fp = NULL;
	buff = NULL;
}
# if 0
FILE *fp1 = fopen("LB.txt","r");
while(getline(&buff1,&len,fp1) != -1)
{

	LoadBalanced_Data obj;
	memset(&obj,'\0',sizeof(LoadBalanced_Data));
	printf("======= line == [ %s ]\n",buff1);
	sscanf(buff1,"%[^,],%u,%[^,],%hu,%hu,%hu,%lu,%u",s,&sttl,d,&w,&po,&pr,&now,&weight);
	strcpy(obj.srv_name,s);
	strcpy(obj.srv_target,d);
	obj.srv_ttl = sttl;
	obj.now = now;
	obj.weight = w;
	obj.port = po;
	obj.priority = pr;
	obj.lbWeight = weight;
	addList(obj,&LB_head);
	printf("after adding\n");

}
fclose(fp1);
//free(buff1);
printf("************\n");
printf("list 1 done printing LB.txt \n");
printList(LB_head);

}
#endif

int getLB_Weight(const char *name,LoadBalanced_Data *lb)
{

	LoadBalanced_Data *temp = lb;
	int weight = 0;
	while(temp != NULL)
	{
		printf("matching [ %s ] with [ %s ]\n",name,temp->srv_name);
		if(!strcmp(temp->srv_name,name))
		{
			weight = temp->lbWeight;	
			break;
		}
		temp = temp->link;
	}
	return weight;
}

void updateList(LoadBalanced_Data *srv,const LoadBalanced_Data *lb)
{

	LoadBalanced_Data *temp = srv;
	int val =0;
	while(temp != NULL)
	{
		val = getLB_Weight(temp->srv_name,lb);
		temp->lbWeight = val;
		temp = temp->link;
	}

}

bool removeList(LoadBalanced_Data **node)
{
	LoadBalanced_Data *current = *node;
	LoadBalanced_Data *temp;
	while(current != NULL)
	{
		temp = current->link;
		printf("removing == [ %s ], address == [ %lu ]\n",current->srv_name,current);
		free(current);
		printf("after free\n");
		current = temp;
		printf("after current\n");
	}
	*node = NULL;
	printf("removind done\n");

}

int updateFile(LoadBalanced_Data *srvHead)
{

	unsigned char buff[128];
	LoadBalanced_Data *node = srvHead;
	FILE *fp = fopen("LB.txt","w");
	if(fp == NULL)
	{
		perror("\n");
		return -1;
	}
	while(node)
	{
		memset(buff,'\0',sizeof(buff));

		sprintf(buff,"%s,%d,%s,%d,%d,%d,%ld,%d\n",node->srv_name,node->srv_ttl,node->srv_target,node->weight,node->port,node->priority,node->now,node->lbWeight);
		//printf("\n\n buffer =  [ %s ]\n\n",buff);
		fputs(buff,fp);
		//		fwrite(buff,sizeof(buff),1,fp);
		node = node->link;
	}

	fclose(fp);
}


Primary  getPrimaryWeight(unsigned char *primary,LoadBalanced_Data *node,LoadBalanced_Data **lbNode,int *index)
{

	LoadBalanced_Data *temp = node;
	Primary obj;
	int count =0;
	while(temp != NULL)
	{

		if(!strcmp(temp->srv_name,primary))
		{
			break;
		}
		count++;
		temp = temp->link;
	}
	obj.LB_Weight = temp->lbWeight;
	obj.priority = temp->priority;
	obj.weight = temp->weight;
	if(lbNode == NULL && index == NULL)
		return obj;
	else{
		*lbNode = temp;
		*index = count;
		return obj;
	}

}

#if 0
LoadBalanced_Data *GetLBNode(unsigned char *primary)
{

	LoadBalanced_Data *temp = srv_head;
	while(temp != NULL)
	{
		if(!strcmp(primary,temp->srv_name))
			break;
		temp = temp->link;
	}
	return temp;

}
#endif

char *getServer(LoadBalanced_Data *srHead,char *server)
{
		printf("server is  == [ %s ]\n",server);
	if(server == NULL)	
	{
		printf("server is empty\n");
		return NULL;
	}

	LoadBalanced_Data *LB_Node= NULL;
	int count=0;
	Primary obj = getPrimaryWeight(server,srHead,&LB_Node,&count);
	printf("primary server weight is == [ %d ],prio == [%d],weight == [%d],index == [ %d ]\n",obj.LB_Weight,obj.priority,obj.weight,count);
	LoadBalanced_Data *temp = srHead;
	while(temp != NULL)
	{
		printf(" %d \t %d\t %d\n",temp->lbWeight,temp->priority,temp->weight);
		if(temp->priority == obj.priority && temp->weight == obj.weight)
		{

			if(temp->lbWeight < obj.LB_Weight)
			{
				if(LB_Node)
				{
					if(temp->lbWeight < LB_Node->lbWeight )
						LB_Node = temp;
				}
			}	

		}	

		temp = temp->link;
	}

	LB_Node->lbWeight+=1;
	strcpy(server,LB_Node->srv_name);
}

LoadBalanced_Data *getNewServer(LoadBalanced_Data *srHead,char *server,int *index)
{
	if(server == NULL)
		return NULL;

	int count = 0,countServer=0;
	bool flag = false;
	LoadBalanced_Data *LB_Node= NULL;
	Primary obj = getPrimaryWeight(server,srHead,&LB_Node,&countServer);
	printf("primary server weight is == [ %d ],prio == [%d],weight == [%d]\n",obj.LB_Weight,obj.priority,obj.weight);
	LoadBalanced_Data *temp = srHead;
	while(temp != NULL)
	{
		printf(" list server == [ %s ] LB weight == [ %d ] \t priority == [ %d ] \t weight == [ %d ]\n",temp->srv_name,temp->lbWeight,temp->priority,temp->weight);
		if(temp->priority == obj.priority && temp->weight == obj.weight)
		{

			if(temp->lbWeight  == 0)
			{
				flag = true;
				LB_Node = temp;
				break;
			}	

		}	

		temp = temp->link;
		count++;
	}

	LB_Node->lbWeight=1;
	strcpy(server,LB_Node->srv_name);
	if(flag == true)
		*index = count;
	else
	{
		*index = countServer;
	}
	printf("loop done inde x== [ %d ]\n",*index);
	return LB_Node;

}

int compareLists(LoadBalanced_Data *srv,LoadBalanced_Data *lb,LoadBalanced_Data **addedNodes)
{

	LoadBalanced_Data *temp = srv;

	bool flag = false;

	while( temp != NULL)
	{
		LoadBalanced_Data *node = lb;
			printf("object server name == [ %s ],list name == [ %s ]\n\n",node->srv_name,temp->srv_name);
		while(node != NULL)
		{

			if(!strcmp(node->srv_name,temp->srv_name))
			{
				flag = 	true;
				break;

			}
			node = node->link;
		}
		if(flag == false){
			printf("*********object server name == [ %s ],list name == [ %s ]\n\n",node->srv_name,temp->srv_name);
			LoadBalanced_Data obj;
			strcpy(obj.srv_name,temp->srv_name);
			strcpy(obj.srv_target,temp->srv_target);
			obj.srv_ttl = temp->srv_ttl;
			obj.now = temp->now;
			obj.weight = temp->weight;
			obj.port = temp->port;
			obj.priority = temp->priority;
			obj.lbWeight = temp->lbWeight;
			addList(obj,addedNodes);
		}
		temp = temp->link;
		flag = false;
	}

	if(*addedNodes != NULL)
		return -1;
	else
		return 0;
}

int checkGrouping(const Primary  obj,LoadBalanced_Data *node )
{

	LoadBalanced_Data *temp = node;


	while(temp != NULL)
	{
		printf("temp \t prio = [ %d ],weight == [ %d ],lb == [ %d ]\t\t prio = [ %d ],weight == [ %d ],lb == [ %d ]\n",temp->priority,temp->weight,temp->lbWeight,obj.priority,obj.weight,obj.LB_Weight);
		if(temp->weight == obj.weight && temp->priority == obj.priority)
			return 0;

		temp = temp->link;
	}
	return -1;
}


void updateLoad(LoadBalanced_Data *srv_head,LoadBalanced_Data *lb_Node,int index1,int index2)
{
	LoadBalanced_Data *temp = srv_head;
	int count =0;
	while(temp != NULL)
	{

		if(count == index1 || count == index2 )
			temp->lbWeight = 1;
		else if (lb_Node->priority == temp->priority && lb_Node->weight == temp->weight)
			temp->lbWeight = 0;
		temp = temp->link;
		count++;
	}



}

void getNewPrimary(char *primary,char *secondary)
{

	createList(SRV_FILE,0,&srv_head);
	createList(LOAD_BALANCED_FILE,1,&LB_head);
	printf("SRV List\n");
	printList(srv_head);
	printf("LB List\n");
	printList(LB_head);
	updateList(srv_head,LB_head);
	printf("updating done\n");
	printf("SRV List\n\n");
	printList(srv_head);


	if(compareLists(srv_head,LB_head,&extraNodes) == 0 )
	{
		printf("both lists are identical\n");
		printf("\nbefore Load balancing Primary == [ %s ],secondary == [ %s ]\n",primary,secondary);
		getServer(srv_head,primary);
		getServer(srv_head,secondary);
		//getLBServer(srv_head,primary,secondary);
		printf("\nafter Load balancing Primary == [ %s ],secondary == [ %s ]\n",primary,secondary);

	}
	else{
		int index1=-1,index2=-1;
		LoadBalanced_Data *lb_Node=NULL;
		Primary obj = getPrimaryWeight(primary,srv_head,NULL,NULL);
		int ret = checkGrouping(obj,extraNodes);
		if( ret == 0 )
		{
			printf("===========--------------both lists are not identical new record added with same proio and weight of primary\n");
			printf("\nbefore Load balancing Primary == [ %s ],secondary == [ %s ]\n",primary,secondary);
			lb_Node = getNewServer(srv_head,primary,&index1);
			if(lb_Node)
				updateLoad(srv_head,lb_Node,index1,index2);
			//getLBServer(srv_head,primary,secondary);
			printf("index == [ %d ]\n",index1);
		//	updateLoad(srv_head,lb_Node,index1,-1);
			printf("\nafter Load balancing Primary == [ %s ],secondary == [ %s ]\n",primary,secondary);

		}
		else
		{	
			printf(" both lists are not identical and new records not matched with existing records \n");
			getServer(srv_head,primary);
			printf("\nafter Load balancing Primary == [ %s ],secondary == [ %s ]\n",primary,secondary);

		}
		 obj = getPrimaryWeight(secondary,srv_head,NULL,NULL);
		 ret = checkGrouping(obj,extraNodes);
		printf("\n handling secndary \n");
		if( ret == 0 )
		{
			printf("===========--------------both lists are not identical new record added with same proio and weight of primary\n");
			printf("\nbefore Load balancing Primary == [ %s ],secondary == [ %s ]\n",primary,secondary);
			lb_Node = getNewServer(srv_head,secondary,&index2);
			if(lb_Node)
				updateLoad(srv_head,lb_Node,index1,index2);
			//getLBServer(srv_head,primary,secondary);
			printf("index == [ %d ]\n",index2);
			printf("\nafter Load balancing Primary == [ %s ],secondary == [ %s ]\n",primary,secondary);

		}
		else
		{	
			printf(" both lists are not identical and new records not matched with existing records \n");
			getServer(srv_head,secondary);
			printf("\nafter Load balancing Primary == [ %s ],secondary == [ %s ]\n",primary,secondary);

		}
		printf("\n handling secndary done\n");
		//if(lb_Node != NULL)
			updateLoad(srv_head,lb_Node,index1,index2);
	}
	printf("before updating content\n");
	updateFile(srv_head);
	printf("before removing srv\n");
	removeList(&srv_head);
	printf("before removing LB records\n");
	removeList(&LB_head);
	printf("\nfreeing extra nodes\n");
	removeList(&extraNodes);
	printf("\nfreeing extra nodes\n");


}
int main(int argc,char*argv[])
{
	char primary[128],secondary[128];
	if(argc >= 2)
	{

		sprintf(primary,argv[1]);
		sprintf(secondary,argv[2]);
		printf("[rimary == [  %s]\t,secondary == [%s]\n",primary,secondary);

	}
	else
	{
		printf("please provide 2 argiuments\n");
		return -1;
	}

	unsigned char *buff;
	size_t len=0;

	if(access(LOAD_BALANCED_FILE,F_OK) != -1)
	{
		printf("file exists\n");

		// case 1 both primary and secondary has same weight and priority
		getNewPrimary(primary,secondary);

	}

	else
	{
		printf("creating file\n");
		createUpdate(LOAD_BALANCED_FILE,"srv.txt",primary,secondary);



	}
	/*while(getline(&buff,&len,fp)!=NULL)
	  {

	  printf(" line == [ %s ]\n",buff);

	  }*/


	return 0;
}
