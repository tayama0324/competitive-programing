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

int popcount(int n) {
  int result = 0;
  while (n) {
    result += (n & 1);
    n >>= 1;
  }
  return result;
}

int main() {
  int n, m;
  while (cin >> n >> m && n && m) {
    vint v(m);
    vint p(m);
    REP(i,m) {
      int k; cin >> k;
      REP(j,k) {
        int t; cin >> t; t--;
        v[i] = v[i] | (1 << t);
      }
    }
    REP(i,m) {
      cin >> p[i];
    }

    int result = 0;
    REP(i,1<<n) {
      bool ok = true;
      REP(j,m) {
        int st = popcount(i & v[j]);
        if (st % 2 != p[j]) ok = false;
      }

      if (ok) result++;
    }

    cout << result << endl;
  }
}
