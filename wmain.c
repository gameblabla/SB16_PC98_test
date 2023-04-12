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


int main(int argc,char **argv) 
{
	printf("IMF player\n");
	IMF_Init_Music(0);
	if (IMF_Load_Music("th4.imf") == 0) {
		printf("Cannot load!\n");
		return 1;
	}
	printf("Loaded IMF\n");
	IMF_Play_Music();
	printf("Playing IMF\n");
	while(1)
	{
		
	}
	IMF_Close_Music();
	
	return 0;
}

