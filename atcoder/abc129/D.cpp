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
  int sizeOf(int n) { return -v[root(n)]; } 
};

int main() {
  int li, lj;
  while (cin >> li >> lj) {
    vstring v(li);
    REP(i,li) cin >> v[i];

    vector<vint> vert(li, vint(lj));
    vector<vint> hori(li, vint(lj));

    REP(i,li) {
      DisjointSet ds(lj);
      REP(j,lj-1) if (v[i][j] == '.' && v[i][j+1] == '.') ds.unite(j, j + 1);
      REP(j,lj) hori[i][j] = ds.sizeOf(j);
    }
    
    REP(j,lj) {
      DisjointSet ds(li);
      REP(i,li-1) if (v[i][j] == '.' && v[i+1][j] == '.') ds.unite(i, i + 1);
      REP(i,li) vert[i][j] = ds.sizeOf(i);
    }

    int result = 0;
    REP(i,li) REP(j,lj) gs(result, vert[i][j] + hori[i][j] - 1);
    cout << result << endl;
  }
}
