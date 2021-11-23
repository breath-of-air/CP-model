#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, x;
	cin >> n >> x;
	vector<ll> arr(n);
	for (auto& x : arr) {
		cin >> x;
	}

	sort(arr.begin(), arr.end());
	int ans = -1;
	for (int i = 0; i < arr.size(); ++i) {
		int cnt = x - arr[i];
		int l = 0, r = arr.size();
		while (r - l > 1) {
			int mid = l + (r - l) / 2;
			if (i == mid)
				r = mid;
			else if (arr[mid] > cnt) {
				r = mid;
			}
			else
				l = mid;
		}
		if (ans < arr[l] + arr[i] && arr[l] + arr[i] <= x)
			ans = arr[l] +arr[i];
		
	}
	cout << ans << '\n';

	return 0;
}