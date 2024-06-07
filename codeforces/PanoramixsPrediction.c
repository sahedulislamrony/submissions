// https://codeforces.com/problemset/problem/80/A
// December 23,2023
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(void)
{
  int n,m,status;
  scanf("%d%d",&n,&m);
  while(n++)
  {
      status = 1;
      for(int i=2;i<=n;i++)
      {
        if((n%i == 0) && (i!= n))
        {
          status=0;
          break;
        }
      
      }
    if(status == 1)
       break;
  }
      if(n==m)
        printf("YES\n");
       else 
         printf("NO\n");
      
  return 0;
}

