#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int Narr[100000], Marr[100000];

bool search(int start, int end, int target) {
	
	if (start > end) return false;
	int mid = (start + end) / 2;
	if (Narr[mid] == target) return true;
	else if (Narr[mid] > target) return search(start, mid - 1, target);
	else return search(mid + 1, end, target);
}

int main() {
	
	cin >> N;
	for (int i = 0; i < N; i++) cin >> Narr[i];
	cin >> M;
	for (int i = 0; i < M; i++) cin >> Marr[i];

	sort(Narr, Narr + N);
	
	for (int i = 0; i < M; i++) {
		bool answer = search(0, N - 1, Marr[i]);
		if (answer) cout << 1 << '\n';
		else cout << 0 << '\n';
	}

	return 0;
}