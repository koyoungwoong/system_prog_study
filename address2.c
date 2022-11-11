#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int num1 = 1;
int num2;
int arr1[100000] = {1,2,3};
int arr2[100000];
int *mp;

int foo(){
  printf("foo function\n");
  return 2;
}

int main(){
  int num3 = 4;
  int num4;
  num2 = 3;
  num4 = foo();
  mp = malloc(sizeof(int));
  *mp = (int) 5;

  printf("num1 value is %d\n", num1);
  printf("num1 address is %p\n", &num1);
  printf("num2 value is %d\n", num2);
  printf("num2 address is %p\n", &num2);
  printf("num3 value is %d\n", num3);
  printf("num3 address is %p\n", &num3);
  printf("num4 value is %d\n", num4);
  printf("num4 address is %p\n", &num4);
  printf("mp value is %d\n", *mp);
  printf("mp address is %p\n", mp);
  printf("foo address is %p\n", foo);
  printf("arr1 address is %p\n", &arr1[0]);
  printf("arr2 address is %p\n", &arr2[0]);

  sleep(1000);
  free(mp);
}


