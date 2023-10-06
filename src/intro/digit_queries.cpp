#include <bits/stdc++.h>

using namespace std;

int q;
long k;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> q;
  while (q--) {
    cin >> k;
    if (k <= 9) {
      cout << k << '\n';
      continue;
    }
    auto b{1l};
    auto d{1};
    for (; 9 * b * d < k; b *= 10, ++d)
      k -= 9 * b * d;
    --k;
    cout << to_string(b + k / d)[k % d] << '\n';
  }
}