#include <iostream>

using namespace std;

int N, M, ans;
bool button[10];

int abs(int a, int b) {
	return a - b > 0 ? a - b : b - a;
}

void DFS(int x, int cnt) {
	int n = abs(N - x) + cnt;
	if (n < ans) ans = n;
	if (x > 500000) return;

	for (int i = 0; i < 10; i++) {
		if (!button[i]) DFS(10 * x + i, cnt+1);
	}
}

int main(){
	cin >> N >> M;
	ans = abs(N,100);

	for (int i = 0; i < M; i++) {
		int n;
		cin >> n;
		button[n] = true;
	}
	if(!button[0])
		if (ans > N + 1) ans = N + 1;
	for (int i = 1; i < 10; i++) {
		if (!button[i]) DFS(i, 1);
	}

	cout << ans;
	return 0;
}