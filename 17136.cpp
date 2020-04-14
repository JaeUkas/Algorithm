#include <iostream>

using namespace std;

int map[10][10];
int paper[5];

bool countOne()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (map[i][j] == 1) return false;
	return true;
}

void isPossible(int x, int y, int size)
{
	if ( x + size < 10 || y + size < 10)
	{
		if (paper[size] != 5)
		{
			if (size == 0)
			{
				if (map[y][x] == 1) {
					map[y][x] = 0;
					paper[size]++;
				}
			}
			else {
				for (int i = y; i <= y + size; i++)
					for (int j = x; j <= x + size; j++)
					{
						if (map[i][j] == 0) return;
					}

				for (int i = y; i <= y + size; i++)
					for (int j = x; j <= x + size; j++)
					{
						map[i][j] = 0;
					}
				paper[size]++;
			}
		}
	}
}

void find()
{
	for(int k = 4; k>=0; k--)
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			{
				isPossible(j, i, k);

			}
}

int main()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			cin >> map[i][j];

	find();
	if(countOne()) cout << paper[0] + paper[1] + paper[2] + paper[3] + paper[4];
	else cout << -1;

	return 0;
}