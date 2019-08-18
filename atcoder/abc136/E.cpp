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

inline void write_bool(bool b, const string &tval, const string &fval) {
  cout << (b ? tval : fval) << endl;
} 
inline void YESNO(bool b) { return write_bool(b, "YES", "NO"); }
inline void YesNo(bool b) { return write_bool(b, "Yes", "No"); }
inline void yesno(bool b) { return write_bool(b, "yes", "no"); }

vll calcFactors(ll n) {
  vll result;
  for (ll i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      result.push_back(i);
      result.push_back(n / i);
    }
  }
  return result;
}

bool ok(const vll &v, ll x, ll k) {
  const int n = v.size();
  vll a(n), b(n);
  REP(i,n) a[i] = v[i] - (v[i] / x * x);
  sort(ALL(a));
  REP(i,n) b[i] = x - a[i];

  vll aa(n), bb(n);
  REP(i,n) aa[i] += (i == 0 ? 0 : aa[i-1]) + a[i];
  for (int i = n - 1; i >= 0; --i) bb[i] += (i + 1 == n ? 0 : bb[i+1]) + b[i];
  // cout << "a, b" << endl;
  // pp(a); pp(b);
  // cout << "aa, bb" << endl;
  // pp(aa); pp(bb);
  REP(i,n-1) if (max(aa[i], bb[i+1]) <= k) {
    // cout << "ok " << k << ' ' << aa[i] << ' ' << bb[i+1] << endl;
    return true;
  }
  if (aa[n-1] <= k) return true;
  if (bb[0] <= k) return true;
  return false;
}

int main() {
  int n, k;
  while (cin >> n >> k) {
    vll v(n);
    REP(i,n) cin >> v[i];
    ll sum = accumulate(ALL(v), 0LL);
    vll factors = calcFactors(sum);

    sort(ALL(factors)); reverse(ALL(factors));
    REP(i,factors.size()) if (ok(v, factors[i], k)) {
      cout << factors[i] << endl;
      break;
    }
  }
}
