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

int main() {
  int n, m;
  while (cin >> n >> m) {
    vll as(n);
    REP(i,n) cin >> as[i];
    map<ll, ll> mp;
    REP(i,m) {
      int b, c;
      cin >> b >> c;
      mp[c] += b;
    }

    sort(ALL(as));
    REP(i,as.size()) {
      if (mp.empty()) continue;
      while (mp.size()) {
        auto it = mp.end(); --it;
        if (it->second == 0) mp.erase(it);
        else break;
      }
      if (mp.empty()) continue;
      auto it = mp.end(); --it;
      if (it->first > as[i]) {
        as[i] = it->first;
        (it->second)--;
      }
    }

    // pp(as);
    cout << accumulate(ALL(as), 0LL) << endl;
  }
}
