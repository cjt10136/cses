#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(2e5);
constexpr int mxst(bit_ceil(2 * static_cast<unsigned>(mxn)) - 1);

int n, q;
array<int, mxst> st1, st2;

void upd(span<int, mxst> st, int l1, int x, int i = 0, int l2 = 0, int r2 = n)
{
  if (l2 + 1 == r2) {
    st[i] = x;
    return;
  }
  auto m2{(l2 + r2) / 2};
  if (l1 < m2)
    upd(st, l1, x, 2 * i + 1, l2, m2);
  else
    upd(st, l1, x, 2 * i + 2, m2, r2);
  st[i] = min(st[2 * i + 1], st[2 * i + 2]);
}

int qry(span<int, mxst> st, int l1, int r1, int i = 0, int l2 = 0, int r2 = n)
{
  if (l1 <= l2 && r2 <= r1)
    return st[i];
  auto m2{(l2 + r2) / 2};
  return min((l1 < m2 ? qry(st, l1, r1, 2 * i + 1, l2, m2) : int(1e9)),
             (m2 < r1 ? qry(st, l1, r1, 2 * i + 2, m2, r2) : int(1e9)));
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> q;
  for (auto i{0}; i < n; ++i) {
    int p;
    cin >> p;
    upd(st1, i, p - i);
    upd(st2, i, p + i);
  }
  while (q--) {
    int qt;
    cin >> qt;
    if (qt == 1) {
      int k, x;
      cin >> k >> x, --k;
      upd(st1, k, x - k);
      upd(st2, k, x + k);
    }
    else {
      int k;
      cin >> k, --k;
      cout << min(qry(st1, 0, k) + k, qry(st2, k, n) - k) << '\n';
    }
  }
}
