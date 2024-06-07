// https://codeforces.com/problemset/problem/1206/A
// December 18,2023
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(void)
{
  int n,m,status;
  scanf("%d",&n);
  int strA[n];
  for(int i=0;i<n;i++)
     scanf("%d",&strA[i]);
     
  scanf("%d",&m);
  int strB[m];
  for(int i=0;i<m;i++)
     scanf("%d",&strB[i]);
     
  for(int i=0;i<n;i++)   
  {
    for(int j=0;j<m;j++)
    { 
      status= 1;
      int temp = strA[i] + strB[j];
      for(int k=0;k<n;k++)
      {
        if(temp == strA[k])
          {
            status = 0;
            break;
          }
      }
      for(int k=0;k<m;k++)
      {
        if(temp == strB[k])
          {
            status = 0;
            break;
          }
        
      }
      
      if(status != 0)
      {
        printf("%d %d",strA[i],strB[j]);
        return 0;
      }
    }
  }
  return 0;
}

