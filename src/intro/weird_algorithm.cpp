#include <bits/stdc++.h>

using namespace std;

long n;

int main()
{
  ios::sync_with_stdio(true);

  cin >> n;
  while (n != 1) {
    cout << n << ' ';
    n = n % 2 ? 3 * n + 1 : n / 2;
  }
  cout << 1;
}