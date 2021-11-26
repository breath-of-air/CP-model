#include <iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s; cin >> s;
	int n = s.size();
	int ans = 0, ansl = -1, ansr = -1;
	int it = 0;
	vector<int> cnt(26);
	for (int i = 0; i < n; ++i) {
		while (it < n) {
			cnt[s[it] - 'a']++;
			++it;
			if (cnt[s[it - 1] - 'a'] == 2)
				break;
		}
		if (it - i - 1 > ans) {
			ans = it - i - 1;
			ansl = i;
			ansr = it - 2;
		}
		cnt[s[i] - 'a']--;
	}
	cout << ansl + 1 << ' ' << ansr + 1 << '\n';
	return 0;
}