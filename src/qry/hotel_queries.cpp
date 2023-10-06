#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(2e5);

int n, m, st[bit_ceil(static_cast<unsigned>(mxn) * 2) - 1]; 

void upd(int l1, int x, int i = 0, int l2 = 0, int r2 = n)
{
  if (l2 + 1 == r2) {
    st[i] += x;
    return;
  }
  auto m2{(l2 + r2) >> 1};
  if (l1 < m2)
    upd(l1, x, 2 * i + 1, l2, m2);
  else
    upd(l1, x, 2 * i + 2, m2, r2);
  st[i] = max(st[2 * i + 1], st[2 * i + 2]);
}

int qry(int x, int i = 0, int l2 = 0, int r2 = n)
{
  if (l2 + 1 == r2)
    return l2;
  auto m2{(l2 + r2) >> 1};
  if (st[2 * i + 1] >= x)
    return qry(x, 2 * i + 1, l2, m2);
  return qry(x, 2 * i + 2, m2, r2);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for (auto i{0}; i < n; ++i) {
    int x;
    cin >> x;
    upd(i, x);
  }
  while (m--) {
    int r;
    cin >> r;
    if (st[0] >= r) {
      auto h{qry(r)};
      cout << h + 1 << ' ';
      upd(h, -r);
    }
    else
      cout << "0 ";
  }
}
