#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> n;
  vector<int> ans;
  while (n--) {
    int k;
    cin >> k;
    auto p{lower_bound(begin(ans), end(ans), k)};
    if (p != end(ans))
      *p = k;
    else
      ans.push_back(k);
  }
  cout << size(ans);
}