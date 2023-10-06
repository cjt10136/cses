#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(1e3);

int n, m;
complex<long> pg[mxn];

void solve()
{
  int x, y;
  cin >> x >> y;
  complex<long> p{x, y};
  auto ans{0};
  for (auto i{0}; i < n; ++i) {
    auto v1{pg[i] - p}, v2{pg[i != n - 1 ? i + 1 : 0] - p};
    auto dc{conj(v1) * v2};
    if (!dc.imag() && dc.real() <= 0) {
      cout << "BOUNDARY\n";
      return;
    }
    if ((v1.real() < 0 || v2.real() < 0) && (v1.real() >= 0 || v2.real() >= 0)
        && (dc.imag() < 0 && (v1 - v2).real() < 0
            || dc.imag() > 0 && (v1 - v2).real() > 0))
      ++ans;
  }
  cout << (ans % 2 ? "INSIDE\n" : "OUTSIDE\n");
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for (auto i{0}; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    pg[i] = {x, y};
  }
  while (m--)
    solve();
}