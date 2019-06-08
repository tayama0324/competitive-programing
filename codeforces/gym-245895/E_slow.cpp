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


const int N = 2048;
const int inf = 1 << 29;

/*
  Dinic (with adjacency matrix)
*/
int l[N], cap[N][N], net[N][N];
int DFS(int n,int src,int snk,int f){
  // cout << "Dinic " << n << ' ' << f << endl;
  int t;
  if(!f || src==snk) return f;
  REP(i,n) if(l[src]+1==l[i] && (t=DFS(n,i,snk,min(f,cap[src][i])))){
    cap[src][i]-=t; cap[i][src]+=t;
    net[src][i]+=t; net[i][src]-=t;
    return t;
  }
  return 0;
}
 
int Dinic(int n,int src,int snk){
  memset(net,0,sizeof net);
  int ans=0;
  while(true){
    queue<int> qu;
    REP(i,n) l[i]=inf;
    for(qu.push(src);qu.size();qu.pop()){
      int t=qu.front();
      if(l[t]==inf) l[t]=0;
      REP(i,n) if(cap[t][i] && l[i]==inf){ l[i]=l[t]+1; qu.push(i); }
    }
    if(l[snk]==inf) break;
    for(int f;(f=DFS(n,src,snk,inf));) ans+=f;
  }
  return ans;
}

const int DI[] = { -1, 0, 1, 0 };
const int DJ[] = { 0, 1, 0, -1 };

int main() {
  int li, lj, c;
  while (cin >> lj >> li >> c) {
    vector<string> s(li);
    REP(i,li) cin >> s[i];
    vint v(c);
    REP(i,c) cin >> v[i];

    const int n = li * lj * 2 + 1;
    auto in = [&](int i, int j) { return i * li + j; };
    auto out = [&](int i, int j) { return li * lj + i * li + j; };
    const int snk = n - 1;
    int src;
    REP(i,n) REP(j,n) cap[i][j] = net[i][j] = 0;
    
    // cout << snk << endl;
    
    REP(i,li) REP(j,lj) {
      REP(d,4) {
        int ni = i + DI[d], nj = j + DJ[d];
        if (0 <= ni && ni < li && 0 <= nj && nj < lj) {
          cap[out(i, j)][in(ni, nj)] = inf;
        } else {
          cap[out(i, j)][snk] = inf;
        }
      }
      int w;
      if ('a' <= s[i][j] && s[i][j] <= 'z') w = v[s[i][j] - 'a'];
      else w = inf;
      cap[in(i, j)][out(i, j)] = w;

      if (s[i][j] == 'B') src = in(i, j);
    }

    // REP(i,n) pp(cap[i],n);
    // REP(i,li) REP(j,lj) cout << i << ' ' << j << ' ' << cap[in(i, j)][out(i, j)] << endl;
    // REP(i,li) REP(j,lj) cout << i << ' ' << j << ' ' << cap[out(i, j)][snk] << endl;

    // REP(i,li) REP(j,lj) cout << i << ' ' << j << ' ' << in(i,j) << ' ' << out(i,j) << endl;

    int result = Dinic(n, src, snk);
    if (result == inf) cout << -1 << endl;
    else cout << result << endl;
  }
}
