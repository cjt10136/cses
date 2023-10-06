#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(2e5);

int n, x[mxn], nl[mxn];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (auto i{0}; i < n; ++i) {
    cin >> x[i];
    nl[i] = i - 1;
    while (~nl[i] && x[nl[i]] >= x[i])
      nl[i] = nl[nl[i]];
    cout << nl[i] + 1 << ' ';
  }
}