#include <iostream>

using namespace std;

char T[4][9];
int K;
int pick[4];
int r[4];
int ans;

void input()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 8; j++)
			cin >> T[i][j];
	cin >> K;
}

void init()
{
	for (int i = 0; i < 4; i++)
	{
		pick[i] = -1;
		r[i] = -1;
	}
}

void rotate(int select, int	direction)
{
	if (direction == 1)
	{
		T[select][8] = T[select][7];
		for (int i = 7; i > 0; i--)
		{
			T[select][i] = T[select][i - 1];
		}
		T[select][0] = T[select][8];
	}
	else
	{
		T[select][8] = T[select][0];
		for (int i = 0; i < 8; i++)
		{
			T[select][i] = T[select][i + 1];
		}
	}

}

void find(int select, int direction)
{
	pick[select] = select;
	r[select] = direction;
	if (T[select][6] != T[select - 1][2]  && select > 0) {
		if(pick[select - 1] == -1)
		find(select - 1, -1 * direction);
	}
	if (T[select][2] != T[select + 1][6]  && select < 3) {
		if(pick[select + 1] == -1)
		find(select + 1, -1 * direction);
	}
}

int main()
{
	input();
	for (int i = 0; i < K; i++)
	{
		init();
		int a, b;
		cin >> a >> b;
		find(a - 1, b);
		for (int j = 0; j < 4; j++) {
			if(pick[j] != -1) rotate(pick[j], r[j]);
		}
	}
	
	for (int i = 0; i < 4; i++)
	{
		if (T[i][0] == '1')
		{
			if (i == 0) ans += 1;
			else if (i == 1) ans += 2;
			else if (i == 2) ans += 4;
			else if (i == 3) ans += 8;
		}
	}
	cout << ans;
	return 0;
}