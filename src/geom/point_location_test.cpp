#include <bits/stdc++.h>

using namespace std;

int t;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t;
  while (t--) {
    complex<long> p[3];
    for (auto&& i : p) {
      int x, y;
      cin >> x >> y;
      i = {x, y};
    }
    if (auto c{(conj(p[1] - p[0]) * (p[2] - p[0])).imag()}; c > 0)
      cout << "LEFT\n";
    else if (c < 0)
      cout << "RIGHT\n";
    else
      cout << "TOUCH\n";
  }
}
