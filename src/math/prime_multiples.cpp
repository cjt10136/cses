#include <bits/stdc++.h>

using namespace std;

constexpr long mxn(1e18);
constexpr auto mxk{20};

long n, a[mxk];
int k;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;
  for (auto i{0}; i < k; ++i)
    cin >> a[i];
  auto ans{0l};
  for (auto i{1}; i < 1 << k; ++i) {
    auto p{1l};
    for (auto j{0}; j < k; ++j) {
      if (i >> j & 1) {
        if (p >= (n - 1) / a[j] + 1) {
          p = mxn + 1;
          break;
        }
        p *= a[j];
      }
    }
    ans += n / p * (popcount(unsigned(i)) % 2 ? 1 : -1);
  }
  cout << ans;
}