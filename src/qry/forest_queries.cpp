#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(1e3);

int n, q, a[mxn + 1][mxn + 1];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> q;
  for (auto i{1}; i <= n; ++i) {
    string s;
    cin >> s;
    for (auto j{1}; j <= n; ++j)
      if (s[j - 1] == '*')
        ++a[i][j];
    for (auto j{1}; j <= n; ++j)
      a[i][j] += a[i][j - 1];
  }
  for (auto i{1}; i <= n; ++i)
    for (auto j{1}; j <= n; ++j)
      a[i][j] += a[i - 1][j];

  while (q--) {
    int y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2, --y1, --x1;
    cout << a[y2][x2] - a[y1][x2] - a[y2][x1] + a[y1][x1] << '\n';
  }
}