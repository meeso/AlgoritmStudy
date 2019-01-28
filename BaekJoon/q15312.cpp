#include <stdio.h>
#include <string.h> 

int main(){
	char a[2001];
	char b[2001];
	int temp[4001];
	int length_temp = 0;
	int alphabet[100] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };
	
	scanf("%s", a);
	scanf("%s", b);

	length_temp = strlen(a)*2;
	
	//A : 65 ~ Z : 90
	for (int i = 0; i < strlen(a); i++){
		temp[i * 2] = alphabet[a[i] - 65];
		temp[i * 2 + 1] = alphabet[b[i] - 65];
	}
	while (length_temp>2)
	{
		for (int i = 0; i < length_temp; i++){
			temp[i] = (temp[i] + temp[i + 1]) % 10;
		}
		length_temp--;
	}
	
	printf("%d%d\n", temp[0], temp[1]);

	return 0;
}
