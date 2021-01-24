#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int MX = 105;

vector<P> g[MX];
int x[MX];
bool used[MX];

vector<int> ans;
int dfs(int v) {
  used[v] = true;
  int res = x[v];
  for (P e : g[v]) {
    if (used[e.first]) continue;
    int r = dfs(e.first);
    if (r) ans.push_back(e.second);
    res ^= r;
  }
  return res;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<P> a(n);
  rep(i,n) cin >> a[i].first >> a[i].second;
  sort(a.begin(), a.end());
  x[0] = a[0].second;
  rep(i,n-1) x[i+1] = a[i].second^a[i+1].second;
  x[n] = a[n-1].second;

  rep(i,m) {
    int l, r;
    cin >> l >> r;
    auto xxx = a.begin();
    auto ll = lower_bound(a.begin(),a.end(),P(l,0));
    l = ll -a.begin();
    auto rr = upper_bound(a.begin(),a.end(),P(r,1));
    r = rr -a.begin();
    g[l].emplace_back(r,i+1);
    g[r].emplace_back(l,i+1);
  }

  rep(i,n+1) {
    if (used[i]) continue;
    if (dfs(i)) {
      cout << -1 << endl;
      return 0;
    }
  }

  cout << ans.size() << endl;
  sort(ans.begin(), ans.end());
  rep(i,ans.size()) printf("%d ", ans[i]);
  cout << endl;
  return 0;
}
