#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
  ios::sync_with_stdio(false);

  cin >> n;
  auto ans{0l};
  for (auto i{5}; i <= n; i *= 5)
    ans += n / i;
  cout << ans << '\n';
}
