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

constexpr int MXN{static_cast<int>(5e2)};

void solve()
{
  int n, m, q;
  cin >> n >> m >> q;
  array<array<long long, MXN>, MXN> dis;
  for (auto i{0}; i < n; ++i)
    for (auto j{0}; j < n; ++j)
      dis[i][j] = 1e18;
  for (auto i{0}; i < n; ++i)
    dis[i][i] = 0;
  for (auto i{0}; i < m; ++i) {
    int a, b;
    long long c;
    cin >> a >> b >> c, --a, --b;
    dis[a][b] = min(dis[a][b], c);
    dis[b][a] = dis[a][b];
  }

  for (auto k{0}; k < n; ++k)
    for (auto i{0}; i < n; ++i)
      for (auto j{0}; j < n; ++j)
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

  while (q--) {
    int a, b;
    cin >> a >> b, --a, --b;
    cout << (dis[a][b] == 1e18 ? -1 : dis[a][b]) << '\n';
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