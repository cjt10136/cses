#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(2e5);

int n, q;
array<long, 2> st[bit_ceil(static_cast<unsigned>(mxn) * 2) - 1];

void upd(int l1, long x, int i = 0, int l2 = 0, int r2 = n)
{
  if (l2 + 1 == r2) {
    st[i] = {x, max(x, 0l)};
    return;
  }
  auto m2{(l2 + r2) / 2};
  if (l1 < m2)
    upd(l1, x, 2 * i + 1, l2, m2);
  else
    upd(l1, x, 2 * i + 2, m2, r2);
  st[i] = {st[2 * i + 1][0] + st[2 * i + 2][0],
           max(st[2 * i + 1][1], st[2 * i + 1][0] + st[2 * i + 2][1])};
}

array<long, 2> qry(int l1, int r1, int i = 0, int l2 = 0, int r2 = n)
{
  if (l1 <= l2 && r2 <= r1)
    return st[i];
  auto m2{(l2 + r2) >> 1};
  auto ql{l1 < m2 ? qry(l1, r1, 2 * i + 1, l2, m2) : array<long, 2>{}};
  auto qr{m2 < r1 ? qry(l1, r1, 2 * i + 2, m2, r2) : array<long, 2>{}};
  return {ql[0] + qr[0], max(ql[1], ql[0] + qr[1])};
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> q;
  for (auto i{0}; i < n; ++i) {
    int x;
    cin >> x;
    upd(i, x);
  }
  while (q--) {
    int qt;
    cin >> qt;
    if (qt == 1) {
      int k, u;
      cin >> k >> u, --k;
      upd(k, u);
    }
    else {
      int a, b;
      cin >> a >> b, --a;
      cout << qry(a, b)[1] << '\n';
    }
  }
}