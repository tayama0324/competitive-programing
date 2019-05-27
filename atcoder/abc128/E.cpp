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

struct segment { int s, t, x; };
struct person { int i, d, result; };

const int S = 0, D = 2, T = 1;
struct event { int tpe, index, time; };

int main() {
  int n, q;
  while (cin >> n >> q) {
    vector<segment> v(n);
    REP(i,n) cin >> v[i].s >> v[i].t >> v[i].x;
    REP(i,n) { v[i].s -= v[i].x; v[i].t -= v[i].x; }

    vector<person> p(q);
    REP(i,q) {
      cin >> p[i].d;
      p[i].i = i;
      p[i].result = -1;
    }

    vector<event> events;
    REP(i,n) {
      events.push_back((event) { S, i, v[i].s });
      events.push_back((event) { T, i, v[i].t });
    }
    REP(i,q) {
      events.push_back((event) { D, i, p[i].d });
    }

    sort(ALL(events), [](const event& a, const event &b){
                        if (a.time != b.time) return a.time < b.time;
                        return a.tpe < b.tpe;
                      });

    multiset<int> xs;
    for (const auto& e: events) {
      // cout << "Event " << "SDT"[e.tpe] << ' ' << e.index << ' ' << e.time << endl;
      if (e.tpe == S) {
        xs.insert(v[e.index].x);
      } else if (e.tpe == T) {
        xs.erase(xs.find(v[e.index].x));
      } else {
        if (xs.empty()) continue;
        int result = *xs.begin();
        if (p[e.index].result != -1) ls(p[e.index].result, result);
        else p[e.index].result = result;
      }
      // cout << "xs = "; pp(xs); cout << endl;

    }

    REP(i,q) cout << p[i].result << endl;
  }
}
