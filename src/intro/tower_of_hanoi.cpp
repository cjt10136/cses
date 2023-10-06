#include <bits/stdc++.h>

using namespace std;

int n;

void solve(int n, int a = 1, int b = 3)
{
  if (n == 0)
    return;
  solve(n - 1, a, a ^ b ^ 1 ^ 2 ^ 3);
  cout << a << ' ' << b << '\n';
  solve(n - 1, a ^ b ^ 1 ^ 2 ^ 3, b);
}

int main()
{
  ios::sync_with_stdio(false);

  cin >> n;
  cout << (1 << n) - 1 << '\n';
  solve(n);
}