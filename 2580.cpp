#include <iostream>

using namespace std;

int map[9][9], mapX[81], mapY[81];
int zeroCnt;

bool is_possible(int x, int y, int num) {
	for (int i = 0; i < 9; i++)
		if (map[y][i] == num) return false;

	for (int i = 0; i < 9; i++)
		if (map[i][x] == num) return false;

	for (int i = y / 3 * 3; i < y / 3 * 3 + 3; i++)
		for (int j = x / 3 * 3; j < x / 3 * 3 + 3; j++)
			if (map[i][j] == num) return false;

	return true;
}

void DFS(int cnt, int idx) {

	if (cnt == 0) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cout << map[i][j] << ' ';
			cout << endl;
		}
		exit(0);
	}

	for (int i = idx; i < zeroCnt; i++) {
		if (map[mapY[i]][mapX[i]] == 0) {
			for (int k = 1; k <= 9; k++) {
				if (is_possible(mapX[i], mapY[i], k)) {
					map[mapY[i]][mapX[i]] = k;
					DFS(cnt - 1, i);
					map[mapY[i]][mapX[i]] = 0;
				}
			}
			return;
		}
	}
}

int main() {

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				mapX[zeroCnt] = j;
				mapY[zeroCnt] = i;
				zeroCnt++;
			}
		}

	DFS(zeroCnt, 0);

	return 0;
}