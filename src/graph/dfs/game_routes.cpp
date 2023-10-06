#include <bits/stdc++.h>

using namespace std;

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

constexpr auto MOD{static_cast<int>(1e9) + 7};
constexpr auto MXN{static_cast<int>(1e5)};

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
  array<int, MXN> dp;
  fill(begin(dp), begin(dp) + n - 1, 0ll);
  dp[n - 1] = 1ll;
  auto dfs{yc{[&](auto self, int u) -> void {
    vis[u] = true;
    for (auto v : adj[u]) {
      if (!vis[v])
        self(v);
      dp[u] = (dp[u] + dp[v]) % MOD;
    }
  }}};
  for (auto i{0}; i < n; ++i)
    if (!vis[i])
      dfs(i);
  cout << dp[0] << '\n';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto t{1};
  while (t--)
    solve();
}
