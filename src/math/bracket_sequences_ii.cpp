#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(1e6);
constexpr int mod(1e9 + 7);

int n, m;
long iv[mxn + 1], f1[mxn + 1], f2[mxn + 1];
string s;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> s;
  n -= size(s);
  auto m{0};
  for (auto&& i : s) {
    m += (i == '(') - (i == ')');
    if (m < 0) {
      cout << 0;
      return EXIT_SUCCESS;
    }
  }
  n -= m;
  if (n % 2 || n < 0) {
    cout << 0;
    return EXIT_SUCCESS;
  }
  iv[1] = 1;
  for (auto i{2}; i <= n + m + 1; ++i)
    iv[i] = mod - mod / i * iv[mod % i] % mod;
  f1[0] = f2[0] = 1;
  for (auto i{1}; i <= n + m + 1; ++i) {
    f1[i] = f1[i - 1] * i % mod;
    f2[i] = f2[i - 1] * iv[i] % mod;
  }
  cout << f1[n + m] * f2[n / 2] % mod * f2[n / 2 + m] % mod * (m + 1) % mod
              * iv[n / 2 + m + 1] % mod;
}