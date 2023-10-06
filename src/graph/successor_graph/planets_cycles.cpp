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

constexpr auto MXN{static_cast<int>(2e5)};

void solve()
{
  int n;
  cin >> n;
  array<int, MXN> t;
  for (auto i{0}; i < n; ++i)
    cin >> t[i], --t[i];

  array<int, MXN> ans;
  fill(begin(ans), begin(ans) + n, 0);
  array<bool, MXN> vis;
  fill(begin(vis), begin(vis) + n, false);
  for (auto i{0}; i < n; ++i)
    if (!vis[i]) {
      queue<int> cyc;
      auto d{1};
      auto dfs{yc{[&](auto self, int u) -> void {
        cyc.push(u);
        vis[u] = true;
        if (!vis[t[u]]) {
          ++d;
          self(t[u]);
        }
        else {
          d += ans[t[u]];
          cyc.push(t[u]);
        }
      }}};
      dfs(i);
      while (!cyc.empty() && cyc.front() != cyc.back()) {
        ans[cyc.front()] = d--;
        cyc.pop();
      }
      while (!cyc.empty()) {
        ans[cyc.front()] = d;
        cyc.pop();
      }
    }
  for (auto i{0}; i < n; ++i)
    cout << ans[i] << ' ';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto t{1};
  while (t--)
    solve();
}