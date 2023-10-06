#include <ext/pb_ds/assoc_container.hpp>

#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using oset =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n;
oset<int> s;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (auto i{1}; i <= n; ++i)
    s.insert(i);
  auto i{0};
  while (size(s)) {
    i = (i + 1) % size(s);
    auto it{s.find_by_order(i)};
    cout << *it << ' ';
    s.erase(it);
  }
}
