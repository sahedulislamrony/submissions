// https://codeforces.com/contest/1915/problem/C
// December 28,2023

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
    long long  int n;
    scanf("%lld",&n);
    long long int str[n];
    long long int sum =0;
    for(long long int i=0;i<n;i++)
    {
      scanf("%lld",&str[i]);
      sum += str[i];
    }
     int  result = sqrt(sum);
     long long int res = (long long int)pow(result,2);
   
    if(res == sum)
       printf("YES\n");
    else
      printf("NO\n");
    
  }
  return 0;
}

