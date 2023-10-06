#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(1e6);
constexpr int mod(1e9 + 7);

int n;
long iv[mxn + 1], f1[mxn + 1], f2[mxn + 1], dp[mxn + 1];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  iv[1] = 1;
  for (auto i{2}; i <= n; ++i)
    iv[i] = mod - mod / i * iv[mod % i] % mod;
  f1[0] = f2[0] = 1;
  for (auto i{1}; i <= n; ++i) {
    f1[i] = f1[i - 1] * i % mod;
    f2[i] = f2[i - 1] * iv[i] % mod;
  }
  dp[0] = 1;
  for (auto i{2}; i <= n; ++i)
    dp[i] = (dp[i - 1] + dp[i - 2]) % mod * (i - 1) % mod;
  cout << dp[n];
}