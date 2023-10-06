#include <bits/stdc++.h>

using namespace std;

constexpr int mxx(1e6);

int n, c[mxx + 1];
long ans[mxx + 1];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (auto i{0}; i < n; ++i) {
    int x;
    cin >> x;
    ++c[x];
  }
  for (auto i{mxx}; i; --i) {
    auto s{c[i]};
    for (auto j{i * 2}; j < mxx; j += i) {
      s += c[j];
      ans[i] -= ans[j];
    }
    ans[i] += long{s} * (s - 1) / 2;
  }
  cout << ans[1];
}