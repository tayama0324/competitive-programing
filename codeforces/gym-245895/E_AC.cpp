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
  Dinic (with adjacency list)
*/
struct edge{ int dst,cap,net,rev; };
vector<edge>  v[N];
vector<edge*> u[N];
vector<edge*>::iterator w[N];
int l[N];
 
void add(int src,int dst,int a,int b){
  v[src].push_back((edge){dst,a,0,(int)v[dst].size()  });
  v[dst].push_back((edge){src,b,0,(int)v[src].size()-1});
}

int cnt = 0;

int DFS(int n,int src,int snk,int f){
  int t;
  ++cnt;
  if (cnt % 1000000 == 0) cout << "#cnt = " << cnt << endl;
  if(!f || src==snk) return f;
  for (auto&it=w[src];it!=u[src].end();++it) if((t=DFS(n,(*it)->dst,snk,min(f,(*it)->cap)))){
    (*it)->cap-=t; v[(*it)->dst][(*it)->rev].cap+=t;
    (*it)->net+=t; v[(*it)->dst][(*it)->rev].net-=t;
    return t;
  }
  return 0;
}
 
int Dinic(int n,int src,int snk){
  int ans=0;

  while(true){
    static int qu[N+N],a,b;
    REP(i,n) l[i]=inf;
    for(a=0,b=1,qu[a]=src;b-a;a++){
      int t=qu[a];
      if(l[t]==inf) l[t]=0;
      EACH(it,v[t]) if(it->cap && l[it->dst]==inf){ l[it->dst]=l[t]+1; qu[b++]=it->dst; }
    }
    // cout << "#level = " << l[snk] << endl;
    if(l[snk]==inf) break;
    REP(i,n){
      u[i].clear();
      REP(j,v[i].size()) if(l[i]+1==l[v[i][j].dst]) u[i].push_back(&v[i][j]);
      w[i] = u[i].begin();
    }
    // cout << "Residue " << n << endl;
    // REP(i,n) for (auto e: u[i]) cout << i << ' ' << e->dst << ' ' << e->cap << endl;
    // cout << endl;
                                  
    
    for(int f;(f=DFS(n,src,snk,inf));) {
      // cout << "Level " << l[snk] << ' ' << f << endl;
      ans+=f;
    }
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
    vint cs(c);
    REP(i,c) cin >> cs[i];

    const int n = li * lj * 2 + 1;
    auto in = [&](int i, int j) { return i * lj + j; };
    auto out = [&](int i, int j) { return li * lj + i * lj + j; };
    const int snk = n - 1;
    int src;
    REP(i,n) { v[i].clear(); u[i].clear(); }
    
    // cout << snk << endl;
    
    REP(i,li) REP(j,lj) {
      bool boundary = false;
      REP(d,4) {
        int ni = i + DI[d], nj = j + DJ[d];
        if (0 <= ni && ni < li && 0 <= nj && nj < lj) {
          add(out(i, j), in(ni, nj), inf, 0);
        } else {
          boundary = true;
        }
      }
      if (boundary) add(out(i, j), snk, inf, 0);

      int w;
      if ('a' <= s[i][j] && s[i][j] <= 'z') w = cs[s[i][j] - 'a'];
      else w = inf;
      
      add(in(i, j), out(i, j), w, 0);

      if (s[i][j] == 'B') {
        src = in(i, j);
        // cout << "lilj " << li << ' ' << lj << ' ' << n << endl;
        // cout << "ios = " << in(i, j) << ' ' << out(i, j) << ' ' << snk << endl;
        
      }
    }

    
    // REP(i,n) pp(cap[i],n);
    // REP(i,li) REP(j,lj) cout << i << ' ' << j << ' ' << cap[in(i, j)][out(i, j)] << endl;
    // REP(i,li) REP(j,lj) cout << i << ' ' << j << ' ' << cap[out(i, j)][snk] << endl;

    //REP(i,li) REP(j,lj) cout << i << ' ' << j << ' ' << in(i,j) << ' ' << out(i,j) << endl;

    int result = Dinic(n, src, snk);
    if (result >= inf) cout << -1 << endl;
    else cout << result << endl;

    // cout << "#cnt = " << cnt << endl;
  }
}
