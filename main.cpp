#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

const int Mod = 1e9 + 7;
// dp
/*
* 	int n;
	cin >> n;
	vector<int> dp(n + 1, 1e9);
	vector<int> p(n + 1, -1);
	dp[1] = 0;
	for (int i = 2; i <= n; ++i) {
		if (dp[i - 1] + 1 < dp[i]) {
			dp[i] = dp[i - 1] + 1;
			p[i] = i - 1;
		}
		if (i % 2 == 0 && dp[i / 2] + 1 < dp[i]) {
			dp[i] = dp[i / 2] + 1;
			p[i] = i / 2;
		}
		if (i % 3 == 0 && dp[i / 3] + 1 < dp[i]) {
			dp[i] = dp[i / 3] + 1;
			p[i] = i / 3;
		}
	}
	vector<int> ans;
	int cur = n;
	while (cur != -1) {
		ans.push_back(cur);
		cur = p[cur];
	}
	reverse(ans.begin(), ans.end());
	for (int i : ans) {
		cout << i << ' ';
	}
*/
// dp - двумерный
/*
* inline int get(int i, int j, const vector<vector<int>>& dp) {
	if (i < 0 || j < 0)
		return -1e9;
	return dp[i][j];
}
* 	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int q = 0; q < m; ++q) {
			cin >> a[i][q];
		}
	}

	vector<vector<int>> dp(n, vector<int>(m));
	vector<vector<int>> p(n, vector<int>(m, -1));
	dp[0][0] = a[0][0];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; j++) {
			if (i == 0 && j == 0)
				continue;
			if (get(i - 1, j, dp) > get(i, j - 1, dp)) {
				dp[i][j] = get(i - 1, j, dp) + a[i][j];
				p[i][j] = 0;
			}
			else {
				dp[i][j] = get(i, j - 1, dp) + a[i][j];
				p[i][j] = 1;
			}
		}
	}
	int curx = n - 1, cury = m - 1;
	vector<char> ans;
	while (p[curx][cury] != -1) {
		if (p[curx][cury] == 0) {
			ans.push_back('D');
			curx -= 1;
		}
		else {
			ans.push_back('R');
			cury -= 1;
		}
	}
	reverse(ans.begin(), ans.end());
	cout << dp[n - 1][m - 1] << '\n';
	for (char c : ans) {
		cout << c << ' ';
	}
*/

//мяч на лесенке
/*
* 	ll n;
	cin >> n;
	int arr[30];
	arr[n-1] = 1;
	arr[n - 2] = 2;
	arr[n - 3] = 4;
	for (int i = n - 4; i >= 0; i--) {
		arr[i] = arr[i + 1] + arr[i + 2] + arr[i + 3];
	}
	cout << arr[0] << '\n';
*/
//платная лестница
/*
* 	int n; cin >> n;
	vector<int> a(n);
	vector<int> ans(n, 0);
	for (auto& x : a)
		cin >> x;
	int minn = 0;
	ans[0] = a[0];
	ans[1] = a[1];
	for (int i = 2; i < n; ++i) {
		ans[i] = min(ans[i - 1]+a[i], ans[i - 2] + a[i]);
	}

	cout << ans[n-1] << '\n';
*/
//калькулятор с восст ответа
/*
* 	int n; cin >> n;
	vector<int> dp(3*n + 1, 1e6); // храним кол операций числа
	vector<int> p(3*n + 1, -1); // храним пред число от нынешнего
	dp[1] = 0;

	for (int i = 1; i < n + 1; ++i) {
		if (dp[i + 1] > dp[i] + 1) {
			dp[i + 1] = dp[i] + 1;
			p[i + 1] = i;
		}
		if (dp[i * 2] > dp[i] + 1) {
			dp[i * 2] = dp[i] + 1;
			p[i * 2] = i;
		}
		if (dp[i * 3] > dp[i] + 1) {
			dp[i * 3] = dp[i] + 1;
			p[i * 3] = i;
		}
	}

	vector<int> ans;
	int cnt = n;
	while (p[cnt] != -1) {
		if (cnt - p[cnt] == 1)
			ans.push_back(1);
		else if (cnt % p[cnt] == 0)
			ans.push_back(cnt/p[cnt]);
		cnt = p[cnt];
	}
	reverse(ans.begin(), ans.end());
	for (auto& x : ans)
		cout << x;
*/
//маршрут черепашки
/*
int get(int x, int y, int n, int m, vector<vector<int>>& a) {
	if (x < 0 || y < 0 || x >= n || y >= m)
		return -1e9;
	if (a[x][y] == -1) {
		a[x][y] = max(get(x - 1, y, n, m, a) + a[x][y], (get(x, y - 1, n, m, a) + a[x][y]));
	}
	return a[x][y];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m; cin >> n >> m;

	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; ++j) {
			int x; cin >> x;
			a[i][j] = x;
		}
	}
	vector<vector<int>> p(n, vector<int>(m, -1));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; ++j) {
			if (i == 0 and j == 0)
				continue;
			if (get(i - 1, j, n, m, a) + a[i][j] > get(i, j - 1, n, m, a) + a[i][j]) {
				a[i][j] = get(i - 1, j, n, m, a) + a[i][j];
				p[i][j] = 0;
			}
			else
			{
				a[i][j] = get(i, j-1, n, m, a) + a[i][j];
				p[i][j] = 1;
			}
		}
	}

	int curx = n - 1, cury = m - 1;
	cout << a[n - 1][m - 1] << '\n';

	vector<char> way;
	while (p[curx][cury] != -1) {
		if (p[curx][cury] == 1)
		{
			way.push_back('R');
			cury -= 1;
		}
		else
		{
			way.push_back('D');
			curx -= 1;
		}
	}
	reverse(way.begin(), way.end());
	for (auto& x : way)
		cout << x << ' ';

	return 0;
}
*/
//взрывоопасность
/*int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	vector<vector<int>> dp(n, vector<int>(3));
	dp[0][0] = 1;
	dp[0][1] = 1;
	dp[0][2] = 1;
	for (int i = 1; i < n; ++i) {
		dp[i][0] = dp[i - 1][1]+dp[i-1][2];
		dp[i][1] = dp[i - 1][0] + dp[i - 1][1] + dp[i-1][2];
		dp[i][2] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
	}

	cout << dp[n - 1][0] + dp[n - 1][1] + dp[n-1][2] << '\n';

	return 0;
}
*/


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	vector<vector<int>> dp(n, vector<int>(3));
	dp[0][0] = 1;
	dp[0][1] = 1;
	dp[0][2] = 1;
	for (int i = 1; i < n; ++i) {
		dp[i][0] = dp[i - 1][1] + dp[i - 1][2];
		dp[i][1] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
		dp[i][2] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
	}

	cout << dp[n - 1][0] + dp[n - 1][1] + dp[n - 1][2] << '\n';

	return 0;
}