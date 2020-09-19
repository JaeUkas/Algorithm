#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int arr[10000];

bool divide(int num) {

	for (int i = 1; i < num; i++) {
		int sum = i;
		int n = i;
		while (n > 0) {
			sum += n % 10;
			n /= 10;
		}
		if (sum == num) return true;
	}
	return false;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 1;
	while (n < 10000) {
		if (!divide(n)) cout << n << '\n';
		n++;
	}
}