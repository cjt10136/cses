#include <bits/stdc++.h>

using namespace std;

constexpr auto mxn{500};
constexpr int mod(1e9 + 7);

int n;
long dp[mxn * (mxn + 1) / 2 + 1];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  auto s{n * (n + 1) / 2};
  if (s % 2) {
    cout << 0;
    return EXIT_SUCCESS;
  }
  dp[0] = 1;
  for (auto i{1}; i < n; ++i)
    for (auto j{i * (i + 1) / 2}; j >= i; --j)
      dp[j] = (dp[j] + dp[j - i]) % mod;
  cout << dp[s / 2];
}