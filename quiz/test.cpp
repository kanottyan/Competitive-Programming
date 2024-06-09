#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x, ans;
	string s;
	vector<pair<int, char> >a;
	cin >> n;
	cin >> s;
	ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> x;
		a.push_back({ x,s[i] });
		if (s[i] == '1')ans++;
	}
	sort(a.begin(), a.end());
	x = ans;
	for (int i = 0; i < n; i++) {
		if (a[i].second == '1')x--;
		else x++;
		// if (i < (n - 1)) {
		// 	if (a[i].first != a[i + 1].first)ans = max(ans, x);
		// }
		// else 
        ans = max(ans, x);
	}
	cout << ans << endl;
	return 0;
}
