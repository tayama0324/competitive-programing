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
  int n, k;
  while (cin >> n >> k) {
    vector<Edge> v;
    REP(i,n-1) v.push_back((Edge) { i + 1, n });

    int result = (n - 1) * (n - 2) / 2;
    REP(i,n-1) REP(j,i) if (result > k) {
      result--;
      v.push_back((Edge) { j + 1, i + 1 });
    }

    if (result == k) {
      cout << v.size() << endl;
      REP(i,v.size()) cout << v[i].src << ' ' << v[i].dst << endl;
    } else {
      cout << -1 << endl;
    }
    // cout << v.size() << " edges" << endl;
    // check
    // static int dp[128][128];
    // REP(i,n) REP(j,n) dp[i][j] = 1 << 20;
    // REP(i,n) dp[i][i] = 0;
    // REP(i,v.size()) dp[v[i].src-1][v[i].dst-1] = 1;
    // REP(i,v.size()) dp[v[i].dst-1][v[i].src-1] = 1;
    // //REP(i,n) pp(dp[i],n);

    // REP(k,n) REP(i,n) REP(j,n) ls(dp[i][j], dp[i][k] + dp[k][j]);
    // int cnt = 0;
    // REP(i,n) REP(j,i) if (dp[i][j] == 2) cnt++;
    // if (cnt == k) cout << "ac" << endl;
    // else cout << "wa" << ' ' << cnt << endl;
    //REP(i,n) pp(dp[i],n);
  }
}
