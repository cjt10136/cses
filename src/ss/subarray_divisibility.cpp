#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> n;
  map<long, int> mp{{0, 1}};
  auto ans{0l};
  for (auto i{0}, s{0}; i < n; ++i) {
    int a;
    cin >> a;
    s = (s + a % n + n) % n;
    if (auto it{mp.find(s)}; it != end(mp))
      ans += it->second;
    ++mp[s];
  }
  cout << ans;
}