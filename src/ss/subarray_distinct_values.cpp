#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(2e5);

int n, k, x[mxn];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;
  auto ans{0l};
  map<int, int> mp;
  for (auto i{0}, j{0}; i < n; ++i) {
    cin >> x[i];
    ++mp[x[i]];
    while (size(mp) > k) {
      if (auto it{mp.find(x[j])}; it->second == 1)
        mp.erase(it);
      else
        --it->second;
      ++j;
    }
    ans += i - j + 1;
  }
  cout << ans;
}
