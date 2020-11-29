#include "../seqlist.h"

int main(void)
{
    int m, a[8];
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
        scanf("%d", &a[i]);
    queueApp(a, m);
}

//8 2 1 3 9 4 11 13 15
//1 3 2 9 11 4 13 15 

//6 2 4 6 8 10 12
//2 4 6 8 10 12 

//5 1 3 7 4 5
//1 3 4 7 5 

/*cpp描述
#include<iostream>
#include<queue>
using namespace std;
int N;
queue<int>A;
queue<int>B;
void Input() {
	cin >> N;
	int M;
	for (int i = 1; i <= N; i++) {
		cin >> M;
		if (M % 2 == 0) {
			B.push(M);
		}
		else {
			A.push(M);
		}
	}
}
void Printf() {
	int flag = 0;
	while (A.empty() != 1 && B.empty() != 1) {//当他们都不为空
		if (flag == 0) {
			cout <<A.front();
			flag++;
		}
		else {
			cout << " "<<A.front();
		}
		A.pop();
		if (A.empty() != 1) {
			cout << " "<<A.front();
			A.pop();
		}
		cout << " " << B.front();
		B.pop();
	}
	while (A.empty() == 1 && B.empty() != 1) {
		if (flag == 0) {
			cout <<B.front();
			flag++;
		}
		else {
			cout << " " << B.front();
		}
		B.pop();
	}
	while (A.empty() != 1 && B.empty() == 1) {
		if (flag == 0) {
			cout <<A.front();
			flag++;
		}
		else {
			cout << " " << A.front();
		}
		A.pop();
	}
}

	int main() {
		Input();
		Printf();
	}
*/