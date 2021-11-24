#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (auto& x : a) {
		cin >> x;
	}
	ll ans = 0;
	int it = 0;

	for (int i = 0; i < n; ++i) {
		while (it < n && a[it] - a[i] < k) {
			++it;
		}
		ans += (n - it);
	}
	cout << ans << '\n';
	return 0;
}