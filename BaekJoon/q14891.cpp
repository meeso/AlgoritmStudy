#include <stdio.h>
#define N 0
#define S 1
#define sigye 1
#define bansigye -1

//톱니 한개를 시계 혹은 반시계 방향으로 회전해주는 함수
void circul_sigye(int a[8], int direction){
	int temp[8];
	for (int i = 0; i < 8; i++)
		temp[i] = a[i];
	if (direction == sigye){
		a[0] = temp[7];
		a[1] = temp[0];
		a[2] = temp[1];
		a[3] = temp[2];
		a[4] = temp[3];
		a[5] = temp[4];
		a[6] = temp[5];
		a[7] = temp[6];
	}
	else {
		a[0] = temp[1];
		a[1] = temp[2];
		a[2] = temp[3];
		a[3] = temp[4];
		a[4] = temp[5];
		a[5] = temp[6];
		a[6] = temp[7];
		a[7] = temp[0];
	}

}
int main(){
	int a[8], b[8], c[8], d[8];

//톱니 1~4번까지 입력 받기
	for (int i = 0; i < 8; i++){
		scanf("%1d", &a[i]);
	}
	for (int i = 0; i < 8; i++){
		scanf("%1d", &b[i]);
	}
	for (int i = 0; i < 8; i++){
		scanf("%1d", &c[i]);
	}
	for (int i = 0; i < 8; i++){
		scanf("%1d", &d[i]);
	}

	int k; //회전횟수 1<=k<=100
	scanf("%d", &k);

	int temp_a, temp_b;
  
  // 톱니가 돌아야 하는지 아닌지 여부
  int need_to_circle[5] = { 0, 0, 0, 0, 0 };
  //톱니가 어느 방향으로 돌 것인지 :: 반시계 혹은 시계방향
	int circle_direction[5] = { 0, 0, 0, 0, 0 };
	for (; k > 0; k--){
		//입력 받기 :: 회전 시킨 톱니가 몇번인지 + 방향 (1:시계 / -1:반시계)
		scanf("%d %d", &temp_a, &temp_b);

		circle_direction[temp_a] = temp_b;
    // 1,3번 톱니끼리 24번 톱니끼리 같은 방향으로 회전함 
		if (temp_a % 2 == 0){
			circle_direction[4] = temp_b;
			circle_direction[2] = temp_b;
			circle_direction[1] = -temp_b;
			circle_direction[3] = -temp_b;
		}
		else{
			circle_direction[4] = -temp_b;
			circle_direction[2] = -temp_b;
			circle_direction[1] = temp_b;
			circle_direction[3] = temp_b;
		}

//1번 톱니가 회전의 시작일때
		if (temp_a == 1){
			need_to_circle[1] = 1;
			if (a[2] != b[6]) {
				need_to_circle[2] = 1;
				if (b[2] != c[6]){
					need_to_circle[3] = 1;
					if (c[2] != d[6])
						need_to_circle[4] = 1;
				}
			}
		}
    //2번 톱니가 회전의 시작일때
		else if (temp_a == 2){
			need_to_circle[2] = 1;
			if (a[2] != b[6])need_to_circle[1] = 1;

			if (b[2] != c[6]){
				need_to_circle[3] = 1;
				if (c[2] != d[6])
					need_to_circle[4] = 1;
			}
		}
    //3번 톱니가 회전의 시작일때
		else if (temp_a == 3){
			need_to_circle[3] = 1;
			if (c[2] != d[6])
				need_to_circle[4] = 1;

			if (b[2] != c[6]){
				need_to_circle[2] = 1;
				if (a[2] != b[6])
					need_to_circle[1] = 1;
			}
		}
    //4번 톱니가 회전의 시작일때
		else if(temp_a == 4){
			need_to_circle[4] = 1;
			if (c[2] != d[6]){
				need_to_circle[3] = 1;
				if (b[2] != c[6]){
					need_to_circle[2] = 1;
					if (a[2] != b[6])
						need_to_circle[1] = 1;

				}
			}
		}
    //회전해야하는 톱니만 회전 시키기
		if (need_to_circle[1] == 1)circul_sigye(a, circle_direction[1]);
		if (need_to_circle[2] == 1)circul_sigye(b, circle_direction[2]);
		if (need_to_circle[3] == 1)circul_sigye(c, circle_direction[3]);
		if (need_to_circle[4] == 1)circul_sigye(d, circle_direction[4]);
		
    //변수 초기화 해줌 :  처음엔 모두 회전 필요 없도록
		need_to_circle[1] = 0;
		need_to_circle[2] = 0;
		need_to_circle[3] = 0;
		need_to_circle[4] = 0;

	}

	int answer = 0;
	if (a[0] == S)
		answer = answer + 1;
	if (b[0] == S)
		answer = answer + 2;
	if (c[0] == S)
		answer = answer + 4;
	if (d[0] == S)
		answer = answer + 8;

	printf("%d", answer);

	return 0;
}
