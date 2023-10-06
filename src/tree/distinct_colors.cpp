#include <bits/stdc++.h>
 
using namespace std;
 
constexpr int mxn(2e5);
 
int n, ans[mxn];
set<int> s[mxn];
vector<int> adj[mxn];
 
void dfs(int u = 0, int p = -1)
{
  for (auto&& v : adj[u]) {
    if (v == p)
      continue;
    dfs(v, u);
    if (size(s[u]) < size(s[v]))
      swap(s[u], s[v]);
    for (auto&& i : s[v])
      s[u].insert(i);
  }
  ans[u] = size(s[u]);
}
 
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  cin >> n;
  for (auto i{0}; i < n; ++i) {
    int c;
    cin >> c;
    s[i].insert(c);
  }
  for (auto i{0}; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b, --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs();
  for (auto i{0}; i < n; ++i)
    cout << ans[i] << ' ';
}