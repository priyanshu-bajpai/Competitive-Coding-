#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int main(void)
{
  FILE *fp;
  int array1[3];
  int linect = 1;
  int linesum = 0;
  char buf[128];
 
  fp = fopen("input.txt", "r");
   
  if(fp == NULL)
  {
    puts("Cannot open file for reading");
    exit(EXIT_FAILURE);
  }
 
  while()  
    {
    //fgets(buf, sizeof(buf), fp);
    fscanf(fp, "%d %d %d ", &array1[0], &array1[1], &array1[2]); 
    printf("1st: %d, 2nd: %d, 3rd: %d ",array1[0], array1[1], array1[2]);
    linesum = (array1[0] + array1[1] + array1[2]);
    printf("%d \n", linesum);
    linect++;
    }
 
  fclose(fp);
   
  int a;
  scanf("%d", &a);
 
  return 0;
}