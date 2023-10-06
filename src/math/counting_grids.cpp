#include <bits/stdc++.h>

using namespace std;

constexpr int mod(1e9 + 7);

int n;

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

  cin >> n;
  if (n % 2)
    cout << (pm(2, long{n} * n) + 2 * pm(2, (long{n} * n + 3) / 4)
             + pm(2, (long{n} * n + 1) / 2))
                * pm(4, mod - 2) % mod;
  else
    cout << (pm(2, long{n} * n) + 2 * pm(2, long{n} * n / 4)
             + pm(2, long{n} * n / 2))
                * pm(4, mod - 2) % mod;
}