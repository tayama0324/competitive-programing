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

template<ll MOD> class MInt {
  ll value;
public:
  MInt() : value(0) {}
  MInt(int v) : value(v) {}
  MInt(ll v) : value(v) {}
  MInt& operator+=(const MInt<MOD> &r) {
    value += r.value; if (value > MOD) value -= MOD; return *this;
  }
  MInt& operator-=(const MInt<MOD> &r) {
    value -= r.value; if (value < 0) value += MOD; return *this;
  }
  MInt& operator*=(const MInt<MOD> &r) {
    value *= r.value; value %= MOD; return *this;
  }
  MInt& operator/=(const MInt<MOD> &r) {
    (*this) *= r.inv(); return *this;
  }
  MInt operator+(const MInt<MOD> &r) const { MInt result = *this; result += r; return result; }
  MInt operator-(const MInt<MOD> &r) const { MInt result = *this; result -= r; return result; }
  MInt operator*(const MInt<MOD> &r) const { MInt result = *this; result *= r; return result; }
  MInt operator/(const MInt<MOD> &r) const { MInt result = *this; result /= r; return result; }
  MInt pow(ll p) const {
    MInt result = 1, x = *this;
    for (;p;p >>= 1) {
      if (p & 1) result *= x;
      x *= x;
    }
    return result;
  }
  MInt inv() const { return this->pow(MOD - 2); }
  operator ll() const { return value; }
  
};

typedef MInt<1000000007> Int;

class C_cls {
  static const int N = 1000000;
  vector<Int> facts;
public:
  C_cls() : facts(vector<Int>(N, 1)){
    FOR(i,1,N) facts[i] = facts[i-1] * Int(i);
  }
  Int choose(int n, int r) { return facts[n] / (facts[r] * facts[n-r]); }
};

C_cls C;



int main() {
  string s;
  while (cin >> s) {
    const int n = s.length();
    static Int dp[111111][13];
    REP(i,n+1) REP(j,13) dp[i][j] = 0;

    dp[0][0] = 1;
    REP(i,n) REP(j,13) {
      if (isdigit(s[i])) {
        int t = s[i] - '0';
        dp[i+1][(j*10+t)%13] += dp[i][j];
      } else {
        REP(k,10) {
          dp[i+1][(j*10+k)%13] += dp[i][j];
        }
      }
    }

    // REP(i,n+1) {
    //   cout << i << ": " ; pp(dp[i], 13);
    // }
    cout << (int)dp[n][5] << endl;
  }
}
