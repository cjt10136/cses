#include <bits/stdc++.h>

using namespace std;

constexpr int mxn(1e3);

int n, x, a[mxn];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> x;
  for (auto i{0}; i < n; ++i)
    cin >> a[i];
  unordered_map<int, array<int, 2>> mp;
  for (auto i{0}; i < n; ++i) {
    for (auto j{i + 1}; j < n; ++j)
      if (auto it{mp.find(x - a[i] - a[j])}; it != end(mp)) {
        auto&& [p1, p2]{it->second};
        cout << i + 1 << ' ' << j + 1 << ' ' << p1 + 1 << ' ' << p2 + 1;
        return EXIT_SUCCESS;
      }
    for (auto j{0}; j < i; ++j)
      mp[a[i] + a[j]] = {i, j};
  }
  cout << "IMPOSSIBLE";
}