#include <bits/stdc++.h>

using namespace std;

constexpr auto mxn{20};
constexpr int mod(1e9 + 7);

int n, m, dp[2][1 << mxn];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  dp[0][0] = 1;
  for (auto i{0}; i < m; ++i)
    for (auto j{0}; j < n; ++j) {
      for (auto k{0}; k < 1 << n; ++k) {
        dp[1][k] = dp[0][k ^ 1 << j];
        if (j && ~k >> j & ~k >> j - 1 & 1) {
          dp[1][k] += dp[0][k ^ 1 << j - 1];
          if (dp[1][k] >= mod)
            dp[1][k] -= mod;
        }
      }
      copy(dp[1], dp[1] + (1 << n), dp[0]);
    }
  cout << dp[0][0];
}