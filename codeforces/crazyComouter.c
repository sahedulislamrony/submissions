// https://codeforces.com/problemset/problem/716/A
// December 19,2023 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(void)
{
  long int n,c;
  scanf("%ld %ld",&n,&c);
  int str[n];
  for(int i=0;i<n;i++)
     scanf("%d",&str[i]);
  
  int count = 0;
  
  for(int i=0;i<n-1;i++)
  {
    if(abs(str[i]-str[i+1]) <= c)
      count++;
    else 
       count = 0;
  }
  
  printf("%d\n",count+1);
  
  
  return 0;
}

