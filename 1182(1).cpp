#include <iostream>

using namespace std;

int N, S, ans;
int sArr[1000000];
bool visited[1000000];
void DFS(int x, int idx, int depth, int n) {
	if (depth == n) {
		if (x == S) ans++;
		return;
	}

	for (int i = idx; i < N; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		DFS(x + sArr[i], i, depth+1, n);
		visited[i] = false;
	}
}

int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> sArr[i];

	for (int i = 1; i <= N; i++) {
		DFS(0, 0, 0, i);
	}

	cout << ans;
	return 0;
}