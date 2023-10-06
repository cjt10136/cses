#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(2e5);

int n, p[mxn + 1], ans{1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> n;
  for (auto i{0}; i < n; ++i) {
    int x;
    cin >> x;
    p[x] = i;
  }
  for (auto i{2}; i <= n; ++i)
    ans += p[i] < p[i - 1];
  cout << ans;
}