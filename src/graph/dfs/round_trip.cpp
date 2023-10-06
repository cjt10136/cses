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
  array<int, MXN> par;
  auto dfs{yc{[&](auto self, int u, int pu = -1) -> void {
    par[u] = pu;
    vis[u] = true;
    for (auto v : adj[u])
      if (v == par[u])
        continue;
      else if (vis[v]) {
        vector<int> ans{v};
        while (u ^ v) {
          ans.push_back(u);
          u = par[u];
        }
        ans.push_back(v);
        cout << ans.size() << '\n';
        for (auto i : ans)
          cout << i + 1 << ' ';
        exit(EXIT_SUCCESS);
      }
      else
        self(v, u);
  }}};
  for (auto i{0}; i < n; ++i)
    if (!vis[i])
      dfs(i);
  cout << "IMPOSSIBLE\n";
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto t{1};
  while (t--)
    solve();
}