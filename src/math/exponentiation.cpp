#include <bits/stdc++.h>

using namespace std;

constexpr int mod(1e9 + 7);

int n;

long pm(long b, int p)
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
  while (n--) {
    int a, b;
    cin >> a >> b;
    cout << pm(a, b) << '\n';
  }
}