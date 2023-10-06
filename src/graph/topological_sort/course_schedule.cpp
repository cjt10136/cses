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
  vector<vector<int>> adj(n, vector<int>{});
  for (auto i{0}; i < m; ++i) {
    int a, b;
    cin >> a >> b, --a, --b;
    adj[a].push_back(b);
  }

  array<bool, MXN> vis{}, act{};
  vector<int> st;
  auto dfs{yc{[&](auto self, int u) -> void {
    vis[u] = true;
    act[u] = true;
    for (auto&& v : adj[u])
      if (act[v]) {
        cout << "IMPOSSIBLE\n";
        exit(EXIT_SUCCESS);
      }
      else if (!vis[v])
        self(v);
    act[u] = false;
    st.push_back(u);
  }}};
  for (auto i{0}; i < n; ++i)
    if (!vis[i])
      dfs(i);
  for (auto i{n - 1}; ~i; --i)
    cout << st[i] + 1 << ' ';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto t{1};
  while (t--)
    solve();
}