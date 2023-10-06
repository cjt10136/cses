#include <bits/stdc++.h>

using namespace std;

constexpr auto mxn{100};

int n, a, b;
double dp[mxn + 1][6 * mxn + 1];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> a >> b;
  dp[0][0] = 1;
  for (auto i{0}; i < n; ++i)
    for (auto j{i}; j <= 6 * i; ++j)
      for (auto k{1}; k <= 6; ++k)
        dp[i + 1][j + k] += dp[i][j] / 6;
  cout << fixed << setprecision(6) << accumulate(dp[n] + a, dp[n] + b + 1, .0);
}