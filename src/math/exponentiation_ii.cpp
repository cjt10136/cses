#include <bits/stdc++.h>

using namespace std;

constexpr int mod(1e9 + 7);

int n;

long pm(long b, int p, int m)
{
  auto r{1l};
  while (p) {
    if (p % 2)
      r = r * b % m;
    b = b * b % m;
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
    int a, b, c;
    cin >> a >> b >> c;
    cout << pm(a, pm(b, c, mod - 1), mod) << '\n';
  }
}