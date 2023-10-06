#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(2e5);

int n, m;
complex<long> p[mxn];
auto ans{numeric_limits<long>::max()};

void solve(int l = 0, int r = n)
{
  if (l + 1 == r)
    return;
  auto m{(l + r) / 2};
  auto xl{p[m - 1].real()}, rx{p[m].real()};
  solve(l, m);
  solve(m, r);
  vector<complex<long>> pl, pr;
  for (auto i{l}; i < m; ++i)
    if (norm(p[i].real() - rx) < ans)
      pl.push_back(p[i]);
  for (auto i{m}; i < r; ++i)
    if (norm(p[i].real() - xl) < ans)
      pr.push_back(p[i]);
  for (auto i{0}, j{0}; i < size(pl); ++i) {
    while (j < size(pr) && pl[i].imag() > pr[j].imag()
           && norm(pl[i].imag() - pr[j].imag()) >= ans)
      ++j;
    for (auto k{j}; k < size(pr) && norm(pl[i].imag() - pr[j].imag()) < ans;
         ++k)
      ans = min(ans, norm(pl[i] - pr[j]));
  }
  inplace_merge(p + l, p + m, p + r, [](complex<long> a, complex<long> b) {
    return a.imag() < b.imag();
  });
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (auto i{0}; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    p[i] = {x, y};
  }
  sort(p, p + n, [](complex<long> a, complex<long> b) {
    return a.real() < b.real();
  });
  solve();
  cout << ans;
}