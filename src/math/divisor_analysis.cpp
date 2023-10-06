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
  auto ans1{1l}, ans2{1l}, ans3{1l}, d{1l};
  while (n--) {
    int x, k;
    cin >> x >> k;
    ans1 = (ans1 * (k + 1)) % mod;
    ans2 = ans2 * (pm(x, k + 1) - 1) % mod * pm(x - 1, mod - 2) % mod;
    ans3 = pm(ans3, k + 1) * pm(pm(x, long{k} * (k + 1) / 2), d) % mod;
    d = (d * (k + 1)) % (mod - 1);
  }
  cout << ans1 << ' ' << ans2 << ' ' << ans3;
}