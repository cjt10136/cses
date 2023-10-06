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

constexpr auto MXN{1 << 14};
constexpr auto MXM{1 << 15};

void solve()
{
  int n;
  cin >> n;
  array<vector<int>, MXN> adj;
  array<int, MXM> eu, ev;
  for (auto i{0}; i < 1 << n; ++i) {
    eu[i] = i >> 1;
    ev[i] = i & ((1 << (n - 1)) - 1);
    adj[eu[i]].push_back(i);
  }

  vector<int> ans;
  ans.reserve(1 << n);
  array<bool, MXM> used{};
  auto dfs{yc{[&](auto self, int u) -> void {
    while (!adj[u].empty()) {
      auto e{adj[u].back()};
      adj[u].pop_back();
      if (!used[e]) {
        used[e] = true;
        self(eu[e] ^ ev[e] ^ u);
        ans.push_back(e);
      }
    }
  }}};
  dfs(0);

  for (auto const& i : ans)
    cout << (i & 1);
  for (auto i{0}; i < n - 1; ++i)
    cout << 0;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto t{1};
  while (t--)
    solve();
}