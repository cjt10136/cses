#include <bits/stdc++.h>

using namespace std;

int n;
long ans1(-1e18), ans2(-1e18);

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> n;
  for (auto i{0}; i < n; ++i) {
    long x;
    cin >> x;
    ans1 = max(ans1 + x, x);
    ans2 = max(ans2, ans1);
  }
  cout << ans2;
}