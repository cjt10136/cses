#include <bits/stdc++.h>
 
using namespace std;
 
constexpr int mxn(2e5);
 
int n, q, v[mxn], dt, ds[mxn], de[mxn];
long ft[mxn + 1];
vector<int> adj[mxn];
 
void upd(int i, int x)
{
  for (++i; i <= n; i += i & -i)
    ft[i] += x;
}
 
long qry(int i)
{
  auto r{0l};
  for (; i; i -= i & -i)
    r += ft[i];
  return r;
}
 
void dfs(int u = 0, int p = -1)
{
  ds[u] = dt++;
  for (auto&& v : adj[u]) {
    if (v == p)
      continue;
    dfs(v, u);
  }
  de[u] = dt;
}
 
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  cin >> n >> q;
  for (auto i{0}; i < n; ++i)
    cin >> v[i];
  for (auto i{0}; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b, --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs();
  for (auto i{0}; i < n; ++i) {
    upd(ds[i], v[i]);
    upd(de[i], -v[i]);
  }
  while (q--) {
    int qt;
    cin >> qt;
    if (qt == 1) {
      int s, x;
      cin >> s >> x, --s;
      upd(ds[s], x - v[s]);
      upd(de[s], v[s] - x);
      v[s] = x;
    }
    else {
      int s;
      cin >> s, --s;
      cout << qry(ds[s] + 1) << '\n';
    }
  }
}