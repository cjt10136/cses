#include <bits/stdc++.h>

using namespace std;

int t;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    auto ans{0};
    for (auto i{0}; i < n; ++i) {
      int x;
      cin >> x;
      if (i % 2)
        ans ^= x;
    }
    cout << (ans ? "first\n" : "second\n");
  }
}