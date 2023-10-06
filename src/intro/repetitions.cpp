#include <bits/stdc++.h>

using namespace std;

string s;

int main()
{
  ios::sync_with_stdio(false);

  cin >> s;
  auto ans{1}, c{0};
  auto l{'A'};
  for (auto&& i : s)
    if (i == l) {
      ++c;
      ans = max(ans, c);
    }
    else {
      l = i;
      c = 1;
    }
  cout << ans << '\n';
}