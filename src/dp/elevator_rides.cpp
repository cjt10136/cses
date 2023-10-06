#include <bits/stdc++.h>

using namespace std;

constexpr auto mxn{20};

int n, x, w[mxn];
array<int, 2> dp[1 << mxn];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> x;
  for (auto i{0}; i < n; ++i)
    cin >> w[i];
  dp[0] = {1, 0};
  for (auto i{1}; i < 1 << n; ++i) {
    dp[i] = {n + 1, 0};
    for (auto j{0}; j < n; ++j)
      if (i >> j & 1) {
        auto [a, b] = dp[i ^ 1 << j];
        if (b + w[j] > x) {
          ++a;
          b = min(b, w[j]);
        }
        else
          b += w[j];
        dp[i] = min(dp[i], {a, b});
      }
  }
  cout << dp[(1 << n) - 1][0];
}