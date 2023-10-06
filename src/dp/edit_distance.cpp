#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(5e3);

int n, m, dp[mxn + 1][mxn + 1];
string a, b;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> a >> b;
  for (auto i{0}; i <= size(a); ++i)
    dp[i][0] = i;
  for (auto i{0}; i <= size(b); ++i)
    dp[0][i] = i;
  for (auto i{1}; i <= size(a); ++i)
    for (auto j{1}; j <= size(b); ++j)
      if (a[i - 1] == b[j - 1])
        dp[i][j] = dp[i - 1][j - 1];
      else
        dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
  cout << dp[size(a)][size(b)];
}
