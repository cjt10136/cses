#include <ext/pb_ds/assoc_container.hpp>

#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using oset =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

constexpr int mxn(2e5);

int n, ans1[mxn], ans2[mxn];
array<int, 3> x[mxn];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (auto i{0}; i < n; ++i) {
    cin >> x[i][0] >> x[i][1];
    x[i][2] = i;
  }
  sort(x, x + n, [](array<int, 3> lhs, array<int, 3> rhs) {
    return lhs[0] != rhs[0] ? lhs[0] < rhs[0] : lhs[1] > rhs[1];
  });
  oset<array<int, 2>> s;
  for (auto i{n - 1}; ~i; --i) {
    ans1[x[i][2]] = s.order_of_key({x[i][1], n});
    s.insert({x[i][1], x[i][2]});
  }
  s.clear();
  for (auto i{0}; i < n; ++i) {
    ans2[x[i][2]] = i - s.order_of_key({x[i][1], -1});
    s.insert({x[i][1], x[i][2]});
  }
  for (auto i{0}; i < n; ++i)
    cout << ans1[i] << ' ';
  cout << '\n';
  for (auto i{0}; i < n; ++i)
    cout << ans2[i] << ' ';
}