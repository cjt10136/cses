#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(1e5);

int n;
complex<long> p[mxn];

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
  auto a{0l}, b{0l};
  for (auto i{0}; i < n; ++i) {
    auto j{i != n - 1 ? i + 1 : 0};
    a += (conj(p[i]) * p[j]).imag();
    auto v{p[j] - p[i]};
    b += gcd(v.real(), v.imag());
  }
  cout << (abs(a) - b) / 2 + 1 << ' ' << b;
}