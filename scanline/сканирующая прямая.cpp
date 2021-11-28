#include <iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;

struct Event {
	int x, type, num; //type 0 - open, type 1 - close
	Event(){}
	Event(int x, int type, int num) : x(x), type(type), num(num){}
};

bool operator <(const Event& a, const Event& b) {
	return make_pair(a.x, a.type) < make_pair(b.x, b.type);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	vector<Event> ev;
	for (int i = 0; i < n; ++i) {
		int l, r;
		cin >> l >> r;
		ev.push_back(Event(l, 0, i));
		ev.push_back(Event(r, 1, i));
	}
	sort(ev.begin(), ev.end());
	int ans1 = -1, ans2 = -1;
	int cur = -1;
	for (auto& e : ev) {
		if (e.type == 0) {
			if (cur != -1) {
				ans1 = e.num;
				ans2 = cur;
				break;
			}
			cur = e.num;
		}
		else {
			cur = -1;
		}
	}
	cout << ans1 + 1 << ' ' << ans2 + 1 << '\n';
	return 0;
}