#include <stdio.h>
#include <malloc.h>
int main(){
	int n;
	int *result = (int*)malloc(sizeof(int) * 100000);
	int *answer = (int*)malloc(sizeof(int) * 200000);
	int *stack = (int *)malloc(sizeof(int) * 100000);
	bool possible = true;
	int top_stack = -1;
	int top_answer = -1;

	//read n & required array
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &result[i]);
	}
	int num = 1;
	for (int i = 0; i < n; i++){
		if (possible == false) break;
		//res[i] 를 만들수 있는가 ? 
		//==> 1. res[i] >= num 인경우 가능  : push (+)
		//==> 2. stack[top] 에 res[i] 가 있는 경우 가능 : pop (-)
		while (1){
			if (result[i] < num && (top_stack != -1 && stack[top_stack] != result[i])){
				possible = false;
				break;
			}
			else{
				//pop (-)
				if (top_stack != -1 && stack[top_stack] == result[i]){
					stack[top_stack--] = -1;
					answer[++top_answer] = 0;
					break;
				}
				//push (+)
				else if (result[i] >= num){
					stack[++top_stack] = num++;
					answer[++top_answer] = 1;
				}
			}
		}
	}
	
	//print the answer Array.
	if (possible == false)
		printf("NO");
	else {
		for (int i = 0; i < 2*n; i++){
			if (answer[i]==0)
				printf("-\n");
			else 
				printf("+\n");
		}
	}
	return 0;
}