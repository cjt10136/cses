#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(1e6);
constexpr int mod(1e9 + 7);

int n, m;
long iv[2 * mxn + 1], f1[2 * mxn + 1], f2[2 * mxn + 1];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  iv[1] = 1;
  for (auto i{2}; i <= n + m - 1; ++i)
    iv[i] = mod - mod / i * iv[mod % i] % mod;
  f1[0] = f2[0] = 1;
  for (auto i{1}; i <= n + m - 1; ++i) {
    f1[i] = f1[i - 1] * i % mod;
    f2[i] = f2[i - 1] * iv[i] % mod;
  }
  cout << f1[n + m - 1] * f2[m] % mod * f2[n - 1] % mod;
}