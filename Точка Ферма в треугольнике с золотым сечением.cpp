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

const double gold = (sqrt(5) - 1) / 2;

double ternary_x() {
	double l = -10000, r = 10000;
	double memm1, memm2;
	bool first = true;
	bool move;
	for (int i = 0; i < 200; i++) {
		double m1 = l + (1 / (2 + gold));
		double m2 = r - (1 / (2 + gold));
		if (first) {
			memm1 = ternary_y(m1);
			memm2 = ternary_y(m2);
			first = false;
		}
		else {
			if (!move) {
				memm2 = memm1;
				memm1 = ternary_y(m1);
			}
			else
			{
				memm1 = memm2;
				memm2 = ternary_y(m2);
			}
		}
		if (memm1 > memm2) {
			l = m1;
			move = true;
		}
		else
		{
			r = m2;
			move = false;
		}
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