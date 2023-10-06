#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(2e5);
constexpr int st_size(bit_ceil(2 * static_cast<unsigned>(mxn)) - 1);

int n, q, x[mxn], ans[mxn], st[st_size];
vector<array<int, 2>> ta[mxn];

void upd(int l1, int x, int i = 0, int l2 = 0, int r2 = n)
{
  if (l2 + 1 == r2) {
    st[i] = x;
    return;
  }
  auto m2{(l2 + r2) / 2};
  if (l1 < m2)
    upd(l1, x, 2 * i + 1, l2, m2);
  else
    upd(l1, x, 2 * i + 2, m2, r2);
  st[i] = st[2 * i + 1] + st[2 * i + 2];
}

int qry(int l1, int r1, int i = 0, int l2 = 0, int r2 = n)
{
  if (l1 <= l2 && r2 <= r1)
    return st[i];
  auto m2{(l2 + r2) / 2};
  return (l1 < m2 ? qry(l1, r1, 2 * i + 1, l2, m2) : 0)
         + (m2 < r1 ? qry(l1, r1, 2 * i + 2, m2, r2) : 0);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> q;
  for (auto i{0}; i < n; ++i)
    cin >> x[i];
  for (auto i{0}; i < q; ++i) {
    int a, b;
    cin >> a >> b, --a, --b;
    ta[b].push_back({a, i});
  }
  map<int, int> mp;
  for (auto i{0}; i < n; ++i) {
    upd(i, 1);
    if (mp.find(x[i]) != end(mp))
      upd(mp[x[i]], 0);
    mp[x[i]] = i;
    for (auto&& [a, j] : ta[i])
      ans[j] = qry(a, i + 1);
  }
  for (auto i{0}; i < q; ++i)
    cout << ans[i] << '\n';
}