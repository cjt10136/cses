#include <bits/stdc++.h>

using namespace std;

long n, s;

int main()
{
  ios::sync_with_stdio(false);

  cin >> n;
  s = n * (n + 1) / 2;
  for (auto i{0}; i < n - 1; ++i) {
    int x;
    cin >> x;
    s -= x;
  }
  cout << s;
}