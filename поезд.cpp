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

	int N; cin >> N;
	vector<int> arr(N);
	for (auto& x : arr) {
		cin >> x;
	}
	sort(arr.begin(), arr.end());

	vector<int> result(9, 0);

	for (int i = 0; i < N; i++) {
		if (arr[i] % 4 == 0)
		{
			result[arr[i] / 4 - 1] = -1;
		}
		else
			result[arr[i] / 4] = -1;
	}
	for (int i = 0; i < 9; ++i) {
		if (result[i] == 0)
		{
			cout << ((i + 1) * 4) - 3 << ' ' << (i + 1) * 4 << '\n';
			return 0;
		}
	}
	
	return 0;
}