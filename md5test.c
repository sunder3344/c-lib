#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>
#include <sys/wait.h>
#include <signal.h>

#include <fcntl.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <gdbm.h>
#include "md5.h"

int main(int argc, char *argv[]) {
	MD5_CTX md5;
	MD5Init(&md5);
	int i;
	//unsigned char encrypt[] = "admin";
	char *encrypt;
	encrypt = argv[1];
	unsigned char decrypt[16];
	char *result = (char *)malloc(sizeof(char*) * 32);
	MD5Update(&md5, encrypt, strlen((char *)encrypt));
	MD5Final(&md5, decrypt);
	printf("encrypt := %s\n", encrypt);
	for(i = 0; i < 16; i++) {
		//printf("%02x",decrypt[i]);
		char *str = (char *)malloc(sizeof(char *) * 2);
		sprintf(str, "%02x", decrypt[i]);
		//printf("%s\n", str);
		strcat(result, str);
		free(str);
	}
	printf("decrypt str := %s\n", result);
	return 0;
}
