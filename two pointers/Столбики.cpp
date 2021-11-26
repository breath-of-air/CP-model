#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

ll f(ll m, const vector<ll>& h, ll a, ll b) {
	ll ans = 0;
	int n = h.size();
	for (int i = 0; i < n; ++i) {
		if (h[i] > m) {
			ans += (h[i] - m) * b;
		}
		else {
			ans += (m - h[i]) * a;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	vector<ll> h(n);
	for (auto& x : h) {
		cin >> x;
	}
	ll a, b; cin >> a >> b;
	ll l = 0, r = 1e9;
	while (l < r - 2) {
		ll m1 = l + (r - l) / 3;
		ll m2 = m1 + (r - l) / 3;

		if (f(m1, h, a, b) > f(m2, h, a, b)) {
			l = m1;
		}
		else {
			r = m2;
		}
	}

	ll ans = f(l, h, a, b);
	ans = min(ans, f(l + 1, h, a, b));
	ans = min(ans, f(l + 2, h, a, b));
	cout << ans << '\n';
	return 0;
}