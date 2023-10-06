#include <ext/pb_ds/assoc_container.hpp>

#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using oset =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

constexpr int mxn(2e5);

int n, q, p[mxn];
oset<array<int, 2>> s;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> q;
  for (auto i{0}; i < n; ++i) {
    cin >> p[i];
    s.insert({p[i], i});
  }
  while (q--) {
    char qt;
    cin >> qt;
    if (qt == '!') {
      int k, x;
      cin >> k >> x, --k;
      s.erase({p[k], k});
      p[k] = x;
      s.insert({p[k], k});
    }
    else {
      int a, b;
      cin >> a >> b;
      cout << s.order_of_key({b + 1, 0}) - s.order_of_key({a, 0}) << '\n';
    }
  }
}