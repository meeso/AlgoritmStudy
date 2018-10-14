#include<stdio.h>
int main(){
	int n, kim, lim;
	
	scanf("%d %d %d", &n, &kim, &lim);

	int round = 1;
	while(1){
		if (((kim % 2 == 1) && (lim == kim + 1))
			||	((lim % 2 == 1) && (kim == lim + 1))){
			printf("%d", round);
			break;
		}
		else {
			round++;
			kim =  (kim+1)/2;
			lim = (lim + 1) / 2;
		}
	}
	
	return 0;
}
