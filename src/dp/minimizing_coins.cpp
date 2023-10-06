#include <bits/stdc++.h>

using namespace std;

constexpr auto mxn{100};
constexpr int mxx(1e6);

int n, x, c[mxn], dp[mxx + 1];

int main()
{
  ios::sync_with_stdio(false);

  cin >> n >> x;
  for (auto i{0}; i < n; ++i)
    cin >> c[i];
  fill_n(dp + 1, x, 1e9);
  for (auto i{1}; i <= x; ++i)
    for (auto j{0}; j < n; ++j)
      if (i - c[j] >= 0)
        dp[i] = min(dp[i], dp[i - c[j]] + 1);
  cout << (dp[x] == 1e9 ? -1 : dp[x]);
}
