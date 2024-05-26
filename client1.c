#include"header.h"
void main(int argc,char **argv)
{
	if(argc<3)
	{
		return;
	}
	int sfd;
	sfd=socket(AF_INET,SOCK_STREAM,0);
	perror("socket");
	struct sockaddr_in server_id;
	server_id.sin_family=AF_INET;
	server_id.sin_port=htons(atoi(argv[1]));
	server_id.sin_addr.s_addr=inet_addr(argv[2]);
	int len=sizeof(server_id);
	if(connect(sfd,(struct sockaddr*)&server_id,len)<0)
	{
		perror("connect");
		return;
	}
	perror("connect");
	printf("enter value\n");
	int num;
	scanf("%d",&num);
	write(sfd,&num,sizeof(num));
	read(sfd,&num,sizeof(num));
	printf("Sum=%d\n",num);
	//printf("%d\n",num);
}


