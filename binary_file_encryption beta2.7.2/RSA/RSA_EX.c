#include <stdio.h>
#include <stdlib.h>

int main(void){
	//p=11, q=17, n=p*q = 187, (p-1)(q-1) = 160, e=7, d=23,
    int p, q;
	scanf("%d %d", &p, &q);
	int n = p*q;
	int r = (p-1)*(q-1);
	printf("n=%d r=%d\n", n, r);
	int e;
	scanf("%d", &e);
	int d = 100;
	while((e*d)%r != 1){
		d++;
	}
	printf("e=%d d=%d\n", e, d);
	
    return 0;
}