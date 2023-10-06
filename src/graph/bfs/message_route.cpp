#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(1e5);

int n, m, p[mxn];
vector<int> adj[mxn];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for (auto i{0}; i < m; ++i) {
    int a, b;
    cin >> a >> b, --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  fill(p + 1, p + n, -1);
  queue<int> qu;
  qu.push(0);
  while (!qu.empty()) {
    auto u{qu.front()};
    qu.pop();
    for (auto&& v : adj[u])
      if (p[v] == -1) {
        p[v] = u;
        qu.push(v);
      }
  }
  if (~p[n - 1]) {
    vector<int> ans;
    auto u{n - 1};
    while (u) {
      ans.push_back(u);
      u = p[u];
    }
    ans.push_back(0);
    cout << size(ans) << '\n';
    for (auto i{size(ans) - 1}; ~i; --i)
      cout << ans[i] + 1 << ' ';
  }
  else
    cout << "IMPOSSIBLE";
}