#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int rand_num(){
  int file = open("/dev/random", O_RDONLY);
  int rando;
  read(file, &rando,sizeOf(int));
  close(file);
  return rando;
}
int main(){
  int ary1[10];
  int ary2[10];
  printf("\nGenerating random numbers:\n");
  for(int i =0; i<10; i++){
    ary1[i]=rand_num();
    printf("ary1[%d] : % d \n", i, ary1[i]);
  }
  printf("\nWriting numbers to a file...\n");
  int file = open("foo", O_WRONLY || O_CREAT, 0744);
  write(file, ary1,sizeOf(ary1));
  close(file);
  printf("Done\n");
  
}
    
	      
  
      
