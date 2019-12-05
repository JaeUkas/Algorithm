#include <iostream>

using namespace std;

int N, NArr[11], NCnt[4], minx = 1000000001, maxx = -1000000001;

void DFS(int x, int depth) {

	if (depth == N) {
		if (x < minx) minx = x;
		if (x > maxx) maxx = x;
		return;
	}

	for (int i = 0; i < 4; i++) { //1:µ¡¼À 2:»¬¼À 3:°ö¼À 4:³ª´°¼À
		if (NCnt[i] != 0) {
			NCnt[i]--;
			if(i == 0) DFS(x + NArr[depth], depth + 1);
			else if (i == 1) DFS(x - NArr[depth], depth + 1);
			else if (i == 2) DFS(x * NArr[depth], depth + 1);
			else if (i == 3) DFS(x / NArr[depth], depth + 1);
			NCnt[i]++;
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> NArr[i];
	for (int i = 0; i < 4; i++) cin >> NCnt[i];

	DFS(NArr[0], 1);

	cout << maxx << endl << minx;

	return 0;
}