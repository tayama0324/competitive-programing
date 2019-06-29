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

struct Edge { int src, dst; };

class DisjointSet {
public:
  vint v;
  DisjointSet(int n) : v(n, -1) {}

  int root(int n) { return v[n] < 0 ? n : (v[n] = root(v[n])); }
  bool unite(int a, int b) {
    int ra = root(a), rb = root(b);
    if (ra == rb) return false;
    if (-ra > -rb) swap(ra, rb);
    v[rb] += v[ra];
    v[ra] = rb;
    return true;
  }
  int size() { return count_if(ALL(v), [](int x){ return x < 0; }); }
};


const int N = 100001;

int main() {
  int n;
  while (cin >> n) {
    vint x(n), y(n);
    REP(i,n) cin >> x[i] >> y[i];

    auto vx = [](int x) { return x; };
    auto vy = [](int y) { return N + y; };

    DisjointSet ds(N + N);
    REP(i,n) ds.unite(vx(x[i]), vy(y[i]));
    vint cx(N + N), cy(N + N);
    REP(i,N) {
      cx[ds.root(vx(i))]++;
      cy[ds.root(vy(i))]++;
    }

    ll result = 0;
    REP(i,N+N) result += (ll)cx[i] * cy[i];
    cout << result - n << endl;
  }
}
