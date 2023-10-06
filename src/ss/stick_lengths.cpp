#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(2e5);

int n, p[mxn];
long ans;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (auto i{0}; i < n; ++i)
    cin >> p[i];
  nth_element(p, p + n / 2, p + n);
  for (auto i{0}; i < n; ++i)
    ans += abs(p[n / 2] - p[i]);
  cout << ans;
}