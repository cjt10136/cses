#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(2e5);

int n, k, x[mxn];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;
  for (auto i{0}; i < n; ++i)
    cin >> x[i];
  long lb{*max_element(x, x + n)}, rb(1e18);
  while (lb < rb) {
    auto mb{(lb + rb) / 2}, s{0l};
    auto c{1};
    for (auto i{0}; i < n; ++i) {
      if (s + x[i] > mb) {
        ++c;
        s = 0;
      }
      s += x[i];
    }
    if (c > k)
      lb = mb + 1;
    else
      rb = mb;
  }
  cout << lb;
}