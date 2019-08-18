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

template<class T,int L> class BIT{ // internally implemented in 1-based, but arguments are all 0-based.
public:
  T v[L+1];
  BIT(){ REP(i,L+1) v[i]=0; }
  T sum(int s,int d){ return zsum(d) - zsum(s-1); }                // [s, d]
  T zsum(int i){ T c=0; for(++i;i;i-=i&-i) c+=v[i]; return c; }    // [0, d]
  void add(T t,int i){ for(++i;i<=L;i+=i&-i) v[i]+=t; }
};
 
template<class T,int L> class BIT_REF{
public:
  T v[L];
  BIT_REF(){ REP(i,L) v[i]=0; }
  T sum(int s,int d){ return zsum(d) - zsum(s-1); }
  T zsum(int t){ T c=0; REP(i,t+1) c+=v[i]; return c; }
  void add(T t,int i){ v[i]+=t; }
};
 
template<class T,int L> class BIT2D{
public:
  BIT<T,L> v[L+1];
  T sum(int sx,int sy,int dx,int dy){ return zsum(dx,sy,dy) - zsum(sx-1,sy,dy); }         // [(sx, sy), (dx,dy)]
  T zsum(int x,int sy,int dy){ T c=0; for(++x;x;x-=x&-x) c+=v[x].sum(sy,dy); return c; }  
  void add(T t,int i,int j){ for(++i;i<=L;i+=i&-i) v[i].add(t,j); }
};
 
template<class T,int L> class BIT2D_REF{
public:
  T v[L][L];
  BIT2D_REF(){ REP(i,L) REP(j,L) v[i][j]=0; }
  T sum(int sx,int sy,int dx,int dy){ T c=0; FOR(i,sx,dx+1) FOR(j,sy,dy+1) c+=v[i][j]; return c; }
  void add(T t,int i,int j){ v[i][j]+=t; }
};

vint compress(const vint &a) {
  map<int, int> m;
  for (auto &e: a) m[e] = 0;
  int cnt = 0;
  for (auto &it: m) it.second = cnt++;
  vint result(a.size());
  REP(i,a.size()) result[i] = m[a[i]];
  return result;
}

int main() {
  int n;
  while (cin >> n) {
    vint xs(n), ys(n);
    REP(i,n) cin >> xs[i] >> ys[i];
    xs = compress(xs); ys = compress(ys);
  }
}
