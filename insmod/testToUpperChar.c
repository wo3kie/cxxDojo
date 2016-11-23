/*
 * Followed
 *   http://derekmolloy.ie/writing-a-linux-kernel-module-part-2-a-character-device/
 * by
     Derek Molloy
 */

#include<errno.h>
#include<fcntl.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

static char receive[256];   

int main(){
   int ret;
   int fd;
   char stringToSend[256];

   fd = open("/dev/ebbchar", O_RDWR);
   
   if (fd < 0){
      perror("Failed to open the device...");
      return errno;
   }
   
   printf("Type in a short string to send to the kernel module:\n");
   
   scanf("%[^\n]%*c", stringToSend);
   
   printf("Writing message to the device [%s].\n", stringToSend);
   
   ret = write(fd, stringToSend, strlen(stringToSend));
   
   if (ret < 0){
      perror("Failed to write the message to the device.");
      return errno;
   }

   printf("Press ENTER to read back from the device...\n");
   getchar();
   printf("Reading from the device...\n");
   
   ret = read(fd, receive, 256);
   
   if (ret < 0){
      perror("Failed to read the message from the device.");
      return errno;
   }
   
   printf("The received message is: [%s]\n", receive);
   
   printf("End of the program\n");
   
   return 0;
}

