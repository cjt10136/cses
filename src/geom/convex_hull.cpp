#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(2e5);

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
  sort(p, p + n, [](complex<long> a, complex<long> b) {
    return pair{a.real(), a.imag()} < pair{b.real(), b.imag()};
  });
  vector<complex<long>> ans1, ans2;
  for (auto i{0}; i < n; ++i) {
    while (size(ans1) >= 2
           && (conj(ans1[size(ans1) - 1] - ans1[size(ans1) - 2])
               * (p[i] - ans1[size(ans1) - 1]))
                      .imag()
                  > 0)
      ans1.pop_back();
    ans1.push_back(p[i]);
    while (size(ans2) >= 2
           && (conj(ans2[size(ans2) - 1] - ans2[size(ans2) - 2])
               * (p[i] - ans2[size(ans2) - 1]))
                      .imag()
                  < 0)
      ans2.pop_back();
    ans2.push_back(p[i]);
  }
  cout << size(ans1) + size(ans2) - 2 << '\n';
  for (auto i{0}; i < size(ans1); ++i)
    cout << ans1[i].real() << ' ' << ans1[i].imag() << '\n';
  for (auto i{1}; i < size(ans2) - 1; ++i)
    cout << ans2[i].real() << ' ' << ans2[i].imag() << '\n';
}