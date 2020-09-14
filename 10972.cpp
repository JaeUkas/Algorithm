#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {

	string a, b;
	cin >> a >> b;

	if (a.length() < b.length()) {
		reverse(a.begin(), a.end());
		while (a.length() < b.length()) {
			a += '0';
		}
		reverse(a.begin(), a.end());
	}
	if (a.length() > b.length()) {
		reverse(b.begin(), b.end());
		while (a.length() > b.length()) {
			b += '0';
		}
		reverse(b.begin(), b.end());
	}

	int n = 0;
	if (a.length() == b.length()) {
		for (int i = a.length() - 1; i >= 0; i--) {
			int t = (a[i] - '0') + (b[i] - '0');
			if (t > 9) {
				if (n == 1) {
					string s = to_string(t+1);
					a[i] = s[1];
				}
				else {
					string s = to_string(t);
					a[i] = s[1];
					n = 1;
				}
				
			}
			else {
				if (n == 1) {
					t = t + 1;
					if (t > 9) a[i] = '0';
					else {
						string s = to_string(t);
						a[i] = s[0];
						n = 0;
					}
					
				}
				else {
					string s = to_string(t);
					a[i] = s[0];
				}
			}
		}
		if (n == 1) {
			cout << '1' << a;
		}
		else cout << a;
	}

	return 0;
}