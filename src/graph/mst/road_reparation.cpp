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
  vector<tuple<long long, int, int>> edge;
  edge.reserve(m);
  for (auto i{0}; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c, --a, --b;
    edge.push_back({c, a, b});
  }

  sort(begin(edge), end(edge));
  vector<int> par(n);
  iota(begin(par), end(par), 0);
  auto ans1{0};
  auto ans2{0ll};
  for (auto const& [c, a, b] : edge) {
    auto join{[&](int u, int v) {
      auto find{yc{[&](auto self, int u) -> int {
        return u != par[u] ? par[u] = self(par[u]) : u;
      }}};
      if ((u = find(u)) == (v = find(v)))
        return false;
      par[u] = v;
      return true;
    }};

    if (join(a, b)) {
      ++ans1;
      ans2 += c;
    }
  }
  ans1 < n - 1 ? cout << "IMPOSSIBLE\n" : cout << ans2 << '\n';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto t{1};
  while (t--)
    solve();
}