#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(1e3);
constexpr int mxx(1e5);

int n, x, h[mxn], s[mxn], dp[mxx + 1];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> x;
  for (auto i{0}; i < n; ++i)
    cin >> h[i];
  for (auto i{0}; i < n; ++i)
    cin >> s[i];
  for (auto i{0}; i < n; ++i)
    for (auto j{x}; j >= h[i]; --j)
      dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
  cout << dp[x];
}