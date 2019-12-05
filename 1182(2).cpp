#include <iostream>

using namespace std;

int N, S, ans;
int sArr[20];

void DFS(int depth, int sum) {
	if (sum + sArr[depth] == S) ans++;
	if (depth == N - 1) return;

	DFS(depth + 1, sum);
	DFS(depth + 1, sum+sArr[depth]);
}

int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> sArr[i];

	DFS(0, 0);

	cout << ans;
	return 0;
}