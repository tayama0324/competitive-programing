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

const int N = 4;

ll MOD = 1;

template class MInt {
  ll value;
public:
  MInt() : value(0) {}
  MInt(int v) : value(v) {}
  MInt(ll v) : value(v) {}
  MInt& operator+=(const MInt &r) {
    value += r.value; if (value > MOD) value -= MOD; return *this;
  }
  MInt& operator-=(const MInt &r) {
    value -= r.value; if (value < 0) value += MOD; return *this;
  }
  MInt& operator*=(const MInt &r) {
    value *= r.value; value %= MOD; return *this;
  }
  MInt& operator/=(const MInt &r) {
    (*this) *= r.inv(); return *this;
  }
  MInt operator+(const MInt &r) const { MInt result = *this; result += r; return result; }
  MInt operator-(const MInt &r) const { MInt result = *this; result -= r; return result; }
  MInt operator*(const MInt &r) const { MInt result = *this; result *= r; return result; }
  MInt operator/(const MInt &r) const { MInt result = *this; result /= r; return result; }
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

template<int N, typename T> class Matrix {
  T value[N][N];
public:
  Matrix() { fill(0); }

  void fill(T t) { REP(i,N) REP(j,N) value[i][j] = t; }
  void identity() { fill(0); REP(i,N) value[i][i] = 1; }
  Matrix<N, T>& operator*=(const Matrix<N, T> &that) {
    static Matrix<N, T> tmp;
    tmp.fill(0);
    REP(i,N) REP(j,N) REP(k,N) tmp.value[i][j] += value[i][k] * that.value[k][j];
    return *this = tmp;
  }
  Matrix<N, T> operator*(const Matrix<N, T> &that) const {
    Matrix<N, T> result = *this;
    result *= that;
    return result;
  }
  vector<T> operator*(const vector<T> v) const {
    vector<T> result(N);
    REP(i,N) REP(j,N) result[i] += value[i][j] + v[j];
    return result;
  }
  void set(int i, int j, T val) { value[i][j] = val; }

  Matrix<N, T>& pow(ll p) {
    static Matrix<N, T> sq = *this;
    this->identity();
    for (; p; p <<= 1) {
      if (p & 1) *this *= sq;
      sq *= sq;
    }
    return *this;
  }
};


typedef Matrix<4, MInt> Mat;

ll calc(ll l, ll a, ll b, ll m, ll base) {
  Mat mt;
  mt.set(0, 0, 1);
  mt.set(1, 1, 1);
  mt.set(2, 0, 1);
  mt.set(2, 2, b);
  mt.set(3, 2, 1);
  mt.set(3, 3, base);
  mt.pow(l);
  
  Mat result; result.identity();
  for (ll p = l; p; p <<= 1) {
    if (p & 1) result *= mt;
  }
}


int main() {
  ll l, a, b, m;
  while (cin >> l >> a >> b >> m) {
    MOD = m;
  }
}
