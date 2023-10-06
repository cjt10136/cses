#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(2e5);

int n, x, a[mxn];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> x;
  for (auto i{0}; i < n; ++i)
    cin >> a[i];
  auto s{0l}, ans{0l};
  for (auto i{0}, j{0}; i < n; ++i) {
    s += a[i];
    while (s > x) {
      s -= a[j];
      ++j;
    }
    if (s == x)
      ++ans;
  }
  cout << ans;
}