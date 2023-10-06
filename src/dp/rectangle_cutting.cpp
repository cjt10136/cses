#include <bits/stdc++.h>

using namespace std;

constexpr auto mxa{500};

int a, b;
int dp[mxa + 1][mxa + 1];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> a >> b;
  for (auto i{1}; i <= a; ++i)
    for (auto j{1}; j <= b; ++j) {
      if (i != j)
        dp[i][j] = 1e9;
      for (auto k{1}; k < i; ++k)
        dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
      for (auto k{1}; k < j; ++k)
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
    }
  cout << dp[a][b];
}