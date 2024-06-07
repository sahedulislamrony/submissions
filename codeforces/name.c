// https://codeforces.com/contest/1820/problem/A
// December 13,2023

#include<stdio.h>
#include<string.h>
int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
    char str[110];
    scanf("%s",str);
    int count = 0;
    int len = strlen(str);
    for(int i=0;i<len;i++)
    {
      if(str[i] == '_')
      {
        if(str[i+1] != '^')
           count++;
      }
    }
    if(str[0] == '_')
      count++;
    if(len == 1 && str[0] == '^')
      count++;
      
      
      printf("%d\n",count);
  }
  return 0;
}