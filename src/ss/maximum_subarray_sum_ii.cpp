#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(2e5);

int n, a, b;
long c[mxn + 1];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> a >> b;
  for (auto i{0}; i < n; ++i) {
    cin >> c[i + 1];
    c[i + 1] += c[i];
  }
  set<array<long, 2>> s;
  long ans(-1e18);
  for (auto i{0}; i <= n; ++i) {
    if (i >= a)
      s.insert({c[i - a], i - a});
    if (size(s))
      ans = max(c[i] - (*begin(s))[0], ans);
    if (i >= b)
      s.erase({c[i - b], i - b});
  }
  cout << ans;
}
