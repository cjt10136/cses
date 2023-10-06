#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(2e5);
constexpr int st_size(bit_ceil(2 * static_cast<unsigned>(mxn)) - 1);

struct Node {
  long s, lz;
} st[st_size];

int n, q;

void app(int i, long x, int l2, int r2)
{
  st[i].s += x * (r2 - l2);
  st[i].lz += x;
}

void psh(int i, int l2, int m2, int r2)
{
  app(2 * i + 1, st[i].lz, l2, m2);
  app(2 * i + 2, st[i].lz, m2, r2);
  st[i].lz = 0;
}

void upd1(int l1, long x, int i = 0, int l2 = 0, int r2 = n)
{
  if (l2 + 1 == r2) {
    st[i].s = x;
    return;
  }
  auto m2{(l2 + r2) / 2};
  psh(i, l2, m2, r2);
  if (l1 < m2)
    upd1(l1, x, 2 * i + 1, l2, m2);
  else
    upd1(l1, x, 2 * i + 2, m2, r2);
  st[i].s = st[2 * i + 1].s + st[2 * i + 2].s;
}

void upd2(int l1, int r1, long x, int i = 0, int l2 = 0, int r2 = n)
{
  if (l1 <= l2 && r2 <= r1) {
    app(i, x, l2, r2);
    return;
  }
  auto m2{(l2 + r2) / 2};
  psh(i, l2, m2, r2);
  if (l1 < m2)
    upd2(l1, r1, x, 2 * i + 1, l2, m2);
  if (m2 < r1)
    upd2(l1, r1, x, 2 * i + 2, m2, r2);
  st[i].s = st[2 * i + 1].s + st[2 * i + 2].s;
}

long qry(int l1, int r1, int i = 0, int l2 = 0, int r2 = n)
{
  if (l1 <= l2 && r2 <= r1)
    return st[i].s;
  auto m2{(l2 + r2) >> 1};
  psh(i, l2, m2, r2);
  return (l1 < m2 ? qry(l1, r1, 2 * i + 1, l2, m2) : 0)
         + (m2 < r1 ? qry(l1, r1, 2 * i + 2, m2, r2) : 0);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> q;
  for (auto i{0}; i < n; ++i) {
    int x;
    cin >> x;
    upd1(i, x);
  }
  while (q--) {
    int qt;
    cin >> qt;
    if (qt == 1) {
      int a, b, u;
      cin >> a >> b >> u, --a;
      upd2(a, b, u);
    }
    else {
      int k;
      cin >> k, --k;
      cout << qry(k, k + 1) << '\n';
    }
  }
}