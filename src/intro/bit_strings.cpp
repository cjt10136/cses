#include <bits/stdc++.h>

using namespace std;

constexpr int mod(1e9 + 7);

int n;

int main()
{
  ios::sync_with_stdio(false);

  cin >> n;
  auto ans{1};
  for (auto i{0}; i < n; ++i)
    (ans *= 2) %= mod;
  cout << ans;
}
