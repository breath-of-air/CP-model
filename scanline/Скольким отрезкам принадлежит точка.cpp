#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

struct Event {
	ll x, type, num; // 0 - open, 2 - close
	Event(ll x, ll type, ll num) : x(x), type(type), num(num) {  }
};

bool operator <(const Event& a, const Event& b) {
	return make_pair(a.x, a.type) < make_pair(b.x, b.type);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;
	vector<Event> arr;
	for (int i = 0; i < N; ++i) {
		ll a, b; cin >> a >> b;
		arr.push_back(Event(min(a,b), 0, i));
		arr.push_back(Event(max(a,b), 2, i));
	}
	for (int i = 0; i < M; ++i) {
		ll a; cin >> a;
		arr.push_back(Event(a, 1, i));
	}
	sort(arr.begin(), arr.end());
	ll n = arr.size();
	ll cnt = 0;
	vector<ll> ans(M);
	for (int i = 0; i < n; ++i) {
		if (arr[i].type == 0)
			cnt++;
		else if (arr[i].type == 1)
			ans[arr[i].num] = cnt;
		else
			cnt--;
	}

	for (auto& x : ans)
		cout << x << '\n';
	return 0;
}