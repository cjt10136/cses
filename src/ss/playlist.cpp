#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(2e5);

int n, k[mxn], ans{0};
set<int> s;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (auto i{0}; i < n; ++i)
    cin >> k[i];
  for (auto i{0}, j{0}; i < n; ++i) {
    while (j < n && !s.contains(k[j])) {
      s.insert(k[j]);
      ++j;
    }
    ans = max(ans, j - i);
    s.erase(k[i]);
  }
  cout << ans;
}