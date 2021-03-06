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

template<class T>void pp(T v,int n){ REP(i,n)cout<<v[i]<<(i+1==n?'\n':' '); }
template<class T>void pp(T v){ EACH(it,v) cout<<(it==v.begin()?"":" ")<<*it; cout << endl;  }
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

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a; }
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; }

ll solve(string &s, string &t) {
  vector<int> vs[26];
  REP(i,s.size()) {
    vs[s[i]-'a'].push_back(i);
  }

  ll result = 0;
  int cur = 0;
  REP(i,t.size()) {
    // cout << "t[i] = " << t[i] << ' ' << ", " << cur << ' ' << result << endl;
    int ch = t[i] - 'a';
    if (vs[ch].empty()) return -1;
    auto it = lower_bound(ALL(vs[ch]), cur);
    if (it != vs[ch].end()) {
      int pos = *it;
      result += pos - cur + 1;
      cur = pos + 1;
    } else {
      it = lower_bound(ALL(vs[ch]), 0);
      int pos = *it;
      result += s.length() - cur + pos + 1;
      cur = pos + 1;
    }
  }

  return result;
}

int main() {
  ll l, r;
  while (cin >> l >> r) {
    vector<pair<int,int>> v;
    FOR(x,l,r+1) FOR(y,l,r+1) {
      char ok = (y % x == (x ^ y)) ? 'o' : 'x';      
      cout << ok << ' ' << x << ' ' << y << ' ' << (y % x) << ' ' << (x ^ y) << endl;
    }
  }
}
