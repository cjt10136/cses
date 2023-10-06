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

constexpr auto MXN{static_cast<int>(5e2)};

void solve()
{
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> adj(n, vector<int>{});
  for (auto i{0}; i < k; ++i) {
    int a, b;
    cin >> a >> b, --a, --b;
    adj[a].push_back(b);
  }

  vector<int> mt(m, -1);
  array<bool, MXN> vis;
  auto dfs{yc{[&](auto self, int u) -> bool {
    vis[u] = true;
    for (auto const& v : adj[u])
      if (!~mt[v] || (!vis[mt[v]] && self(mt[v]))) {
        mt[v] = u;
        return true;
      }
    return false;
  }}};
  auto ans{0};
  for (auto i{0}; i < n; ++i) {
    fill(begin(vis), begin(vis) + n, false);
    ans += dfs(i);
  }

  cout << ans << '\n';
  for (auto i{0}; i < m; ++i)
    if (~mt[i])
      cout << mt[i] + 1 << ' ' << i + 1 << '\n';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto t{1};
  while (t--)
    solve();
}