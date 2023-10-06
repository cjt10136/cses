#include <bits/stdc++.h>
 
using namespace std;
 
constexpr int mxn(2e5);
 
int n, x, p[mxn];
 
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  cin >> n >> x;
  for (auto i{0}; i < n; ++i)
    cin >> p[i];
  sort(p, p + n);
  auto ans{n};
  for (auto i{0}, j{n - 1};;) {
    while (i < j && p[i] + p[j] > x)
      --j;
    if (i >= j)
      break;
    --ans;
    ++i, --j;
  }
  cout << ans;
}