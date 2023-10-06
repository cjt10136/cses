#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(2e5);

int n, s[mxn];
vector<int> adj[mxn];
long ans[mxn];

void dfs1(int u = 0, int p = -1, long d = 0)
{
  ans[0] += d;
  s[u] = 1;
  for (auto&& v : adj[u]) {
    if (v == p)
      continue;
    dfs1(v, u, d + 1);
    s[u] += s[v];
  }
}

void dfs2(int u = 0, int p = -1)
{
  for (auto&& v : adj[u]) {
    if (v == p)
      continue;
    ans[v] = ans[u] + n - 2 * s[v];
    dfs2(v, u);
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