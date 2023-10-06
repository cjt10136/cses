#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(1e3);

int n;
complex<long> pg[mxn];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (auto i{0}; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    pg[i] = {x, y};
  }
  auto ans{0l};
  for (auto i{0}; i < n; ++i)
    ans += (conj(pg[i]) * pg[i != n - 1 ? i + 1 : 0]).imag();
  cout << abs(ans);
}
