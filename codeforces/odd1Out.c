// https://codeforces.com/contest/1915/problem/A
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
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int d = (a==b)?c:(b==c)?a:b;
    printf("%d\n",d);
  }
  return 0;
}
