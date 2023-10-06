#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(2e5);

int n, t, k[mxn];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> t;
  for (auto i{0}; i < n; ++i)
    cin >> k[i];
  long lb{0}, rb(1e18);
  while (lb < rb) {
    auto mb{(lb + rb) / 2}, s{0l};
    for (auto i{0}; i < n; ++i)
      s += min(mb / k[i], long(1e9));
    if (s < t)
      lb = mb + 1;
    else
      rb = mb;
  }
  cout << lb;
}