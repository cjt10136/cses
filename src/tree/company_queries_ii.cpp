#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(2e5);
constexpr int bwn(bit_width(unsigned(mxn)));

int n, q, d[mxn], anc[mxn][bwn];
vector<int> adj[mxn];

void dfs(int u = 0, int p = -1)
{
  anc[u][0] = p;
  for (auto i{1}; i < bwn; ++i)
    anc[u][i] = anc[u][i - 1] != -1 ? anc[anc[u][i - 1]][i - 1] : -1;
  for (auto&& v : adj[u]) {
    if (v == p)
      continue;
    d[v] = d[u] + 1;
    dfs(v, u);
  }
}

int lca(int u, int v)
{
  if (d[u] < d[v])
    swap(u, v);
  for (auto i{bwn - 1}; ~i; --i)
    if (d[u] - (1 << i) >= d[v])
      u = anc[u][i];
  if (u == v)
    return u;
  for (auto i{bwn - 1}; ~i; --i)
    if (anc[u][i] != anc[v][i]) {
      u = anc[u][i];
      v = anc[v][i];
    }
  return anc[u][0];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> q;
  for (auto i{1}; i < n; ++i) {
    int p;
    cin >> p, --p;
    adj[p].push_back(i);
  }
  dfs();
  while (q--) {
    int a, b;
    cin >> a >> b, --a, --b;
    cout << lca(a, b) + 1 << '\n';
  }
}