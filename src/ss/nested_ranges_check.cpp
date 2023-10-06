#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(2e5);

int n;
bool ans1[mxn], ans2[mxn];
array<int, 3> x[mxn];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (auto i{0}; i < n; ++i) {
    cin >> x[i][0] >> x[i][1];
    x[i][2] = i;
  }
  sort(x, x + n, [](array<int, 3> lhs, array<int, 3> rhs) {
    return lhs[0] != rhs[0] ? lhs[0] < rhs[0] : lhs[1] > rhs[1];
  });
  int mn(2e9);
  for (auto i{n - 1}; ~i; --i)
    if (mn > x[i][1])
      mn = x[i][1];
    else
      ans1[x[i][2]] = true;
  auto mx{0};
  for (auto i{0}; i < n; ++i)
    if (mx < x[i][1])
      mx = x[i][1];
    else
      ans2[x[i][2]] = true;
  for (auto i{0}; i < n; ++i)
    cout << ans1[i] << ' ';
  cout << '\n';
  for (auto i{0}; i < n; ++i)
    cout << ans2[i] << ' ';
}