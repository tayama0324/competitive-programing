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

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; } 

struct Edge { ll src, dst, cost; };
bool operator>(const Edge& a, const Edge& b) {
  return a.cost > b.cost;
}

int main() {
  int n;
  while (cin >> n) {
    vector<vector<Edge>> v(n);
    REP(i,n-1) {
      int s, d, c; cin >> s >> d >> c;
      s--; d--;
      v[s].push_back((Edge) { s, d, c });
      v[d].push_back((Edge) { d, s, c });
    }

    int q, k; cin >> q >> k; k--;
    vll cost(n, 1LL << 60);
    priority_queue<Edge, vector<Edge>, greater<Edge>> qu;
    for (qu.push((Edge){ -1, k, 0}); qu.size(); qu.pop()) {
      Edge e = qu.top();
      if (cost[e.dst] <= e.cost) continue;
      cost[e.dst] = e.cost;

      for (auto &next: v[e.dst]) {
        qu.push((Edge) { e.dst, next.dst, e.cost + next.cost });
      }
    }

    REP(_,q) {
      int a, b; cin >> a >> b; a--; b--;
      cout << cost[a] + cost[b] << endl;
    }
  }
}
