#include <iostream>

using namespace std;

int q;

int solve(int n, int k)
{
  if (k <= (n + 1) / 2)
    return (2 * k - 1) % n + 1;
  return 2 * solve(n / 2, k - (n + 1) / 2) + (n % 2 ? 1 : -1);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> q;
  while (q--) {
    int n, k;
    cin >> n >> k;
    cout << solve(n, k) << '\n';
  }
}