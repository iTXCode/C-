#include<stdio.h>
#include<unistd.h>  
//只有Linux系统下才包含这个头文件,uni表示的是Unix
// chche 缓存    vs buffer 缓冲区
int main(){
  // \n表示换行，另起一个新行，光标会来到行首
  // \r表示回车，不另起新行，光标来到行首
  // sleep(1);Linux上的sleep单位为秒
  // usleep 单位为微秒
  // SLeep是windows上的系统函数，单位为毫秒
  //         行缓冲
  // 1. 缓冲区如果满了，就会真正写入到显示器上,如果把数据写到文件中,此时\n就不能刷新缓冲区了
  // 2. 如果遇到\n也会写到显示器上,遇到\n默认就会刷新缓冲区
  // 3.程序结束的时候也"可能"会刷新
  // 4.fflush手动刷新缓冲区
    
    const char *label="/-\\|";//效果转圈圈
    char buf[102]={0};
    int i=0;
    for(;i<100;i++){
      buf[i]='*';
      printf("[%s] [%d%%][%c]\r",buf,i,label[i%4]); //%%效果相当于一个转义字符
      fflush(stdout);  //手动刷新缓冲区
      usleep(500*1000); //单位为微秒
    }
    return 0;
    
}
