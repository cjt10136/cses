#include <bits/stdc++.h>

using namespace std;

constexpr auto mxn{2500};

int n, m;
long d[mxn];
bool vis1[mxn], vis2[mxn];
vector<int> adj1[mxn], adj2[mxn];
vector<array<int, 3>> e;

void dfs1(int u = 0)
{
  vis1[u] = true;
  for (auto&& v : adj1[u])
    if (!vis1[v])
      dfs1(v);
}

void dfs2(int u = n - 1)
{
  vis2[u] = true;
  for (auto&& v : adj2[u])
    if (!vis2[v])
      dfs2(v);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for (auto i{0}; i < m; ++i) {
    int a, b, x;
    cin >> a >> b >> x, --a, --b;
    e.push_back({a, b, x});
    adj1[a].push_back(b);
    adj2[b].push_back(a);
  }
  fill(d + 1, d + n, -1e18);
  d[0] = 0;
  for (auto i{0}; i < n - 1; ++i)
    for (auto&& [a, b, x] : e)
      d[b] = max(d[b], d[a] + x);
  dfs1();
  dfs2();
  for (auto&& [a, b, x] : e)
    if (d[b] < d[a] + x && vis1[a] && vis2[a]) {
      cout << "-1";
      return EXIT_SUCCESS;
    }
  cout << d[n - 1];
  
}