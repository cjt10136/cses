#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(1e3);
constexpr int mod(1e9 + 7);

int n, dp[mxn][mxn];
string s[mxn];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (auto i{0}; i < n; ++i)
    cin >> s[i];
  dp[0][0] = s[0][0] == '.';
  for (auto i{0}; i < n; ++i)
    for (auto j{0}; j < n; ++j) 
      if (s[i][j] == '.') {
        if (i > 0)
          dp[i][j] += dp[i - 1][j];
        if (j > 0)
          dp[i][j] += dp[i][j - 1];
        dp[i][j] %= mod;
      }
  cout << dp[n - 1][n - 1];
}