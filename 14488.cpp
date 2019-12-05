#include <iostream>
#include<cmath>

using namespace std;

double N, pos[50000], speed[50000];
double T;
bool state;

double c_max(double a, double b) {
	return a > b ? a : b;
}

double c_min(double a, double b) {
	return a < b ? a : b;
}

int main() {

	cin >> N >> T;
	for (int i = 0; i < N; i++) cin >> pos[i];
	for (int i = 0; i < N; i++) cin >> speed[i];

	double right = pos[0] + speed[0] * T;
	double left = pos[0] - speed[0] * T;

	right = floor(right * 10000.f);
	left =floor(left * 10000.f);


	for (int i = 1; i < N; i++) {
		double next_right = pos[i] + speed[i] * T;
		double next_left = pos[i] - speed[i] * T;
		next_right = floor(next_right * 10000);
		next_left = floor(next_left * 10000);

		if (next_right < left || right < next_left) {
			state = true;
			break;
		}
		right = c_min(right, next_right);
		left = c_max(left, next_left);
	}

	state ? cout << 0 : cout << 1;
	return 0;
}