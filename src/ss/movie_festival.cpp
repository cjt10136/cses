#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(2e5);

int n;
array<int, 2> a[mxn];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (auto i{0}; i < n; ++i)
    cin >> a[i][1] >> a[i][0];
  sort(a, a + n);
  auto ans{0};
  for (auto i{0}, t{1}; i < n; ++i)
    if (t <= a[i][1]) {
      ++ans;
      t = a[i][0];
    }
  cout << ans;
}
