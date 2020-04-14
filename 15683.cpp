#include <iostream>

using namespace std;

int N, M, zeroCnt, ans = 9999;
int map[9][9];
int tMap[9][9];
int cctv[8], cctvCnt;

void copyMap()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			tMap[i][j] = map[i][j];
}

void countZero()
{
	zeroCnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (tMap[i][j] == 0) zeroCnt++;
}

void spread(int i, int x, int y) // 1: µ¿ 2:¼­ 3:³² 4:ºÏ
{
	switch (i)
	{
	case 0: //µ¿
		for (int i = x + 1; i < M; i++) {
			if (tMap[y][i] == 6) break;
			if (tMap[y][i] >= 1 && tMap[y][i] < 6) continue;
			tMap[y][i] = -1;
		}
		break;
	case 1: //³²
		for (int i = y + 1; i < N; i++) {
			if (tMap[i][x] == 6) break;
			if (tMap[i][x] >= 1 && tMap[i][x] < 6) continue;
			tMap[i][x] = -1;
		}
		break;
	case 2: //¼­
		for (int i = x - 1; i >= 0; i--) {
			if (tMap[y][i] == 6) break;
			if (tMap[y][i] >= 1 && tMap[y][i] < 6) continue;
			tMap[y][i] = -1;
		}
		break;
	case 3: //ºÏ
		for (int i = y - 1; i >= 0; i--) {
			if (tMap[i][x] == 6) break;
			if (tMap[i][x] >= 1 && tMap[i][x] < 6) continue;
			tMap[i][x] = -1;
		}
	}
}

void findCCTV()
{
	int cnt = -1;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (tMap[i][j] >= 1 && tMap[i][j] < 6) {
				cnt++;
				if (tMap[i][j] == 1) spread(cctv[cnt], j, i);
				else if (tMap[i][j] == 2) {
					spread(cctv[cnt], j, i);
					spread((cctv[cnt] + 2) % 4, j, i);
				}
				else if (tMap[i][j] == 3) {
					spread((cctv[cnt] + 3) % 4, j, i);
					spread((cctv[cnt]), j, i);
				}
				else if (tMap[i][j] == 4) {
					spread((cctv[cnt] + 2) % 4, j, i);
					spread((cctv[cnt] + 3) % 4, j, i);
					spread((cctv[cnt]), j, i);
				}
				else if (tMap[i][j] == 5) {
					spread((cctv[cnt] + 3) % 4, j, i);
					spread((cctv[cnt] + 2) % 4, j, i);
					spread((cctv[cnt]), j, i);
					spread((cctv[cnt] + 1) % 4, j, i);
				}
			}
		}
}

void rotate(int cnt)
{
	if (cnt == cctvCnt)
	{
		copyMap();
		findCCTV();
		countZero();
		if (zeroCnt < ans)ans = zeroCnt;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		cctv[cnt] = i;
		rotate(cnt + 1);
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] >= 1 && map[i][j] < 6) cctvCnt++;
		}
	rotate(0);
	cout << ans;
	return 0;
}