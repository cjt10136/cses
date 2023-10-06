#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(2e5);

int n, ans[mxn];
array<int, 3> a[mxn];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (auto i{0}; i < n; ++i) {
    cin >> a[i][1] >> a[i][0];
    a[i][2] = i;
  }
  sort(a, a + n);
  set<array<int, 2>> s;
  for (auto i{0}; i < n; ++i) {
    auto it{s.lower_bound({a[i][1]})};
    if (it != begin(s)) {
      --it;
      ans[a[i][2]] = (*it)[1];
      s.erase(it);
    }
    else
      ans[a[i][2]] = size(s);
    s.insert({a[i][0], ans[a[i][2]]});
  }
  cout << size(s) << '\n';
  for (auto i{0}; i < n; ++i)
    cout << ans[i] + 1 << ' ';
}