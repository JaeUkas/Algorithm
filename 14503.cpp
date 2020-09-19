#include <iostream>

using namespace std;

int M, N, r, c, d; //d가 0인 경우에는 북쪽을, 1인 경우에는 동쪽을, 2인 경우에는 남쪽을, 3인 경우에는 서쪽
int map[51][51];
int ans;

void input()
{
	cin >> N >> M >> r >> c >> d;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
}

void find(int r, int c, int d, int cnt)
{
	if (map[r][c] == 0)
	{
		map[r][c] = 2;
		ans++;
	}
	if (d == 0)
	{
		if (cnt == 4)
		{
			if (map[r + 1][c] == 2) find(r + 1, c, d, 0);
			return;
		}
		if (map[r][c - 1] == 0) find(r, c - 1, 3, 0);
		else find(r, c , 3, cnt+1);
	}

	else if (d == 1)
	{
		if (cnt == 4)
		{
			if (map[r][c - 1] == 2) find(r, c - 1, d, 0);
			return;
		}
		if (map[r - 1][c] == 0) find(r - 1, c, 0, 0);
		else find(r, c , 0, cnt + 1);
	}

	else if (d == 2)
	{
		if (cnt == 4)
		{
			if (map[r - 1][c] == 2) find(r - 1, c, d, 0);
			return;
		}
		if (map[r][c + 1] == 0) find(r, c + 1, 1, 0);
		else find(r, c , 1, cnt + 1);
	}

	else if (d == 3)
	{
		if (cnt == 4)
		{
			if (map[r][c + 1] == 2) find(r, c + 1, d, 0);
			return;
		}
		if (map[r + 1][c] == 0) find(r + 1, c, 2, 0);
		else find(r, c , 2, cnt + 1);
	}
}

int main()
{
	input();
	find(r,c,d, 0);
	cout << ans;
	return 0;
}