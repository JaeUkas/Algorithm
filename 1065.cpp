#include <iostream>

using namespace std;

int N, ans;

bool is_possible(int x) {
	int n1 = x % 10;
	int n2 = x / 10 % 10;
	int cur = n1 - n2;
	while (x >= 100) {
		x = x / 10;
		int n3 = x % 10;
		int n4 = x / 10 % 10;
		int cur2 = n3-n4;
		if (cur != cur2) return false;
	}
	return true;
}

void DFS(int x) {
	if (x > N) return;
	if (is_possible(x)) ans++;
	DFS(x + 1);
}

int main() {
	cin >> N;

	DFS(1);
	cout << ans;
	return 0;
}