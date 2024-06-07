// https://codeforces.com/problemset/problem/1/A
// December 2023
#include <stdio.h>
int main() 
{
  long long int n,m,a;
  scanf("%lld %lld %lld",&n,&m,&a);
  if(m>n)
  {
   long long int temp = n;
    n = m;
    m = temp;
  }
  n = n%a == 0? n/a :(n/a)+1;
  m = m%a == 0? m/a :(m/a)+1;
   
  printf("%lld\n",n*m);
  return 0;
}