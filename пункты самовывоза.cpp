#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

struct supermarket {
	int x, y;
};

struct house {
	int x, y;
};

double far(house a, supermarket b) {
	return hypot(a.x - b.x, a.y - b.y);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	vector<supermarket> mag;
	vector<int> ans(N);
	for (int i = 0; i < N; i++) {
		int x, y; cin >> x >> y;
		supermarket q;
		q.x = x; q.y = y;
		mag.push_back(q);
	}
	int K; cin >> K;
	vector<house> hous;
	for (int i = 0; i < K; i++) {
		int x, y; cin >> x >> y;
		house q;
		q.x = x; q.y = y;
		hous.push_back(q);
	}

	for (int i = 0; i < K; ++i) 
	{
		double far2 = 1e6;
		int id = 0;
		for (int j = 0; j < N; ++j) 
		{
			double far3 = far(hous[i], mag[j]);
			if (far3 < far2) {
				far2 = far3;
				id = j;
			}
		}
		ans[id] += 1;
	}

	for (auto& x : ans) {
		cout << x << '\n';
	}

	return 0;
}