#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(2e5);

int n;
array<int, 2> a[2 * mxn];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (auto i{0}; i < 2 * n; i += 2) {
    cin >> a[i][0] >> a[i + 1][0];
    a[i][1] = 1;
    a[i + 1][1] = -1;
  }
  sort(a, a + 2 * n);
  auto ans1{0}, ans2{0};
  for (auto i{0}; i < 2 * n; ++i) {
    ans1 += a[i][1];
    ans2 = max(ans2, ans1);
  }
  cout << ans2;
}