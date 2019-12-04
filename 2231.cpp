#include <iostream>

using namespace std;

int N, ans = 2000000;

int sum(int n) {
	int total = n;
	while (n > 0) {
		total += n % 10;
		n = n / 10;
	}
	return total;
}

int main() {
	cin >> N;

	for (int i = 1; i < 1000001; i++) {
		if (sum(i) == N)
			if (i < ans) ans = i;
	}
	ans == 2000000 ? cout << 0 : cout << ans;

	return 0;
}