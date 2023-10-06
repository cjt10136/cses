#include <bits/stdc++.h>

using namespace std;

constexpr int mod(1e9 + 7);

int n, m;

long pm(long b, long p)
{
  auto r{1l};
  while (p) {
    if (p % 2)
      r = r * b % mod;
    b = b * b % mod;
    p /= 2;
  }
  return r;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  auto ans{0l};
  for (auto i{0}; i < n; ++i)
    ans = (ans + pm(m, gcd(i, n))) % mod;
  cout << ans * pm(n, mod - 2) % mod;
}