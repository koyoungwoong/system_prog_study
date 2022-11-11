#include <stdio.h>
#include <unistd.h>

int num1 = 3;
int num2 = 4;

int main(){
  printf("num1 value is %d\n", num1);
  printf("num1 address is %p\n", &num1);
  printf("num2 value is %d\n", num2);
  printf("num2 address is %p\n", &num2);
  sleep(1000);
}


