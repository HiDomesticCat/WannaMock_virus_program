#include <stdio.h>
#include <stdlib.h>

//#define max 1000

//p=11, q=17, n=p*q = 187, (p-1)(q-1) = 160, e=7, d=23,
// 425,927,596,977,747 (15)

typedef struct node{
	int data;
	struct node *next;
}arr;

int division(arr *DATA2, int *c, int legth_a, int legth_c){
	int ans1[legth_a];
	int quo[legth_a];
	arr *ptr_DATA2 = DATA2;
	for(int i=0; i < legth_a; i++){
		ans1[legth_a-i-1] = ptr_DATA2->data;
		quo[i] = 0;
		ptr_DATA2 = ptr_DATA2->next;
	}
	free(ptr_DATA2);
	
	for(int k=0; k < (legth_a-legth_c+1); k++){
		while(ans1[k] >= 0){
			for(int j=0; j < legth_c; j++){
				ans1[k+j] -= c[j];
				if((ans1[k+j] < 0) && (j > 0)){
					ans1[k+j-1]--;
					ans1[k+j] += 10;
				}
			}
			quo[k]++;
		}
		for(int j=0; j < legth_c; j++){
			ans1[k+j] += c[j];
		}
		quo[k]--;
		ans1[k+1] += ans1[k]*10;
		ans1[k] = 0;
	}
	int ans2 = 0;
	for(int i=0; i < legth_a; i++){
		ans2 += ans1[i];
		if(i+1 == legth_a){
			break;
		}
		ans2 *= 10;
	}
	//printf("%d\n", ans2);
	return ans2;
}

arr multiplication(arr *a, arr *b, int legth_a, int legth_b){
	arr ans;
	arr *ptr_ans;
	arr *ptr_a;
	arr *ptr_b;
	ptr_a = a;
	ptr_b = b;
	ptr_ans = &ans;
	ptr_ans->data = 0;
	ptr_ans->next = NULL;
	for(int i=0; i < legth_a; i++){
		ptr_b = b;
		for(int j=0; j < legth_b; j++){
			int n = 0;
			ptr_ans = &ans;
			while(n != i+j){
				n++;
				if(ptr_ans->next == NULL){
					ptr_ans->next = (arr*)malloc(sizeof(arr));
					ptr_ans = ptr_ans->next;
					ptr_ans->data = 0;
					ptr_ans->next = NULL;
				}
				else{
					ptr_ans = ptr_ans->next;
				}
			}
			//printf("n=%d i=%d j=%d\n", i+j, i, j);
			ptr_ans->data += ptr_a->data*ptr_b->data;
			//printf("n:%d ptr_a*ptr_b:%d\n", i+j, ptr_a->data*ptr_b->data);
			//printf("i=%d j=%d %d %d\n", i, j, ptr_a->data, ptr_b->data);
			ptr_b = ptr_b->next;
		}
		ptr_a = ptr_a->next;
	}
	arr *ptr_ans2 = (arr*)malloc(sizeof(arr));
	ptr_ans = &ans;
	while(1){
		if(ptr_ans->next == NULL && ptr_ans->data >= 10){
			ptr_ans->next = (arr*)malloc(sizeof(arr));
			ptr_ans2 = ptr_ans->next;
			ptr_ans2->data = 0;
			ptr_ans2->next = NULL;
			
		}
		else if(ptr_ans->next == NULL){
			break;
		}
		else if(ptr_ans->data >= 10){
			ptr_ans2 = ptr_ans->next;
			ptr_ans2->data += ptr_ans->data/10;
			ptr_ans->data = ptr_ans->data%10;
		}
		else{
			ptr_ans = ptr_ans->next;
		}
		
	}
	
	free(ptr_ans);
	free(ptr_a);
	free(ptr_b);
	a = &ans;
	return ans;
}

int main(void){
	int DATA = 68;
	
	int legth_a = 0, legth_b = 0;
	arr *ptr_a = (arr*)malloc(sizeof(arr));
	arr *ptr_b = (arr*)malloc(sizeof(arr));
	arr *a;
	arr *b;
	a = ptr_a;
	b = ptr_b;
	while(DATA != 0){
		ptr_a->data = DATA%10;
		ptr_b->data = DATA%10;
		DATA /= 10;
		ptr_a->next = (arr*)malloc(sizeof(arr));
		ptr_a = ptr_a->next;
		ptr_b->next = (arr*)malloc(sizeof(arr));
		ptr_b = ptr_b->next;
		legth_a++;
		legth_b++;
	}
	/*ptr_a = a;
	ptr_b = b;
	for(int i=0; i < 3; i++){
		printf("%d %d\n", ptr_a->data, ptr_b->data);
		ptr_a = ptr_a->next;
		ptr_b = ptr_b->next;
	}*/
	free(ptr_a);
	free(ptr_b);
	
	arr ans;
	arr *ptr_ans;
	for(int i=0 ; i < 250; i++){
		ans = multiplication(a, b, legth_a, legth_b);
		int max = 0;
		ptr_ans = &ans;
		while(1){
			if(ptr_ans->next == NULL){
				break;
			}
			ptr_ans = ptr_ans->next;
			max++;
		}
		a = &ans;
		legth_a = max+1;
		//printf("%d", legth_a);
	}
	
	int DATA2 = 60409;
	int data2_len = 0;
	int DATA2_copy = DATA2;
	while(DATA2_copy != 0){
		data2_len++;
		DATA2_copy /= 10;
	}
	DATA2_copy = DATA2;
	int c[data2_len];
	for(int i=0; i < data2_len; i++){
		c[data2_len-i-1] = DATA2%10;
		DATA2 /= 10;
	}
	
	//int legth_c = 0;
	//arr *ptr_c = (arr*)malloc(sizeof(arr));
	//arr *c;
	//c = ptr_c;
	/*while(DATA2 != 0){
		ptr_c->data = DATA2%10;
		DATA2 /= 10;
		ptr_c->next = (arr*)malloc(sizeof(arr));
		ptr_c = ptr_c->next;
		legth_c++;
	}*/
	
	ptr_ans = &ans;
	int push = division(ptr_ans, &c[0], legth_a, data2_len);
	while(push < 0){
		push = DATA2_copy+push;
	}
	printf("%d\n", push);
	/*for(int i=0; i < 5; i++){
		printf("%d\n", ptr_ans->data);
		ptr_ans = ptr_ans->next;
	}*/
	/*while(1){
		printf("%d", ptr_ans->data);
		if(ptr_ans->next == NULL){
			break;
		}
		ptr_ans = ptr_ans->next;
	}
	printf("\n");*/
	
	/*int *b = (int*)malloc(sizeof(int));
	int *c = (int*)malloc(sizeof(int));
	*c = a;
	*b = 0;
	while(*c != 0){
		*b += 1;
		*c /= 10;
	}
	free(c);
	
	int *d = (int*)calloc(*b, sizeof(int));
	int *e = (int*)calloc(*b, sizeof(int));
	for(int i=0; i < *b; i++){
		d[i] = a%10;
		e[i] = a%10;
		a /= 10;
	}*/
	
	
	
	
	
	return 0;
}