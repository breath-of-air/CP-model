#include <iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;

double f(int vp, int vf, double m, double y) {
	return (hypot(0 - m, 1 - y) / vp) + (hypot(1 - m, 0 - y) / vf);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin.precision(8);
	int vp, vf; cin >> vp >> vf;
	double y; cin >> y;
	double l = 0, r = 1;
	for (int i = 0; i < 200; ++i) {
		double m1 = l + (r - l) / 3;
		double m2 = m1 + (r - l) / 3;
		if (f(vp, vf, m1, y) > f(vp, vf, m2, y)) {
			l = m1;
		}
		else
			r = m2;
	}

	cout << r << '\n';

	return 0;
}