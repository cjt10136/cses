#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(1e6);
constexpr int mod(1e9 + 7);

string s;
int c[26];
long iv[mxn + 1], f1[mxn + 1], f2[mxn + 1];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> s;
  for (auto&& i : s)
    ++c[i - 'a'];
  iv[1] = 1;
  for (auto i{2}; i <= size(s); ++i)
    iv[i] = mod - mod / i * iv[mod % i] % mod;
  f1[0] = f2[0] = 1;
  for (auto i{1}; i <= size(s); ++i) {
    f1[i] = f1[i - 1] * i % mod;
    f2[i] = f2[i - 1] * iv[i] % mod;
  }
  auto ans{f1[size(s)]};
  for (auto&& i : c)
    ans = ans * f2[i] % mod;
  cout << ans;
}