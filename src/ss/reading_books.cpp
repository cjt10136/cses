#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  auto mx{0};
  auto s{0l};
  for (auto i{0}; i < n; ++i) {
    int t;
    cin >> t;
    mx = max(mx, t);
    s += t;
  }
  cout << max(2 * long{mx}, s);
}