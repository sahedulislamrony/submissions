// https://codeforces.com/problemset/problem/898/A
// December 17,2023
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(void)
{
  int n;
  scanf("%d",&n);
  int digit = n%10;
  if(digit)
  {
     n /= 10 ; 
    if(digit<=5)
    {
      
       printf("%d",n*10);
       return 0;
      
    } else {
      
       printf("%d",(n*10)+10);
       return 0;
    }
  }
  printf("%d",n);
  return 0;
}

