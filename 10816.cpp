#include <iostream>

using namespace std;

int N, M;
int Narr[20000001], Marr[20000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (num >= 0) Narr[num]++;
		else Narr[10000000 - num]++;
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> Marr[i];
	}

	for (int i = 0; i < M; i++) {
		if (Marr[i] >= 0) cout << Narr[Marr[i]] << ' ';
		else cout << Narr[10000000-Marr[i]] << ' ';
	}

	return 0;
}