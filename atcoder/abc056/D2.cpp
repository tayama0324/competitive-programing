#include <iostream>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <numeric>
#include <algorithm>
#include <string>
#include <complex>
 
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <cstring>
 
#define REP(i,e) for(int i=0;i<(int)(e);i++)
#define FOR(i,b,e) for(int i=(int)(b);i<(int)(e);i++)
#define ALL(c) (c).begin(), (c).end()
#define EACH(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define RALL(c) (c).rbegin(), (c).rend()
#define ALLA(a,n) ((a)+0), ((a)+n)
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vint;
typedef vector<long long> vll;
typedef vector<string> vstring;
typedef vector<double> vdouble;
 
template<class T>void pp(T v,int n){ REP(i,n)cout<<v[i]<< ' ' ; cout << endl; }
template<class T>void pp(T v){ EACH(it,v) cout << *it << ' ' ; cout << endl;  }
template<class T>T& ls(T& a,T b){ if(b<a) a=b; return a; }
template<class T>T& gs(T& a,T b){ if(b>a) a=b; return a; }
inline ll to_i(const string& s){ll n;sscanf(s.c_str(),"%lld",&n);return n;}
inline string to_s(ll n){char buf[32];sprintf(buf,"%lld",n);return string(buf);}

const int N = 5001;
const int K = 5001;

bool needed(const vint &a, int n, int k, int t) {
  static bool dp[N][K];
  REP(i,n+1) REP(j,k+1) dp[i][j] = false;
  dp[0][0] = true;
  REP(i,n) REP(j,k) {
    if (i != t && j + a[i] < k) dp[i+1][j+a[i]] = dp[i+1][j+a[i]] || dp[i][j];
    dp[i+1][j] = dp[i+1][j] || dp[i][j];
  }
  FOR(j,max(0,k-a[t]),k) if (dp[n][j]) return true;
  return false;
}

typedef int int_nk[N][K];
typedef bool bool_nk[N][K];

void DP(const vint &a, int n, int k, bool_nk dp, int_nk sum) {
  REP(i,n+1) REP(j,k+1) dp[i][j] = false;
  dp[0][0] = true;
  REP(i,n) REP(j,k) {
    if (j + a[i] < k) dp[i+1][j+a[i]] = dp[i+1][j+a[i]] || dp[i][j];
    dp[i+1][j] = dp[i+1][j] || dp[i][j];
  }
  REP(i,n+1) REP(j,k+1) {
    sum[i][j] = dp[i][j];
    if (j) sum[i][j] += sum[i][j-1];
  }
}

int main() {
  int n, k;
  while (cin >> n >> k) {
    vint a(n);
    REP(i,n) cin >> a[i];

    static bool_nk dp1, dp2;
    static int_nk sum1, sum2;
    DP(a, n, k, dp1, sum1);
    reverse(ALL(a));
    DP(a, n, k, dp2, sum2);
    reverse(ALL(a));
    int result = 0;
    REP(i,n) {
      bool *head = &dp1[i][0];
      int *tail = &sum2[n-i-1][0]; // tail[i] = sum[*][0] .. sum[0][i] (inclusive)
      bool needed = false;
      auto sum = [&](int n) { return n < 0 ? 0 : tail[n]; };
      REP(j,k) if (head[j] && sum(k-1-j) != sum(k-1-j-a[i])) {
        needed = true;
      }
      if (!needed) {
        // cout << "no-needs " << i << ' ' << a[i] << endl; 
        ++result;
      }
    }
    cout << result << endl;
  }
}
