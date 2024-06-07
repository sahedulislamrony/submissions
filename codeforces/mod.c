// https://codeforces.com/problemset/problem/913/A
// December 14,2023
#include <stdio.h>
#include <math.h>
int main()
{
  long long int n,m;
  scanf("%lld",&n);
  scanf("%lld",&m);
  n = pow(2,n);
  m = m%n;
  printf("%lld\n",m) ;
 
}