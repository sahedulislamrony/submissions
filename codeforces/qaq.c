// https://codeforces.com/problemset/problem/894/A
// December 14,2023

#include <stdio.h>
#include <string.h>
int main()
{
  char str[110];
  scanf("%s",str); 
  int len = strlen(str);
  int count =0;
  for(int i=0; str[i] != '\0';i++)
  {
    if(str[i] == 'Q')
    {
      for(int j=i+1; str[j] != '\0';j++)
      {
        if(str[j] == 'A')
        {
          for(int k=j+1; str[k] != '\0';k++)
          {
            if(str[k] == 'Q')
               count++;
          }
        }
      }
    }
  }
 
 printf("%d\n",count);
 return 0;
}