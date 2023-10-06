#include <ext/pb_ds/assoc_container.hpp>

#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using oset =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n;
oset<array<int, 2>> s;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (auto i{0}; i < n; ++i) {
    int x;
    cin >> x;
    s.insert({i, x});
  }
  for (auto i{0}; i < n; ++i) {
    int p;
    cin >> p, --p;
    auto it{s.find_by_order(p)};
    cout << (*it)[1] << ' ';
    s.erase(it);
  }
}
