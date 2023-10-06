#include <bits/stdc++.h>

using namespace std;

int t, a, b;

void solve()
{
  cin >> a >> b;
  cout << ((a + b) % 3 == 0 && 2 * a >= b && 2 * b >= a ? "YES\n" : "NO\n");
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t;
  while (t--)
    solve();
}
