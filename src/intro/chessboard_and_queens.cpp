#include <bits/stdc++.h>

using namespace std;

string s[8];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (auto i{0}; i < 8; ++i)
    cin >> s[i];
  int p[8];
  iota(p, p + 8, 0);
  auto ans{0};
  do {
    bool ok{true};
    for (auto i{0}; i < 8; ++i)
      ok &= s[i][p[i]] == '.';
    bool b[15]{};
    for (auto i{0}; i < 8; ++i) {
      ok &= !b[i + p[i]];
      b[i + p[i]] = true;
    }
    fill(b, b + 15, false);
    for (auto i{0}; i < 8; ++i) {
      ok &= !b[i - p[i] + 7];
      b[i - p[i] + 7] = true;
    }
    ans += ok;
  } while (next_permutation(p, p + 8));
  cout << ans;
}
