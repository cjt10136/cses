#include <bits/stdc++.h>

using namespace std;

constexpr int mxx(1e6);
constexpr int mod(1e9 + 7);

int n, x, c[mxx], dp[mxx + 1];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> x;
  for (auto i{0}; i < n; ++i)
    cin >> c[i];
  dp[0] = 1;
  for (auto i{1}; i <= x; ++i)
    for (auto j{0}; j < n; ++j)
      if (i - c[j] >= 0)
        dp[i] = (dp[i] + dp[i - c[j]]) % mod;
  cout << dp[x];
}