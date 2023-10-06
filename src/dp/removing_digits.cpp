#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(1e6);

int n, dp[mxn + 1];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  fill_n(dp + 1, n, 1e9);
  for (auto i{1}; i <= n; ++i)
    for (auto j{i}; j; j /= 10)
      dp[i] = min(dp[i], dp[i - j % 10] + 1);
  cout << dp[n];
}