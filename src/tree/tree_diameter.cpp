#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(2e5);

int n, ans, d[mxn];
vector<int> adj[mxn];

void dfs(int u = 0, int p = -1)
{
  for (auto&& v : adj[u]) {
    if (v == p)
      continue;
    dfs(v, u);
    ans = max(ans, d[u] + d[v] + 1);
    d[u] = max(d[u], d[v] + 1);
  }
}

int main()
{
  ios::sync_with_stdio(false);

  cin >> n;
  for (auto i{0}; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b, --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs();
  cout << ans;
}