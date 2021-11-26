#include <iostream>
using namespace std;
typedef long long ll;

struct Point {
	double x, y;
	Point(){}
	Point(double x, double y): x(x), y(y){}
};
Point a, b, c;

double len(const Point& a, const Point& b) {
	return hypot(a.x - b.x, a.y - b.y);
}

double dist(double x, double y) {
	Point cur(x, y);
	return len(cur, a) + len(cur, b) + len(cur, c);
}

double ternary_y(double x) {
	double l = -10000, r = 10000;
	for (int i = 0; i < 200; ++i) {
		double m1 = l + (r - l) / 3;
		double m2 = m1 + (r - l) / 3;
		if (dist(x, m1) > dist(x, m2)) {
			l = m1;
		}
		else
			r = m2;
	}

	return dist(x, l);
}

double ternary_x() {
	double l = -10000, r = 10000;
	for (int i = 0; i < 200; i++) {
		double m1 = l + (r - l) / 3;
		double m2 = m1 + (r - l) / 3;
		if (ternary_y(m1) > ternary_y(m2)) {
			l = m1;
		}
		else
			r = m2;
	}
	return ternary_y(l);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
	cout << ternary_x() << '\n';
}