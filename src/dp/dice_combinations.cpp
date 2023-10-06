#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(1e6);
constexpr int mod(1e9 + 7);

int n, dp[mxn + 1];

int main()
{
  ios::sync_with_stdio(false);

  cin >> n;
  dp[0] = 1;
  for (auto i{1}; i <= n; ++i)
    for (auto j{1}; j <= min(i, 6); ++j)
      dp[i] = (dp[i] + dp[i - j]) % mod;
  cout << dp[n];
}