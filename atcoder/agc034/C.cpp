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

struct T { ll b, l, u; };

bool trivial(const vector<T> &v) {
  ll result = 0;
  REP(i,v.size()) result += v[i].b;
  return result == 0;
}

ll score(const T& t, ll x) {
  if (t.b <= x) return (x - t.b) * t.u;
  else return (x - t.b) * t.l;
}

bool ok(vector<T> &v, ll x, ll t) {
  const int n = v.size();
  ll q = t / x, r = t % x;
  sort(ALL(v), [&](const T& a, const T& b) { return score(a, x) - score(a, 0) > score(b, x) - score(b, 0); });
  ll sum = 0;
  REP(i,n) {
    if (i < q) sum += score(v[i], x);
    else sum += score(v[i], 0);
  }
  ll result = -(1LL << 60);
  // cout << "qrs =  " << q << ' ' << r << ' ' << sum << endl;
  // REP(i,n) cout << score(v[i], 0) << ' ' << score(v[i], r) << ' ' << score(v[i], x) << endl;
  REP(i,n) {
    ll cnt = sum;
    if (i < q) {
      cnt -= score(v[i], x);
      cnt += score(v[i], r);
      cnt -= score(v[q], 0);
      cnt += score(v[q], x);
    } else {
      cnt -= score(v[i], 0);
      cnt += score(v[i], r);
    }
    // cout << "cnt: " << i << ' ' << cnt << endl;
    gs(result, cnt);
  }


  // cout << t << ' ' << result << endl;
  return result >= 0;
}

int main() {
  ll n, x;
  while (cin >> n >> x) {
    vector<T> v(n);
    REP(i,n) {
      cin >> v[i].b >> v[i].l >> v[i].u;
    }

    if (trivial(v)) { cout << 0 << endl; continue; }
    // ok(v, x, 115);
    // break;
    ll lb = 0, ub = x * n;
    while (lb + 1 < ub) {
      ll mid = (lb + ub) / 2;
      if (ok(v, x, mid)) ub = mid;
      else lb = mid;
    }

    cout << ub << endl;
  }
}
