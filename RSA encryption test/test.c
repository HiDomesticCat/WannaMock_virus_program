#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int RSA(int x, int y, int z) {
    int result = 1 % z;
    x %= z;
    while (y != 0) {
        if ((y & 1) == 1) {
            result = (result * x) % z;
        }
        x = (x * x) % z;
        y >>= 1;
    }
    return result;
}

int main(void){
  //p=11, q=17, n=p*q = 187, (p-1)(q-1) = 160, e=7, d=23,

  long long int c = RSA(123, 7, 187);
  printf("%d\n", c);

  long long int m = RSA(c, 23, 187);
  printf("%d\n", m);
  
  return 0;
}
