#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
  ios::sync_with_stdio(false);

  cin >> n;
  if (n == 1) {
    cout << 1;
    return EXIT_SUCCESS;
  }
  if (n == 2 || n == 3) {
    cout << "NO SOLUTION\n";
    return EXIT_SUCCESS;
  }
  for (auto i{2 - n % 2}; i <= n; i += 2)
    cout << i << ' ';
  for (auto i{1 + n % 2}; i < n; i += 2)
    cout << i << ' ';
}
