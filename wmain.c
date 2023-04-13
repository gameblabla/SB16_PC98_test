#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <malloc.h>
#include <ctype.h>
#include <fcntl.h>
#include <math.h>
#include <i86.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>
#include <conio.h>
#include <malloc.h>
#include <unistd.h>
#include <stdint.h>

#include "sound.h"


void *loadfile(const char* filename, long* length) {

	// Very simple file loader routine
	
	void* buff;
	long size;
	FILE* fp;
	
	printf("Opening file %s...\n", filename);
	fp = fopen(filename, "rb");
	
	if (!fp) {
		printf("Cannot load %s!\n", filename);
		return NULL;
	}
	
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	
	printf("Loading %u bytes...\n", size);
	
	buff = malloc(size);
	fread(buff, 1, size, fp);

	fclose(fp);
	
	if ( length ) {
		*length = size;
	}		

	return buff;    
}

int main(int argc,char **argv) 
{
	void* imf;
	long imflen;

	
	imf = loadfile("TH4.IMF", &imflen);
	if (!imf) {
		printf("Can't load IMF file\n");
		return 0;
	}

	InstallPlayer(560);
	PlayIMF(imf, (int)imflen);

	while (1) 
	{

	}

	return 0;
}


