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

struct Data {
  multiset<ll> s;
  ll _sum = 0;
  void push(ll a) { s.insert(a); _sum += a; }
  ll popMax() {
    auto it = s.end(); it--;
    ll value = *it; s.erase(it);
    _sum -= value;
    return value;
  }
  ll popMin() {
    auto it = s.begin();
    ll value = *it; s.erase(it);
    _sum -= value;
    return value;
  }
  ll min() {
    return *s.begin();
  }
  ll max() {
    auto it = s.end(); --it;
    return *it;
  }
  ll sum() {
    return _sum;
  }
  int size() { return s.size(); }
};

int main() {
  int q;
  while (cin >> q) {
    Data lo, hi;
    ll bs = 0;
    REP(iter, q) {
      ll op, a, b; cin >> op;
      if (op == 1) {
        cin >> a >> b;
        bs += b;
        if (a > hi.min()) {
          hi.push(a);
        } else {
          lo.push(a);
        }
        while (lo.size() < hi.size() + 1) {
          lo.push(hi.popMin());
        }
        while (lo.size() > hi.size() + 1) {
          hi.push(lo.popMax());
        }
        // cout << "---" << endl;
        // cout << "lo: " << lo.sum() << ' ' ; pp(lo.s);
        // cout << "hi: " << hi.sum() << ' ' ; pp(hi.s);
      } else {
        ll x = lo.max();
        ll result = bs;
        result += x * lo.size() - lo.sum();
        result += hi.sum() - x * hi.size();
        cout << x << ' ' << result << endl;
      }
    }
  }
}
