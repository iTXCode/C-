#include<stdio.h>   
#include <unistd.h>
#include<string.h>
int main()
{
   int i = 0;
    char bar[101];
     memset(bar,'\0' ,sizeof(bar));
      const char *lable="-|/\\";
      while(i <=100){ 
        printf("[%-100s][%d%%][%c]\r", bar, i, lable[i%4]);
         bar[i++] = '*';  
          fflush(stdout);
            usleep(500*1000);  //单位为毫秒    
      }
      printf("\n");
        return 0;
}

