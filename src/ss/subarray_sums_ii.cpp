#include <bits/stdc++.h>

using namespace std;

int n, x;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> x;
  map<long, int> mp{{0, 1}};
  auto s{0l}, ans{0l};
  for (auto i{0}; i < n; ++i) {
    int a;
    cin >> a;
    s += a;
    if (auto it{mp.find(s - x)}; it != end(mp))
      ans += it->second;
    ++mp[s];
  }
  cout << ans;
}