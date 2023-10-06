#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(2e5);

int n;
array<int, 3> a[mxn];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (auto i{0}; i < n; ++i)
    cin >> a[i][1] >> a[i][0] >> a[i][2];
  sort(a, a + n);
  map<int, long> mp{{0, 0}};
  for (auto i{0}; i < n; ++i)
    if (auto it{--mp.lower_bound(a[i][1])};
        it->second + a[i][2] > (--mp.upper_bound(a[i][0]))->second) {
      mp[a[i][0]] = it->second + a[i][2];
    }
  cout << (*--end(mp)).second;
}