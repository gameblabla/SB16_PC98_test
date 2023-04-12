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
#include <dos.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>
#include <conio.h>
#include <malloc.h>
#include <unistd.h>
#include <stdint.h>

#include "sound.h"
SoundDevice mainsound;

struct WaveData Voice;

int main(int argc,char **argv) 
{
	printf("DJGPP test\n");
	
	mainsound = SBDMA_device;

	mainsound.Sound_Init();
	mainsound.Sound_Load("TEST.WAV", &Voice);
	mainsound.Sound_Play(&Voice);
	
	printf("Play sound\n");

	return 0;
}

