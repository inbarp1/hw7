#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int rand_num(){
  int file = open("/dev/random", O_RDONLY);
  int rando;
  read(file, &rando, 4);
  close(file);
  return rando;
}

int main(){
  int ary1[10];
  int ary2[10];
  
  printf("\nGenerating random numbers:\n");
  for(int i =0; i<10; i++){
    ary1[i]=rand_num();
    printf("ary1[%d] : %d \n", i, ary1[i]);
  }
 
  printf("\nWriting numbers to a file...\n");
  int file = open("foo", O_CREAT | O_WRONLY, 0777);
  write(file,ary1,40);
  close(file);
  
  printf("\nVerification that written values were the same:\n");
  file = open("foo", O_RDONLY);
  read(file, ary2,40);
  close(file);
  
  for(int i =0; i<10; i++){
    printf("ary2[%d] : %d \n", i, ary2[i]);
  }
  printf("\nComplete!\n");
}
    
	      
  
      
