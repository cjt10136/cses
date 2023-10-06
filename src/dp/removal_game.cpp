#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(5e3);

int n, x[mxn + 1];
array<long, 2> dp[mxn][mxn]{};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (auto i{0}; i < n; ++i)
    cin >> x[i];
  for (auto i{n - 1}; ~i; --i)
    for (auto j{i}; j < n; ++j)
      if (i == j)
        dp[i][j] = {x[i], 0};
      else if (dp[i + 1][j][1] + x[i] > dp[i][j - 1][1] + x[j])
        dp[i][j] = {dp[i + 1][j][1] + x[i], dp[i + 1][j][0]};
      else
        dp[i][j] = {dp[i][j - 1][1] + x[j], dp[i][j - 1][0]};
  cout << dp[0][n - 1][0];
}