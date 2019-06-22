class Pascal_cls {
  static const int N = 1000;
  ll dp[N][N];
  ll rec(int n, int r) {
    if (n < 0 || r < 0) return 0;
    if (dp[n][r] != -1) return dp[n][r];
    if (n == 0 || n == r) return dp[n][r] = 1;
    return dp[n][r] = rec(n-1, r) + rec(n-1, r-1);
  }
public:
  Pascal_cls() { REP(i,N) REP(j,N) dp[i][j] = -1; }
  ll operator()(int n, int r) { return rec(n, r); }
};

Pascal_cls Pascal;

