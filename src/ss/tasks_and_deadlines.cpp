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
    cin >> a[i][0] >> a[i][1];
  sort(a, a + n);
  auto t{0l}, ans{0l};
  for (auto i{0}; i < n; ++i) {
    t += a[i][0];
    ans += a[i][1] - t;
  }
  cout << ans;
}