#include <iostream>
#include <vector>
#include <algorithm>

#define REP(i,n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vint;

const int inf = 1 << 20;

template<class T> void gs(T &a, T b) { a = max(a, b); }

int main() {
  int h, n;
  while (cin >> h >> n) {
    bool bad[20000][4];
    REP(i,h) REP(j,4) bad[i][j] = false;
    REP(j,4) bad[h][j] = bad[h+1][j] = true;
    
    REP(i,n) {
      int s, t; cin >> t >> s;
      bad[s][t] = true;
    }
    static int dp[20000][1 << 8];

    auto state = [&](int h) {
                   int result = 0;
                   REP(i,8) result = result | ((bad[h+i/4][i%4] ? 1 : 0) << i);
                   return result;
                 };
    REP(i,h+1) REP(j, 1 << 8) dp[i][j] = -inf;
    dp[0][state(0)] = 0;

    const int a = (1 << 0) | (1 << 1) | (1 << 4) | (1 << 5);
    const int b = (1 << 1) | (1 << 2) | (1 << 5) | (1 << 6);
    const int c = (1 << 2) | (1 << 3) | (1 << 6) | (1 << 7);
    const int d = a | c;
    const int e = 0;
    REP(i,h) REP(j, 1 << 8) {
      int btm = 0;
      REP(j,4) btm = btm | ((bad[i+2][j] ? 1 : 0) << (j + 4));
      if (!(j & a)) { gs(dp[i+1][(j | a) >> 4 | btm], dp[i][j] + 1); }
      if (!(j & b)) { gs(dp[i+1][(j | b) >> 4 | btm], dp[i][j] + 1); }
      if (!(j & c)) { gs(dp[i+1][(j | c) >> 4 | btm], dp[i][j] + 1); }
      if (!(j & d)) { gs(dp[i+1][(j | d) >> 4 | btm], dp[i][j] + 2); }
      if (!(j & e)) { gs(dp[i+1][(j | e) >> 4 | btm], dp[i][j] + 0); }
    }

    int result = 0;
    REP(j, 1 << 8) gs(result, dp[h][j]);
    cout << result << endl;
  }
}
