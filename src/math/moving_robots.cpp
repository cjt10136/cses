#include <bits/stdc++.h>

using namespace std;

constexpr int mxk{100};

int k;
double dp[mxk + 1][8][8], ans[8][8];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> k;
  fill(ans[0], ans[0] + 64, 1);
  for (auto i1{0}; i1 < 8; ++i1) {
    for (auto j1{0}; j1 < 8; ++j1) {
      fill(dp[0][0], dp[0][0] + (k + 1) * 64, 0);
      dp[0][i1][j1] = 1;
      for (auto k2{0}; k2 < k; ++k2)
        for (auto i2{0}; i2 < 8; ++i2)
          for (auto j2{0}; j2 < 8; ++j2) {
            auto nd{(i2 > 0) + (i2 < 7) + (j2 > 0) + (j2 < 7)};
            if (i2)
              dp[k2 + 1][i2 - 1][j2] += dp[k2][i2][j2] / nd;
            if (i2 < 7)
              dp[k2 + 1][i2 + 1][j2] += dp[k2][i2][j2] / nd;
            if (j2)
              dp[k2 + 1][i2][j2 - 1] += dp[k2][i2][j2] / nd;
            if (j2 < 7)
              dp[k2 + 1][i2][j2 + 1] += dp[k2][i2][j2] / nd;
          }
      for (auto i2{0}; i2 < 8; ++i2)
        for (auto j2{0}; j2 < 8; ++j2)
          ans[i2][j2] *= 1 - dp[k][i2][j2] ;
    }
  }
 cout << fixed << setprecision(6) << accumulate(ans[0], ans[0] + 64, .0);
}