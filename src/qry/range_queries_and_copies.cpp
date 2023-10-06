#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(2e5);

struct Node {
  long s;
  int lc, rc;
} st[38 * mxn];

int n, q, t[mxn], sts{1};
vector<int> v{0};

void upd(int& i, int l1, int x, int l2 = 0, int r2 = n)
{
  st[sts].lc = st[i].lc;
  st[sts].rc = st[i].rc;
  st[sts].s = st[i].s + x;
  i = sts++;
  if (l2 + 1 == r2)
    return;
  auto m2{(l2 + r2) / 2};
  if (l1 < m2)
    upd(st[i].lc, l1, x, l2, m2);
  else
    upd(st[i].rc, l1, x, m2, r2);
}

long qry(int i, int l1, int r1, int l2 = 0, int r2 = n)
{
  if (l1 <= l2 && r2 <= r1)
    return st[i].s;
  auto m2{(l2 + r2) / 2};
  return (l1 < m2 ? qry(st[i].lc, l1, r1, l2, m2) : 0)
         + (m2 < r1 ? qry(st[i].rc, l1, r1, m2, r2) : 0);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> q;
  for (auto i{0}; i < n; ++i) {
    cin >> t[i];
    upd(v[0], i, t[i]);
  }
  while (q--) {
    int qt;
    cin >> qt;
    if (qt == 1) {
      int k, a, x;
      cin >> k >> a >> x, --k, --a;
      upd(v[k], a, x - qry(v[k], a, a + 1));
    }
    else if (qt == 2) {
      int k, a, b;
      cin >> k >> a >> b, --k, --a;
      cout << qry(v[k], a, b) << '\n';
    }
    else {
      int k;
      cin >> k, --k;
      v.push_back(v[k]);
    }
  }
}