#include <bits/stdc++.h>

using namespace std;

int t;
long y, x;

void solve()
{
  cin >> y >> x;
  auto z{max(y, x)}, ans{z * z};
  if (z % 2)
    if (z == x)
      ans -= y - 1;
    else
      ans += x - 1 - 2 * (y - 1);
  else if (z == x)
    ans += y - 1 - 2 * (x - 1);
  else
    ans -= x - 1;
  cout << ans << '\n';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t;
  while (t--)
    solve();
}
