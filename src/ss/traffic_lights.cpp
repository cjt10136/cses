#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(2e5);

int x, n;
set<int> s{0};
map<int, int> mp;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> x >> n;
  s.insert(x);
  ++mp[x];
  for (auto i{0}; i < n; ++i) {
    int p;
    cin >> p;
    auto it{s.lower_bound(p)};
    auto r{*it};
    auto l{*--it};
    s.insert(p);
    --mp[r - l];
    if (!mp[r - l])
      mp.erase(r - l);
    ++mp[p - l];
    ++mp[r - p];
    cout << (--end(mp))->first << ' ';
  }
}
