#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(1e5);
constexpr auto mxm{100};
constexpr int mod(1e9 + 7);

int n, m, x[mxn];
long dp[mxn][mxm + 2];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for (auto i{0}; i < n; ++i)
    cin >> x[i];
  if (x[0])
    dp[0][x[0]] = 1;
  else
    fill_n(dp[0] + 1, m, 1);
  for (auto i{1}; i < n; ++i)
    if (x[i])
      dp[i][x[i]] =
          (dp[i - 1][x[i] - 1] + dp[i - 1][x[i]] + dp[i - 1][x[i] + 1]) % mod;
    else
      for (auto j{1}; j <= m; ++j)
        dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % mod;
  auto ans{0l};
  for (auto i{1}; i <= m; ++i)
    ans += dp[n - 1][i];
  cout << ans % mod;
}