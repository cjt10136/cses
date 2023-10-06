#include <bits/stdc++.h>

using namespace std;
using namespace std::literals;
;

template<typename F>
struct yc {
  F f;

  template<typename... Ts>
  decltype(auto) operator()(Ts&&... args) const
  {
    return f(*this, forward<Ts>(args)...);
  }
};

template<typename F>
yc(F) -> yc<F>;

constexpr int MXN{static_cast<int>(1e5)};

void solve()
{
  int n, m;
  cin >> n >> m;
  array<vector<int>, MXN> adj;
  for (auto i{0}; i < m; ++i) {
    int a, b;
    cin >> a >> b, --a, --b;
    adj[a].push_back(b);
  }

  array<bool, MXN> vis;
  fill(begin(vis), begin(vis) + n, false);
  array<int, MXN> par, dp;
  fill(begin(dp), begin(dp) + n - 1, -1e9);
  dp[n - 1] = 1;
  auto dfs{yc{[&](auto self, int u) -> void {
    vis[u] = true;
    for (auto v : adj[u]) {
      if (!vis[v])
        self(v);
      if (dp[u] < dp[v] + 1) {
        dp[u] = dp[v] + 1;
        par[u] = v;
      }
    }
  }}};

  for (auto i{0}; i < n; ++i)
    if (!vis[i])
      dfs(i);

  if (dp[0] < 0)
    cout << "IMPOSSIBLE\n";
  else {
    vector<int> ans{0};
    auto u{0};
    while (u ^ n - 1) {
      u = par[u];
      ans.push_back(u);
    }
    cout << ans.size() << '\n';
    for (auto i : ans)
      cout << i + 1 << ' ';
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto t{1};
  while (t--)
    solve();
}