#include <bits/stdc++.h>

using namespace std;

constexpr auto mxn{2500};

int n, m, p[mxn];
long d[mxn];
vector<array<int, 3>> e;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for (auto i{0}; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c, --a, --b;
    e.push_back({a, b, c});
  }
  fill(d, d + n, 1e18);
  for (auto i{0}; i < n - 1; ++i)
    for (auto&& [a, b, c] : e)
      if (d[b] > d[a] + c) {
        d[b] = d[a] + c;
        p[b] = a;
      }
  for (auto&& [a, b, c] : e)
    if (d[b] > d[a] + c) {
      p[b] = a;
      cout << "YES\n";
      for (auto i{0}; i < n; ++i)
        a = p[a];
      vector<int> ans{a};
      a = p[a];
      while (a != ans[0]) {
        ans.push_back(a);
        a = p[a];
      }
      ans.push_back(a);
      for (auto i{size(ans) - 1}; ~i; --i)
        cout << ans[i] + 1 << ' ';
      return EXIT_SUCCESS;
    }
  cout << "NO\n";
}