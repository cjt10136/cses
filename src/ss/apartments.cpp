#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(2e5);
int n, m, k, a[mxn], b[mxn];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> k;
  for (auto i{0}; i < n; ++i)
    cin >> a[i];
  sort(a, a + n);
  for (auto i{0}; i < m; ++i)
    cin >> b[i];
  sort(b, b + m);
  auto ans{0};
  for (auto i{0}, j{0}; i < n; ++i) {
    while (j < m && a[i] - k > b[j])
      ++j;
    if (j < m && a[i] + k >= b[j]) {
      ++ans;
      ++j;
    }
  }
  cout << ans;
}