#include <iostream>

using namespace std;

int N, M;
char map[51][51];
int ans = 9999;

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	for (int n = 0; n < N - 7; n++)
		for (int m = 0; m < M - 7; m++)
		{
			int cnt1 = 0;
			int cnt2 = 0;
			for (int i = n; i < 8 + n; i++)
				for (int j = m; j < 8 + m; j++)
				{
					if ((i + j) % 2 == 0)
					{
						if (map[i][j] != 'W')cnt1++;
						else cnt2++;
					}
					else
					{
						if (map[i][j] != 'B') cnt1++;
						else cnt2++;
					}
				}
			if (cnt1 >= cnt2) 
			{
				if (ans > cnt2) ans = cnt2;
			}
			else
			{
				if (ans > cnt1) ans = cnt1;
			}
		}

	cout << ans;
	return 0;
}