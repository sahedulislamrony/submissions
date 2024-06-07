// https://codeforces.com/contest/1910/problem/A
// December 12,2023

#include <stdio.h>
#include <string.h>
int main()
{
  int t,len;
  scanf("%d",&t);
  for(int i=0;i<t;i++)
  {
    char str[60];
    scanf("%s",str);

    len = strlen(str);
    int count =0;
    int loc = -1; // location of first number 
    for(int j=0;j<len;j++)
    {
      if((str[j] >= '0' && str[j] <= '9') && count == 0)
      {
        loc = j;
        count++;
      }else if((str[j] >= 'a' && str[j] <= 'z'))
      {
        loc = -1;
        count = 0;
      }
    }
    if(loc == -1)
    {
       printf("invalid id!");
       continue;
    }
 
    for(int j=0;(j<loc);j++)
    {
      printf("%c",str[j]);
      if(str[loc] == '0')
      {
         loc++;
      }
    }
    printf("\n");
    
  }
  return 0;
}