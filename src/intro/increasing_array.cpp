#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(2e5);

int n, x[mxn];

int main()
{
  ios::sync_with_stdio(true);

  cin >> n;
  auto ans{0l};
  auto mx{0};
  for (auto i{0}; i < n; ++i) {
    int x;
    cin >> x;
    mx = max(mx, x);
    ans += mx - x;
  }
  cout << ans;
}
