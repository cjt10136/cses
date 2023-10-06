#include <bits/stdc++.h>

using namespace std;

constexpr int mxx(1e6);
constexpr int mod(1e9 + 7);

int c[mxx], dp[mxx + 1];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x;
  cin >> n >> x;
  for (auto j{0}; j < n; ++j)
    cin >> c[j];
  dp[0] = 1;
  for (auto i{0}; i < n; ++i)
    for (auto j{1}; j <= x; ++j)
      if (j - c[i] >= 0)
        dp[j] = (dp[j] + dp[j - c[i]]) % mod;
  cout << dp[x];
}