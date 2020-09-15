#include <iostream>
#include <vector>

using namespace std;

struct Shark {
	int r,c,s,d,z;
};

struct Map {
	int size, index;
};

int r, c, M, ans;
Map map[101][101];
vector<Shark> sharkSet;

void move(Shark* s) {

	if (s->z != -1) {
		for (int i = 0; i < s->s; i++) {

			if (s->d == 1 && s->r == 1) s->d = 2;
			else if (s->d == 2 && s->r == r) s->d = 1;
			else if (s->d == 3 && s->c == c) s->d = 4;
			else if (s->d == 4 && s->c == 1) s->d = 3;

			if (s->d == 1) s->r--;
			else if (s->d == 2) s->r++;
			else if (s->d == 3) s->c++;
			else if (s->d == 4) s->c--;
		}
	}
}

void eat() {
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++) {
			map[i][j].size = 0;
			map[i][j].index = 0;
		}

	for (int i = 0; i < M; i++) {
		if (sharkSet[i].z != -1) {
			if (map[sharkSet[i].r][sharkSet[i].c].size != 0) {
				if (map[sharkSet[i].r][sharkSet[i].c].size > sharkSet[i].z) sharkSet[i].z = -1;
				else {
					sharkSet[map[sharkSet[i].r][sharkSet[i].c].index].z = -1;
					map[sharkSet[i].r][sharkSet[i].c].size = sharkSet[i].z;
					map[sharkSet[i].r][sharkSet[i].c].index = i;
				}
			}
			else {
				map[sharkSet[i].r][sharkSet[i].c].size = sharkSet[i].z;
				map[sharkSet[i].r][sharkSet[i].c].index = i;
			}
		}
	}
}

void hunt(int x) {

	for (int i = 1; i <= r; i++) {
		if (map[i][x].size != 0) {
			if (sharkSet[map[i][x].index].z != -1) {
				ans += map[i][x].size;
				sharkSet[map[i][x].index].z = -1;
				break;
			}
		}
	}
}

int main() {

	cin >> r >> c >> M;

	for (int i = 0; i < M; i++) {
		Shark s;
		cin >> s.r >> s.c >> s.s >> s.d >> s.z;
		if (s.d == 1 || s.d == 2) s.s %= ((r - 1) * 2);
		else if (s.d == 3 || s.d == 4) s.s %= ((c - 1) * 2);
		sharkSet.push_back(s);
	}

	eat();
	for (int i = 0; i < c; i++) {
		hunt(i + 1);
		for (int j = 0; j < M; j++) move(&sharkSet[j]);
		eat();
	}

	cout << ans;
	return 0;
}