#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(2e5);

int n, q;
long x[mxn + 1];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> q;
  for (auto i{1}; i <= n; ++i)
    cin >> x[i];
  for (auto i{1}; i <= n; ++i)
    x[i] += x[i - 1];
  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << x[b] - x[a - 1] << '\n';
  }
}