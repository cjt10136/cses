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
    adj[b].push_back(a);
  }

  array<bool, MXN> vis{};
  auto dfs{yc{[&](auto self, int u) -> void {
    vis[u] = true;
    for (auto v : adj[u])
      if (!vis[v])
        self(v);
  }}};
  vector<int> ans;
  for (auto i{0}; i < n; ++i)
    if (!vis[i]) {
      ans.push_back(i);
      dfs(i);
    }
  cout << size(ans) - 1 << '\n';
  for (auto i{1}; i < size(ans); ++i)
    cout << ans[i] + 1 << ' ' << 1 << '\n';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto t{1};
  // cin >> t;
  while (t--)
    solve();
}