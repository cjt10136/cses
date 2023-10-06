#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(5e3);

int n, x;
array<int, 2> a[mxn];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> x;
  for (auto i{0}; i < n; ++i) {
    cin >> a[i][0];
    a[i][1] = i;
  }
  sort(a, a + n);
  for (auto i{0}; i < n; ++i) {
    auto x2{x - a[i][0]};
    for (auto j{i + 1}, k{n - 1}; j < k; ++j) {
      while (j < k && a[j][0] + a[k][0] > x2)
        --k;
      if (j < k && a[j][0] + a[k][0] == x2) {
        cout << a[i][1] + 1 << ' ' << a[j][1] + 1 << ' ' << a[k][1] + 1;
        return EXIT_SUCCESS;
      }
    }
  }
  cout << "IMPOSSIBLE";
}