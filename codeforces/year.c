// https://codeforces.com/problemset/problem/271/A
// December 12,2023
#include <stdio.h>
int main()
{
  int year,next;
  scanf("%d",&year);
  
  while(1)
  {
    next = ++year;
    int d1,d10,d100,d1000;
    
    d1 = year%10; year /= 10;
    d10 = year%10; year /= 10;
    d100 = year%10; year /= 10;
    d1000 = year%10;
    
    if((d1 != d10) && (d1 != d100) && (d1 != d1000) && (d10 != d100) && (d10 != d1000) && (d100 != d1000) )
    {
      printf("%d\n",next);
      return 0;
    }
    
    year = next;
    
  }
  
}