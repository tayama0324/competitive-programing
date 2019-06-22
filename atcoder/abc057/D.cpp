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

const double eps = 1e-12;

typedef ll Int;


const int N = 128;
ll dp[N][N];

ll rec(int n, int r) {
  if (n < 0 || r < 0) return 0;
  if (dp[n][r] != -1) return dp[n][r];
  if (n == 0 || n == r) return dp[n][r] = 1;
  return dp[n][r] = rec(n-1, r) + rec(n-1, r-1);
}

class C_cls {
  static const int N = 1000000;
  vector<Int> facts;
public:
  C_cls() : facts(vector<Int>(N, 1)){
    FOR(i,1,N) facts[i] = facts[i-1] * Int(i);
  }
  Int choose(int n, int r) { return rec(n, r); }
};

C_cls C;

class Frac {
  ll num, den;  // num / den
public:
  Frac(ll _num, ll _den) : num(_num), den(_den) { normalize(); }
  Frac(int v) : Frac(v, 1) {}
  Frac(ll v) : Frac(v, 1) {}
  Frac() : Frac(0, 1) {}
  void normalize() {
    int s = sign(num) * sign(den);
    if (s == 0) { num = 0, den = 1; }
    else {
      num = llabs(num); den = llabs(den);
      ll g = gcd(num, den);
      num /= g; den /= g;
      num *= s;
    }
  }
  int sign() { return sign(num); }
  int sign(ll n) { return n > 0 ? 1 : (n < 0 ? -1 : 0); }
  ll gcd(ll a, ll b) { return a % b == 0 ? b : gcd(b, a%b); }
  Frac& operator+=(const Frac &r) {
    ll a = num * r.den, b = r.num * den;
    num = a + b, den = den * r.den;
    normalize();
    return *this;
  }
  Frac& operator-=(const Frac &r) {
    (*this) += Frac(-r.num, r.den);
    return *this;
  }
  Frac& operator*=(const Frac &r) {
    num *= r.num; den *= r.den;
    normalize();
    return *this;
  }
  Frac& operator/=(const Frac &r) {
    (*this) *= Frac(r.den, r.num);
    return *this;
  }
  Frac operator+(const Frac &r) const { Frac result = *this; result += r; return result; }
  Frac operator-(const Frac &r) const { Frac result = *this; result -= r; return result; }
  Frac operator*(const Frac &r) const { Frac result = *this; result *= r; return result; }
  Frac operator/(const Frac &r) const { Frac result = *this; result /= r; return result; }
  Frac pow(ll p) const {
    Frac result = 1, x = *this;
    for (;p;p >>= 1) {
      if (p & 1) result *= x;
      x *= x;
    }
    return result;
  }
  bool operator<(const Frac &r) { return (*this - r).sign() < 0; }
  bool operator<=(const Frac &r) { return (*this - r).sign() <= 0; }
  bool operator>(const Frac &r) { return (*this - r).sign() > 0; }
  bool operator>=(const Frac &r) { return (*this - r).sign() >= 0; }
  bool operator==(const Frac &r) { return (*this - r).sign() == 0; }
  bool operator!=(const Frac &r) { return (*this - r).sign() != 0; }
  operator double() const {
    return (double) num / den;
  }
  operator string() const {
    return "(" + to_s(num) + " / " + to_s(den) + ")";
  }
};


int main() {
  REP(i,N) REP(j,N) dp[i][j] = -1;
  
  int n, a, b;
  while (cin >> n >> a >> b) {
    vll v(n);
    REP(i,n) cin >> v[i];
    sort(RALL(v));

    Frac average = 0;
    auto ave = [&](int c) { return Frac(accumulate(v.begin(), v.begin() + c, 0LL), c); };
    FOR(c,a,b+1) {
      auto av = ave(c);
      // cout << "# " << c << ' ' << (string)av << ' ' << string(average) << ' ' << (bool)(av > average) << endl;
      gs(average, ave(c));
    }

    ll cnt = 0;
    FOR(c,a,b+1) if (average == ave(c)) {
      // cout << "# c = " << c << endl;
      map<ll,int> mn, mr;
      ll t = 1;
      REP(i,n) mn[v[i]]++;
      REP(i,c) mr[v[i]]++;
      for (const auto& e: mr) {
        // cout << "+= " << mn[e.first] << " C " << e.second << " = " <<
        //   C.choose(mn[e.first], e.second) << endl;
        t *= C.choose(mn[e.first], e.second);
      }
      cnt += t;
    }

    // cout << "result " << ' ' << average.num << "/" << average.den << endl;
    printf("%.9lf\n%lld\n", (double)average, cnt);
  }
}
