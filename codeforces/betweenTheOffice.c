// https://codeforces.com/problemset/problem/867/A
// December 19,2023
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(void)
{
  int n;
  scanf("%d",&n);
  char str[n+1];
  scanf("%s",str);
  int countS = 0 ,countF =0;
  for(int i=0;i<n-1;i++)
  {
    if(str[i] == 'S' && str[i+1] == 'F')
       countS++;
    else  if(str[i] == 'F' && str[i+1] == 'S')
       countF++;
   
  }
  
  if(countS > countF)
     printf("YES\n");
 else    
     printf("NO\n");
  
  
  return 0;
}

