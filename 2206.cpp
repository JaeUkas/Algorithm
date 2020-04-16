#include <iostream>
#include <queue>

using namespace std;

int N, M;
char map[1000][1000];
int visited[2][1000][1000];
int dir[4][2] = {
	{0,-1},{1,0},{0,1},{-1,0}
};

struct s
{
	int x;
	int y;
	int w;
};


int go()
{
	queue<s> q;
	
	q.push({ 0,0,0 });
	visited[0][0][0] = 1;
	

	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int w = q.front().w;
	
		q.pop();
		if (x == M - 1 && y == N - 1) return visited[w][y][x];
		for (int i = 0; i < 4; i++)
		{
			int dx = x + dir[i][0];
			int dy = y + dir[i][1];
			if (dx >= 0 && dx < M && dy >= 0 && dy < N)
			{
				if (visited[w][dy][dx]) continue;
				if (map[dy][dx] == '1') {
					if (w) continue;
					visited[1][dy][dx] = visited[w][y][x] + 1;
					q.push({dx,dy,1});		
				}
				else {
					visited[w][dy][dx] = visited[w][y][x] + 1;
					q.push({ dx,dy,w });
				}
			}
		}
	}
	return -1;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	int ans = go();
	cout << ans;
	return 0;
}