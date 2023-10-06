#include <bits/stdc++.h>

using namespace std;

constexpr auto mxn{100};

int n, a[mxn];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  auto ans{.0};
  for (auto i{0}; i < n; ++i) {
    cin >> a[i];
    for (auto j{0}; j < i; ++j) {
      auto mn{min(a[i], a[j])};
      auto c{mn * (mn - 1) / 2};
      if (a[j] > a[i])
        c += (a[j] - a[i]) * a[i];
      ans += double(c) / (a[i] * a[j]);
    }
  }
  cout << fixed << setprecision(6) << ans;
}