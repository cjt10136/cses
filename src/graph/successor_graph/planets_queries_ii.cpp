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

constexpr auto MXN{static_cast<int>(2e5)};

void solve()
{
  int n, q;
  cin >> n >> q;
  array<int, MXN> t;
  array<vector<int>, MXN> radj;
  for (auto i{0}; i < n; ++i) {
    cin >> t[i], --t[i];
    radj[t[i]].push_back(i);
  }

  array<int, MXN> rt, rp, cr, cs, d, ds, de;
  fill(begin(rt), begin(rt) + n, -1);
  fill(begin(d), begin(d) + n, 0);
  array<bool, MXN> vis;
  fill(begin(vis), begin(vis) + n, false);
  for (auto i{0}; i < n; ++i) {
    if (~rt[i])
      continue;

    auto u{i};
    while (!vis[u]) {
      vis[u] = true;
      u = t[u];
    }
    vector<int> cyc;
    cyc.reserve(n);
    while (cyc.empty() || u ^ cyc[0]) {
      rp[u] = cyc.size();
      cyc.push_back(u);
      rt[u] = u;
      cr[u] = i;
      u = t[u];
    }

    auto dt{0};
    auto dfs{yc{[&](auto self, int u) -> void {
      ds[u] = dt++;
      for (auto v : radj[u])
        if (rt[v] ^ v) {
          rt[v] = rt[u];
          cr[v] = i;
          d[v] = d[u] + 1;
          self(v);
        }
      de[u] = dt;
    }}};
    for (auto j : cyc) {
      dt = 0;
      dfs(j);
      cs[j] = cyc.size();
    }
    cyc.clear();
  }

  while (q--) {
    int a, b;
    cin >> a >> b, --a, --b;
    auto ans{-1};
    if (cr[a] == cr[b]) {
      if (rt[b] == b)
        ans = (rp[b] - rp[rt[a]] + cs[rt[a]]) % cs[rt[a]] + d[a];
      else if (rt[a] == rt[b] && ds[a] >= ds[b] && ds[a] < de[b])
        ans = d[a] - d[b];
    }
    cout << ans << '\n';
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