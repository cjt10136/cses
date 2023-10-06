#include <bits/stdc++.h>

using namespace std;

constexpr auto mxn{100};
constexpr int mxx(1e3);

int n, x[mxx];
bool dp[mxn * mxx + 1];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (auto i{0}; i < n; ++i)
    cin >> x[i];
  dp[0] = true;
  for (auto i{0}; i < n; ++i)
    for (auto j{mxn * mxx}; j; --j)
      if (j - x[i] >= 0)
        dp[j] |= dp[j - x[i]];
  vector<int> ans;
  for (auto i{1}; i <= mxn * mxx; ++i)
    if (dp[i])
      ans.push_back(i);
  cout << size(ans) << '\n';
  for (auto&& i : ans)
    cout << i << ' ';
}