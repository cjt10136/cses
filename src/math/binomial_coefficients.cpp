#include <bits/stdc++.h>

using namespace std;

constexpr int mxa(1e6);
constexpr int mod(1e9 + 7);

int n;
long iv[mxa + 1], f1[mxa + 1], f2[mxa + 1];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  iv[1] = 1;
  for (auto i{2}; i <= mxa; ++i)
    iv[i] = mod - mod / i * iv[mod % i] % mod;
  f1[0] = f2[0] = 1;
  for (auto i{1}; i <= mxa; ++i) {
    f1[i] = f1[i - 1] * i % mod;
    f2[i] = f2[i - 1] * iv[i] % mod;
  }
  cin >> n;
  while (n--) {
    int a, b;
    cin >> a >> b;
    cout << f1[a] * f2[b] % mod * f2[a - b] % mod << '\n';
  }
}