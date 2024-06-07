// https://codeforces.com/contest/1917/problem/A
// December 25,2023

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(void)
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
    int n,neg=0,pos=0,zero=1;
    scanf("%d",&n);
   long  int str[n];
    for(int i=0;i<n;i++)
    {
      scanf("%ld",&str[i]);
      
      if(str[i] > 0)
         pos++;
      else if(str[i]<0)
         neg++;
      else 
          zero  = 0;
    }
    
    if(zero==0)
    {
      printf("%d\n",zero);
    }
    else if(neg%2 != 0) {
        printf("0\n");
    }
    else if((pos != 0)||(neg%2 == 0)) {
       printf("1\n");
       printf("%d 0\n",n);
        
    }
    
  }
  return 0;
}

