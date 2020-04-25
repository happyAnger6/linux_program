#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#define PIPE_READ_FD 0
#define PIPE_WRITE_FD 1
#define MAX_BUF_SIZE 4096

int child_do_pipe(int rfd)
{
	char buf[MAX_BUF_SIZE+1];
	int total = 0;
	printf("try to read\r\n");
	total = read(rfd, buf, sizeof(buf)-1);
	if(total < 0)
	{
		printf("read error:%s\r\n", strerror(errno));
	}
	printf("read cnt:%d\r\n", total);
	sleep(15);
}

int father_do_pipe(int wfd)
{
	int buf[MAX_BUF_SIZE+1]={0};
	int i = 0, total = 0;
	for(i = 0; i < 100; i++)
	{
		printf("write times:%d\r\n", i);
		total += write(wfd, buf, sizeof(buf)-1);
		if(total < 0)
		{
			printf("write error:%s\r\n", strerror(errno));
		}
		printf("write total:%d\r\n", total);
	}	
	return 0;
}

int main(int argc, char *argv[])
{
	int fds[2];

	int ret = pipe(fds);
	if(ret < 0)
	{
		printf("pipe error\n");
		return 0;
	}
		
//	close(fds[PIPE_WRITE_FD]);
	father_do_pipe(fds[PIPE_READ_FD]);

	int pid = fork();
	if(pid == 0)
	{
		close(fds[PIPE_WRITE_FD]);
		child_do_pipe(fds[PIPE_READ_FD]);
		printf("child done.\r\n");
		exit(0);
	}
	else if(pid > 0)
	{
		close(fds[PIPE_READ_FD]);
		father_do_pipe(fds[PIPE_WRITE_FD]);
		printf("child done.\r\n");
		exit(0);
	}
	else
	{
		printf("fork error.\r\n");
	}

	return 0;
}
