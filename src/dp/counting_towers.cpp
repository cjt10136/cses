#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(1e6);
constexpr int mod(1e9 + 7);

int t;
array<long, 2> dp[mxn];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  dp[0] = {1, 1};
  for (auto i{1}; i < mxn; ++i)
    dp[i] = {(4 * dp[i - 1][0] + dp[i - 1][1]) % mod,
             (dp[i - 1][0] + 2 * dp[i - 1][1]) % mod};
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << (dp[n - 1][0] + dp[n - 1][1]) % mod << '\n';
  }
}