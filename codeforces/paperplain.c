// https://codeforces.com/problemset/problem/965/A
// December 14,2023

#include<stdio.h>
#include<math.h>
int main()
{
  int k,n,s,p;
  scanf("%d %d %d %d",&k,&n,&s,&p);
  int result= ceil(((double)ceil((double)n/s)*k)/p);
  printf("%d\n", result);
  return 0;
}