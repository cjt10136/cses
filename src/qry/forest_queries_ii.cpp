#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(1e3);

int n, q, ft[mxn + 1][mxn + 1];
string s[mxn];

void upd(int i1, int j1, int x)
{
  for (auto i{i1 + 1}; i <= n; i += i & -i)
    for (auto j{j1 + 1}; j <= n; j += j & -j)
      ft[i][j] += x;
}

int qry(int i1, int j1)
{
  auto r{0};
  for (auto i{i1}; i; i -= i & -i)
    for (auto j{j1}; j; j -= j & -j)
      r += ft[i][j];
  return r;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> q;
  for (auto i{0}; i < n; ++i) {
    cin >> s[i];
    for (auto j{0}; j < n; ++j)
      if (s[i][j] == '*')
        upd(i, j, 1);
  }
  for (auto i{0}; i < q; ++i) {
    int qt;
    cin >> qt;
    if (qt == 1) {
      int y, x;
      cin >> y >> x, --y, --x;
      if (s[y][x] == '*') {
        s[y][x] = '.';
        upd(y, x, -1);
      }
      else {
        s[y][x] = '*';
        upd(y, x, 1);
      }
    }
    else {
      int y1, x1, y2, x2;
      cin >> y1 >> x1 >> y2 >> x2;
      cout << qry(y2, x2) - qry(y1 - 1, x2) - qry(y2, x1 - 1)
                  + qry(y1 - 1, x1 - 1)
           << '\n';
    }
  }
}