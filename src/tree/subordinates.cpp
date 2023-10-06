#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(2e5);

int n, s[mxn];
vector<int> adj[mxn];

void dfs(int u = 0, int p = -1)
{
  s[u] = 1;
  for (auto&& v : adj[u]) {
    if (v == p)
      continue;
    dfs(v, u);
    s[u] += s[v];
  }
}

int main()
{
  ios::sync_with_stdio(false);

  cin >> n;
  for (auto i{1}; i < n; ++i) {
    int p;
    cin >> p, --p;
    adj[p].push_back(i);
  }
  dfs();
  for (auto i{0}; i < n; ++i)
    cout << s[i] - 1 << ' ';
}