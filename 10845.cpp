#include <iostream>
#include <string>
using namespace std;

int N[10000];
int f, r = -1;

void push(int x) {
	N[++r] = x;
}

void pop() {
	if (r == -1) cout << -1 << endl;
	else {
		cout << N[f] << endl;
		for (int i = 0; i < r; i++) {
			N[i] = N[i + 1];
		}
		r--;
	}
}

void size() {
	if (r == -1) cout << 0 << endl;
	else cout << r+1 << endl;
}

void empty() {
	if (r == -1) cout << 1 << endl;
	else cout << 0 << endl;
}

void front() {
	if (r == -1) cout << -1 << endl;
	else cout << N[f] << endl;
}

void back() {
	if (r == -1) cout << -1 << endl;
	else cout << N[r] << endl;
}

int main() {
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		if (str == "push") {
			int data;
			cin >> data;
			push(data);
		}
		else if (str == "pop") {
			pop();
		}
		else if (str == "size") {
			size();
		}
		else if (str == "empty") {
			empty();
		}
		else if (str == "front") {
			front();
		}
		else if (str == "back") {
			back();
		}
	}

	return 0;

}