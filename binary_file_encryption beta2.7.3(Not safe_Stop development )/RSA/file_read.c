/*



*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
	FILE *file;
	file = fopen("病毒圖片.jpg","r");
	
	char ch[10];
	while(fgets(ch, 10, file) != NULL){
		fputs(ch, stdout);
		printf("%d\n", ch);
	}
	
	return 0;
}