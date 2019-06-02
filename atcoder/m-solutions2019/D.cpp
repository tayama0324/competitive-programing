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

int main() {
  ios::sync_with_stdio(false);
  int n;
  while (cin >> n) {
    // vector< vector<Edge> > v(n);
    vector<vint> v(n);
    REP(i,n-1) {
      int a, b; cin >> a >> b; a--; b--;
      v[a].push_back(b);
      v[b].push_back(a);
    }

    vll c(n);
    REP(i,n) cin >> c[i];
    sort(RALL(c));

    ll best = 0;
    vint bestV;

    vint vc(n);
    const int N = 1 << 20;
    static int qu[N];
    // queue<int> qu;
    REP(root,n) {
      // if (root != 0) continue;
      vc.assign(n, -1);
      int o = 0;
      int head = 0, tail = 0;
      for (qu[tail++] = root; tail != head;) {
        int p = qu[head++]; head &= N - 1; 
        if (vc[p] != -1) continue;
        vc[p] = c[o++];
        for(int e: v[p]) if (vc[e] == -1) { qu[tail++] = e; tail &= N - 1; }
      }

      ll result = 0;
      REP(i,n) for(int e: v[i]) result += min(vc[i], vc[e]);
      if (result > best) {
        best = result;
        bestV.swap(vc);
      }
    }

    cout << best / 2 << endl;
    REP(i,n) {
      if (i) cout << ' ';
      cout << bestV[i];
    }
    cout << endl;
  }
}
