// modified chess board . 
// https://codeforces.com/contest/1904/problem/A
// December 12,2023

#include <stdio.h>
typedef long long int lli;
typedef struct
{
  lli x;
  lli y;
} coordinate;



lli a, b; // knight
lli Xk, Yk; // king
lli Xq, Yq; // Queen

// possible all point around king for check
coordinate king[8];
coordinate queen[8];
coordinate ans[4]; // for checking overflow 

int main() {
  int t;
  scanf("%d", &t);
  for(int i = 0; i < t; i++) {
    scanf("%lld %lld", &a, &b);
    scanf("%lld %lld", &Xk, &Yk);
    scanf("%lld %lld", &Xq, &Yq);
    int points = a!=b?8:4;
    int fork =0;
   // all possible point around king
   king[0].x = Xk+a;
   king[0].y = Yk+b;
   
   king[1].x = Xk+a;
   king[1].y = Yk-b;
   
   king[2].x = Xk-a;
   king[2].y = Yk+b;
   
   king[3].x = Xk-a;
   king[3].y = Yk-b;
   
   if(points == 8)
   {
   king[4].x = Xk+b;
   king[4].y = Yk+a;
   
   king[5].x = Xk+b;
   king[5].y = Yk-a;
   
   king[6].x = Xk-b;
   king[6].y = Yk+a;
   
   king[7].x = Xk-b;
   king[7].y = Yk-a;
   
   }
   
   // all possible point around Queen
   queen[0].x = Xq+a;
   queen[0].y = Yq+b;
   
   queen[1].x = Xq+a;
   queen[1].y = Yq-b;
   
   queen[2].x = Xq-a;
   queen[2].y = Yq+b;
   
   queen[3].x = Xq-a;
   queen[3].y = Yq-b;
   if(points ==8)
   {
   queen[4].x = Xq+b;
   queen[4].y = Yq+a;
   
   queen[5].x = Xq+b;
   queen[5].y = Yq-a;
   
   queen[6].x = Xq-b;
   queen[6].y = Yq+a;
   
   queen[7].x = Xq-b;
   queen[7].y = Yq-a;
   }
   
   // find fork
   for(int j=0;j<points;j++)
   {
     for(int k=0;k<points;k++)
     {
       if((king[j].x == queen[k].x) && (king[j].y == queen[k].y) )
      {
        fork++;
      }
       
     }
   }
   
   
   
    printf("%d\n", fork);

  }
  return 0;
}