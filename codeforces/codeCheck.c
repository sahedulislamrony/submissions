// https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/N
// December 21,2023
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(void)
{
  int a,b;
  scanf("%d%d",&a,&b);
  char str[a+b+2];
  scanf("%s", str);

  if(str[a] != '-')
  {
    printf("No\n");
    return 0;
  }
  
  for(int i=0;str[i]!='\0';i++)
  {
     if(i==a)
        i++;
    if(!(str[i] >='0' && str[i] <='9' ))
    {
       printf("No\n");
       return 0;
    }
       
       
  }
    
  printf("Yes\n");
  return 0;
}

