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
    bool ans{false};
    for (auto i{0}; i < n; ++i) {
      int x;
      cin >> x;
      ans |= x & 1;
    }
    cout << (ans ? "first\n" : "second\n");
  }
}