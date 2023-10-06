#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(2e5);
constexpr int st_size(bit_ceil(2 * static_cast<unsigned>(mxn)) - 1);

struct Node {
  long s, mx, mxl, mxr;
} st[st_size]; 

int n, m;

void upd(int l1, int x, int i = 0, int l2 = 0, int r2 = n)
{
  if (l2 + 1 == r2) {
    st[i] = {x, x, x, x};
    return;
  }
  auto m2{(l2 + r2) / 2};
  if (l1 < m2)
    upd(l1, x, 2 * i + 1, l2, m2);
  else
    upd(l1, x, 2 * i + 2, m2, r2);
  st[i] = {st[2 * i + 1].s + st[2 * i + 2].s,
           max({st[2 * i + 1].mx,
                st[2 * i + 2].mx,
                st[2 * i + 1].mxr + st[2 * i + 2].mxl}),
           max(st[2 * i + 1].mxl, st[2 * i + 1].s + st[2 * i + 2].mxl),
           max(st[2 * i + 2].mxr, st[2 * i + 2].s + st[2 * i + 1].mxr)};
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
    int k, x;
    cin >> k >> x, --k;
    upd(k, x);
    cout << max(st[0].mx, 0l) << '\n';
  }
}