#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(2e5);
constexpr int bwn(bit_width(unsigned(mxn)));

int n, q, d[mxn], anc[mxn][bwn];
long ans[mxn];
vector<int> adj[mxn];

void dfs1(int u = 0, int p = -1)
{
  anc[u][0] = p;
  for (auto i{1}; i < bwn; ++i)
    anc[u][i] = anc[u][i - 1] != -1 ? anc[anc[u][i - 1]][i - 1] : -1;
  for (auto&& v : adj[u]) {
    if (v == p)
      continue;
    d[v] = d[u] + 1;
    dfs1(v, u);
  }
}

void dfs2(int u = 0, int p = -1)
{
  for (auto&& v : adj[u]) {
    if (v == p)
      continue;
    dfs2(v, u);
    ans[u] += ans[v];
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
  for (auto i{0}; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b, --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs1();
  while (q--) {
    int a, b;
    cin >> a >> b, --a, --b;
    ++ans[a];
    ++ans[b];
    auto c{lca(a, b)};
    --ans[c];
    if (c)
      --ans[anc[c][0]];
  }
  dfs2();
  for (auto i{0}; i < n; ++i)
    cout << ans[i] << ' ';
}