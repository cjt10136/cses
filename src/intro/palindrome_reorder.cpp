#include <bits/stdc++.h>

using namespace std;

string s;

int main()
{
  ios::sync_with_stdio(false);

  cin >> s;
  int c1[26]{}, c2{0};
  for (auto&& i : s)
    ++c1[i - 'A'];
  for (auto&& i : c1)
    c2 += i % 2;
  if (c2 > 1) {
    cout << "NO SOLUTION";
    return EXIT_SUCCESS;
  }

  string ans;
  ans.reserve(size(s));
  for (auto i{0}; i < 26; ++i)
    if (c1[i] % 2 != 1)
      for (auto j{0}; j < c1[i] / 2; ++j)
        ans += 'A' + i;
  cout << ans;
  for (auto i{0}; i < 26; ++i)
    if (c1[i] % 2)
      for (auto j{0}; j < c1[i]; ++j)
        ans += 'A' + i;
  reverse(begin(ans), end(ans));
  cout << ans;
}
