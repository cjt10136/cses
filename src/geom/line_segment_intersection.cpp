#include <bits/stdc++.h>

using namespace std;

int t;

void solve()
{
  complex<long> p[4];
  for (auto&& i : p) {
    int x, y;
    cin >> x >> y;
    i = {x, y};
  }

  for (auto i{0}; i < 2; ++i) {
    if (auto c1{(conj(p[1] - p[0]) * (p[2] - p[0])).imag()},
        c2{(conj(p[1] - p[0]) * (p[3] - p[0])).imag()};
        c1 < 0 && c2 < 0 || c1 > 0 && c2 > 0) {
      cout << "NO\n";
      return;
    }
    swap(p[0], p[2]);
    swap(p[1], p[3]);
  }
  if (!(conj(p[1] - p[0]) * (p[3] - p[2])).imag()) {
    if ((conj(p[1] - p[0]) * (p[2] - p[0])).imag()) {
      cout << "NO\n";
      return;
    }
    for (auto i{0}; i < 2; ++i) {
      if (max(p[0].real(), p[1].real()) < min(p[2].real(), p[3].real())
          || max(p[0].imag(), p[1].imag()) < min(p[2].imag(), p[3].imag())) {
        cout << "NO\n";
        return;
      }
      swap(p[0], p[2]);
      swap(p[1], p[3]);
    }
  }
  cout << "YES\n";
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t;
  while (t--)
    solve();
}
