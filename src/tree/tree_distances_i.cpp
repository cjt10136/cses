#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(2e5);

int n, d[mxn], ans[mxn];
vector<int> adj[mxn];

void dfs1(int u = 0, int p = -1)
{
  for (auto&& v : adj[u]) {
    if (v == p)
      continue;
    dfs1(v, u);
    d[u] = max(d[u], d[v] + 1);
  }
}

void dfs2(int u = 0, int p = -1, int pd = 0)
{
  ans[u] = max(d[u], pd);
  vector<array<int, 2>> w{{pd, -1}};
  for (auto&& v : adj[u]) {
    if (v == p)
      continue;
    w.push_back({d[v] + 1, v});
  }
  ranges::sort(w, greater<>{});
  for (auto&& v : adj[u]) {
    if (v == p)
      continue;
    dfs2(v, u, w[0][1] != v ? w[0][0] + 1 : w[1][0] + 1);
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (auto i{0}; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b, --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs1();
  dfs2();
  for (auto i{0}; i < n; ++i)
    cout << ans[i] << ' ';
}