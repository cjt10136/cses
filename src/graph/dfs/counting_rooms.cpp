#include <bits/stdc++.h>

using namespace std;
using namespace std::literals;

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

constexpr auto MXN{static_cast<int>(1e3)};
constexpr array<pair<int, int>, 4> d4{{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

void solve()
{
  int n, m;
  cin >> n >> m;
  array<string, MXN> s;
  for (auto r{0}; r < n; ++r)
    cin >> s[r];

  auto e{[&](int r, int c) {
    return 0 <= r && r < n && 0 <= c && c < m && s[r][c] == '.';
  }};
  auto dfs{yc{[&](auto self, int r, int c) -> void {
    s[r][c] = '#';
    for (auto& [i, j] : d4)
      if (e(r + i, c + j))
        self(r + i, c + j);
  }}};

  auto ans{0};
  for (auto i{0}; i < n; ++i)
    for (auto j{0}; j < m; ++j)
      if (e(i, j)) {
        ++ans;
        dfs(i, j);
      }
  cout << ans << '\n';
}

int main()
{
  ios::sync_with_stdio(false);

  auto t{1};
  while (t--)
    solve();
}