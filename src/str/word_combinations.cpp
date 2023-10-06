#include <bits/stdc++.h>

using namespace std;

struct bor {
  int next[26];
  bool used;
};

bor t[1000001];
int cnt = 0;

void add_string(string& s)
{
  int v = 0;
  for (int i = 0; i < s.size(); i++) {
    int nd = s[i] - 'a';
    if (t[v].next[nd] == -1) {
      cnt++;
      fill(t[cnt].next, t[cnt].next + 26, -1);
      t[v].next[nd] = cnt;
    }
    v = t[v].next[nd];
  }
  t[v].used = 1;
}

int main()
{
  ios_base::sync_with_stdio(false);
  
  fill(t[0].next, t[0].next + 26, -1);
  string s;
  cin >> s;
  int n;
  cin >> n;
  {
    string ss;
    for (int i = 0; i < n; i++) {
      cin >> ss;
      add_string(ss);
    }
  }
  vector<long long> dp(s.size() + 1, 0);
  dp[0] = 1;
  for (int i = 0; i < s.size(); i++) {
    int v = 0;
    for (int j = i; j < s.size(); j++) {
      // cout << i << " " << j << endl;
      int nd = s[j] - 'a';
      if (t[v].next[nd] == -1) {
        break;
      }
      else {
        v = t[v].next[nd];
        if (t[v].used == 1) {
          dp[j + 1] += dp[i];
          dp[j + 1] %= 1000000007;
        }
      }
    }
  }
  cout << dp[s.size()] << endl;
}