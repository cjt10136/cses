#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(1e6);
constexpr auto mxk{100};

int n, k, p[mxn];
bool dp[mxn + 1];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;
  for (auto i{0}; i < k; ++i)
    cin >> p[i];
  for (auto i{1}; i <= n; ++i) {
    for (auto j{0}; j < k; ++j)
      if (p[j] <= i)
        dp[i] |= !dp[i - p[j]];
    cout << (dp[i] ? 'W' : 'L');
  }
}