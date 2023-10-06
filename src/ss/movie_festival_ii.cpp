#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(2e5);

int n, k;
array<int, 2> a[mxn];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;
  for (auto i{0}; i < n; ++i)
    cin >> a[i][1] >> a[i][0];
  sort(a, a + n);
  auto ans{0};
  multiset<int> s;
  for (auto i{0}; i < n; ++i) {
    auto it{s.upper_bound(a[i][1])};
    if (it != begin(s)) {
      --it;
      s.erase(it);
    }
    if (size(s) < k) {
      s.insert(a[i][0]);
      ++ans;
    }
  }
  cout << ans;
}