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

	int N; cin >> N;
	vector<int> arr1(N);
	for (auto& x : arr1)
		cin >> x;
	int M; cin >> M;
	vector<int> arr2(M);
	for (auto& x : arr2)
		cin >> x;
	int min_n = 1e6, ind1 = 0, ind2 = 0, it = 0;
	for (int i = 0; i < N; i++) {

		while (it < M-1 && abs(arr1[i] - arr2[it]) < min_n) {
			++it;
		}

		if (abs(arr1[i] - arr2[it]) < min_n) {
			min_n = abs(arr1[i] - arr2[it]);
			ind1 = arr1[i];
			ind2 = arr2[it];
		}
	}
	cout << ind1 << ' ' << ind2 << '\n';
	return 0;
}