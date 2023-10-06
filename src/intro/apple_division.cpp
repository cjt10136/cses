#include <bits/stdc++.h>

using namespace std;

int n, p[20];

int main()
{
  ios::sync_with_stdio(false);

  cin >> n;
  auto s{0l};
  for (auto i{0}; i < n; ++i) {
    cin >> p[i];
    s += p[i];
  }
  auto ans{0l};
  for (auto i{0}; i < 1 << n; ++i) {
    auto cs{0l};
    for (auto j{0}; j < n; ++j)
      if (i >> j & 1)
        cs += p[j];
    if (cs <= s / 2)
      ans = max(ans, cs);
  }
  cout << s - 2 * ans;
}