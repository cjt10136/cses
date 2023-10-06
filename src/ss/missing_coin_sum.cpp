#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(2e5);

int n, x[mxn];
long ans{1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (auto i{0}; i < n;++i)
    cin >> x[i];
  sort(x, x + n);
  for (auto i{0}; i < n && x[i] <= ans; ++i)
    ans += x[i];
  cout << ans;
}