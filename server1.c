#include"header.h"
void main(int argc,char **argv)
{
	if(argc<3)
	{
		return;
	}
	int sfd,nsfd;
	sfd=socket(AF_INET,SOCK_STREAM,0);
	perror("socket");
	struct sockaddr_in server_id,client_id;
	server_id.sin_family=AF_INET;
	server_id.sin_port=htons(atoi(argv[1]));
	server_id.sin_addr.s_addr=inet_addr(argv[2]);
	int len=sizeof(server_id);
	if(bind(sfd,(struct sockaddr*)&server_id,len)<0)
	{
		perror("bind");
		return;
	}
	perror("bind");
	if(listen(sfd,5)<0)
	{
		perror("listen");
		return;
	}
	perror("listen");
	printf("ready to accept\n");
	nsfd=accept(sfd,(struct sockaddr*)&client_id,&len);
	int num,num1,s;
	read(nsfd,&num,sizeof(num));
	//printf("%d\n",num);
	for(num1=num,s=0;num1;num1=num1/10)
		s=s*10+num1%10;
	write(nsfd,&s,sizeof(s));

	
}


