// https://codeforces.com/contest/1915/problem/B
// December 28,2023
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

void printChar(int) ;
int main(void) {
  int t;
  scanf("%d", &t);
  while(t--) {
    char str[3][4];
    int rec[] = {
      0,
      0,
      0
    }; // A ,B ,C
    int Qi,
    Qj;
    for(int i = 0; i < 3; i++) {
      scanf("%s", str[i]);
    }

    for(int i = 0; i < 3; i++) {
      for(int j = 0; str[i][j] != '\0'; j++) {
        if(str[i][j] == '?') {
          Qi = i;
          Qj = j;
        }
      }
    }
    char temp;
    for(int i = 0; i < 3; i++) {
      temp = str[Qi][i];
      if(temp == 'A')
      rec[0] = 1;
      else if(temp == 'B')
      rec[1] = 1;
      else if(temp == 'C')
      rec[2] = 1;
    }
    for(int i = 0; i < 3; i++) {
      temp = str[i][Qj];
      if(temp == 'A')
      rec[0] = 1;
      else if(temp == 'B')
      rec[1] = 1;
      else if(temp == 'C')
      rec[2] = 1;
    }

    for(int i = 0; i < 3; i++) {
      if(rec[i] == 0)
      printChar(i);

    }

  }
  return 0;
}
void printChar(int i) {
  if(i == 0)
  printf("A");
  else if(i == 1)
  printf("B");
  else
  printf("C");

  printf("\n");
  return;
}