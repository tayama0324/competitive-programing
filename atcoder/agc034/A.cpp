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

vint DP(const string &s, int a) {
  const int n = s.length();
  vint dp(n, 0);
  dp[a] = 1;
  REP(i,n) {
    if (i+1 < n && s[i+1] == '.') { dp[i+1] += dp[i]; ls(dp[i+1], 2); }
    if (i+2 < n && s[i+2] == '.') { dp[i+2] += dp[i]; ls(dp[i+2], 2); }
  }
  return dp;
}

int main() {
  int n, a, b, c, d;
  string s;
  while (cin >> n >> a >> b >> c >> d >> s) {
    a--; b--; c--; d--;
    vint dpa = DP(s, a), dpb = DP(s, b);
    if (c < d) {
      cout << (dpa[c] && dpb[d] ? "Yes" : "No") << endl;
    } else {
      if (dpb[d] == 2) {
        cout << (dpa[c] ? "Yes" : "No") << endl;
      } else if (dpb[d] == 1) {
        vint x, y;
        s[b] = '#'; x = DP(s, a); s[b] = '.';
        s[d] = '#'; y = DP(s, a); s[d] = '.';
        cout << (x[c] || y[c] ? "Yes" : "No") << endl;
      } else {
        cout << "No" << endl;
      }      
    }
  }
}
