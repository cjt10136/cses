#include <bits/stdc++.h>

using namespace std;

int n, x;
map<int, int> mp;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> x;
  for (auto i{0}; i < n; ++i) {
    int a;
    cin >> a;
    if (auto it{mp.find(x - a)}; it != end(mp)) {
      cout << it->second + 1 << ' ' << i + 1;
      return EXIT_SUCCESS;
    }
    mp[a] = i;
  }
  cout << "IMPOSSIBLE\n";
}