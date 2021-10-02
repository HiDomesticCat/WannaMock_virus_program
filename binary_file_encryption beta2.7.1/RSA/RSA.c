#include <stdio.h>
#include <stdlib.h>

long long int powMod(long long int x, int y, int z) {
    long long int result = 1 % z;
    x %= z;
    while (y != 0) {
        if ((y & 1) == 1) {
            result = (result * x) % z;
        }
        x = (x * x) % z;
        y >>= 1;
        printf("%lld\n", result);
    }
    return result;
}

//60409 251 36101

int main(void){
    long long int key;
    scanf("%lld", &key);
    key = powMod(key, 139, 2581);
    printf("C=%lld\n", key);
    key = powMod(key, 2659, 2581);
    printf("M=%lld\n", key);
    return 0;
}
