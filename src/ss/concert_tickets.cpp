#include <bits/stdc++.h>

using namespace std;

int n, m;
multiset<int> h;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for (auto i{0}; i < n; ++i) {
    int x;
    cin >> x;
    h.insert(x);
  }
  for (auto i{0}; i < m; ++i) {
    int t;
    cin >> t;
    if (auto it{h.upper_bound(t)}; it != begin(h)) {
      --it;
      cout << *it << '\n';
      h.erase(it);
    }
    else
      cout << "-1\n";
  }
}