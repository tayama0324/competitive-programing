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

ll MOD = 1000000007;

class MInt {
  ll value;
public:
  MInt() : value(0) {}
  MInt(int v) : value(v) { value %= MOD; }
  MInt(ll v) : value(v) { value %= MOD; }
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
    assert(0 <= p);
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
public:
  T value[N][N];
  Matrix() { fill(0); }

  void fill(T t) { REP(i,N) REP(j,N) value[i][j] = t; }
  void identity() { fill(0); REP(i,N) value[i][i] = 1; }
  Matrix<N, T>& operator*=(const Matrix<N, T> &that) {
    static Matrix<N, T> tmp;
    tmp.fill(0);
    REP(i,N) REP(j,N) REP(k,N) tmp.value[i][j] += value[i][k] * that.value[k][j];
    *this = tmp;
    return *this;
  }
  Matrix<N, T> operator*(const Matrix<N, T> &that) const {
    Matrix<N, T> result = *this;
    result *= that;
    return result;
  }
  vector<T> operator*(const vector<T> &v) const {
    assert(v.size() == N);
    vector<T> result(N);
    REP(i,N) REP(j,N) result[i] += value[i][j] * v[j];
    return result;
  }
  T& operator()(int i, int j) { return value[i][j]; }

  Matrix<N, T> pow(ll p) const {
    assert(0 <= p);
    static Matrix<N, T> result, sq;
    sq = *this;
    result.identity();
    for (; p; p >>= 1) {
      if (p & 1) result = result * sq;
      sq *= sq;
    }
    return result;
  }

  void print() const { REP(i,N) pp(value[i], N); }
};


typedef Matrix<4, MInt> Mat;

ll calc(ll l, ll a, ll b, MInt base) {
  Mat mt;
  mt(0, 0) = 1;
  mt(1, 1) = 1;
  mt(2, 1) = 1;
  mt(2, 2) = 1;
  mt(3, 2) = 1;
  mt(3, 3) = base;
  mt = mt.pow(l);  
  vector<MInt> x = { a, b, a, 0 };
  vector<MInt> result = mt * x;
  return result[3];
}

void test() {
  Mat a, b, c, d;
  a(0, 0) = 1;
  a(0, 1) = 2;
  a(1, 1) = 3;
  a(1, 2) = 4;
  a(2, 2) = 5;
  a(2, 3) = 6;
  a(3, 3) = 7;
  a(3, 0) = 8;

  b = a;
  (a * b).print();
  cout << endl;
  (a * a).print();
  cout << endl;
}

int main() {
  // test();
  // return 0;

  ll l, a, b, m;
  while (cin >> l >> a >> b >> m) {
    MOD = m;

    // returns max i where s_i < upper
    auto index = [&](ll upper) { return (upper - a - 1) / b; };
    
    ll left = 1;
    ll s_next = 0;
    MInt result = 0;
    const ll s_max = a + b * (l - 1);
    FOR(digit, 1, 20) {
      if (s_next >= l) break;
      ll right = left * 10.0 > s_max + 1 ? s_max + 1 : left * 10;
      ll s_until = min(index(right), l - 1);
      ll len = max(0LL, s_until - s_next + 1);

      // cout << digit << " digits number: " << left << " - " << right << endl;
      // cout << "s: " << s_next << ' ' << s_until << endl;
      // cout << "index, l, a = " << index(right) << ' ' << l << ' ' << a << endl;
      // cout << "s[i]: " << (a + b * s_next) << ' ' << (a + b * s_until) << endl;
      // cout << len << " elements" << endl;
      // cout << "len, digit = " << len << " " << digit << endl;
      // cout << "calc = " << calc(len, MInt(a) + MInt(b) * MInt(s_next), b, left * 10) << endl;
      // cout << endl; 
      result *= MInt(10).pow(len).pow(digit);
      result += calc(len, MInt(a) + MInt(b) * MInt(s_next), b, MInt(left) * MInt(10));
      s_next += len;
      left *= 10;
    }

    cout << result << endl;
  }
}
