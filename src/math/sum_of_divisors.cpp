#include <bits/stdc++.h>

using namespace std;

constexpr int mxx(1e6);
constexpr int mod(1e9 + 7);

long n;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  auto ans{0l};
  for (auto i{1l}; i <= n;) {
    auto r{n / (n / i)};
    ans = (ans + (n / i) * (__int128{r} * (r + 1) - __int128{i} * (i - 1)) / 2)
          % mod;
    i = r + 1;
  }
  cout << ans;
}
