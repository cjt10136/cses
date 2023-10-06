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
constexpr auto MXM{static_cast<int>(2e5)};

void solve()
{
  int n, m;
  cin >> n >> m;
  array<int, MXM> eu, ev;
  array<vector<int>, MXN> adj;
  for (auto i{0}; i < m; ++i) {
    cin >> eu[i] >> ev[i], --eu[i], --ev[i];
    adj[eu[i]].push_back(i);
    adj[ev[i]].push_back(i);
  }

  for (auto i{0}; i < n; ++i)
    if (size(adj[i]) % 2) {
      cout << "IMPOSSIBLE\n";
      return;
    }
  vector<int> ans;
  ans.reserve(m + 1);
  array<bool, MXM> used;
  fill(begin(used), begin(used) + m, false);
  auto dfs{yc{[&](auto self, int u) -> void {
    while (!adj[u].empty()) {
      auto e{adj[u].back()};
      adj[u].pop_back();
      if (!used[e]) {
        used[e] = true;
        self(eu[e] ^ ev[e] ^ u);
        ans.push_back(u);
      }
    }
  }}};
  ans.push_back(0);
  dfs(0);
  if (ans.size() != m + 1) {
    cout << "IMPOSSIBLE";
    return;
  }
  for (auto const& i : ans)
    cout << i + 1 << ' ';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto t{1};
  while (t--)
    solve();
}