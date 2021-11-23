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

	ll n; cin >> n;
	int arr[4]{ 10, 5,2,1 };
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		if (i == 3) {
			cnt += n;
			cout << cnt << '\n';
			return 0;
		}
		else if (n % arr[i] == 0) {
			cnt += 1;
			cout << cnt << '\n';
			return 0;
		}
		else
		{
			cnt += n / arr[i];
			n -= (n / arr[i])*arr[i];
		}
	}

	return 0;
}