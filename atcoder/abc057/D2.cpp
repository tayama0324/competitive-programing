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

typedef ll Int;

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


typedef long double Double;

const Double eps = 1e-18;

bool eq(Double a, Double b) { return fabs(a - b) < eps; }

// max(abs_error, rel_error)
Double error(Double a, Double b) {
  Double abs_error = fabs(a - b);
  if (a > eps) { return min(abs_error, abs_error / a); }
  return abs_error;
}


int main() {
  int n, a, b;
  while (cin >> n >> a >> b) {
    vll v(n);
    REP(i,n) cin >> v[i];
    sort(RALL(v));

    Double average = 0;
    auto ave = [&](int c) { return accumulate(v.begin(), v.begin() + c, 0.0L) / c; };
    FOR(c,a,b+1) {
      gs(average, ave(c));
    }

    ll cnt = 0;
    FOR(c,a,b+1) if (error(average, ave(c)) < eps) {
      // cout << "# c = " << c << endl;
      map<ll,int> mn, mr;
      ll t = 1;
      REP(i,n) mn[v[i]]++;
      REP(i,c) mr[v[i]]++;
      for (const auto& e: mr) {
        // cout << "+= " << mn[e.first] << " C " << e.second << " = " <<
        //   C.choose(mn[e.first], e.second) << endl;
        t *= Pascal(mn[e.first], e.second);
      }
      cnt += t;
    }

    printf("%.9Lf\n%lld\n", average, cnt);
  }
}
