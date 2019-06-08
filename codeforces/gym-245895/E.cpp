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
class Dinic {
  struct Edge { int dst, cap, net, rev; };
  vector<vector<Edge>> v;
  vector<vector<Edge*>> u;
  vector<vector<Edge*>::iterator> w;
  const int n, src, snk;

  int DFS(int p, int f){
    if(!f || p == snk) return f;
    for (auto &it = w[p]; it != u[p].end(); ++it) {
      if(int t = DFS((*it)->dst, min(f,(*it)->cap))){
        (*it)->cap -= t; v[(*it)->dst][(*it)->rev].cap += t;
        (*it)->net += t; v[(*it)->dst][(*it)->rev].net -= t;
        return t;
      }
    }
    return 0;
  }
  
public:
  int maxFlow() {
    int ans = 0, a, b;
    while(true){
      vector<int> l(n, inf), qu(n + n);
      for(a = 0, b = 1, qu[a] = src, l[src] = 0; b-a; a++) {
        for (auto &e: v[qu[a]]) {
          if (e.cap && l[e.dst] == inf) { l[e.dst] = l[qu[a]] + 1; qu[b++] = e.dst; }
        }
      }
      if(l[snk] == inf) break;
      REP(i,n){
        u[i].clear();
        for (auto &e: v[i]) if (l[i] + 1 == l[e.dst]) u[i].push_back(&e);
        w[i] = u[i].begin();
      }
      while (int f = DFS(src, inf)) ans += f;
    }
    return ans;
  }

  Dinic(int n_, int src_, int snk_) : v(n_), u(n_), w(n_), n(n_), src(src_), snk(snk_) {}
  void add(int src, int dst, int a, int b){
    v[src].push_back((Edge){ dst, a, 0, (int) v[dst].size() });
    v[dst].push_back((Edge){ src, b, 0, (int) v[src].size() - 1 });
  }
};

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
    int src; REP(i,li) REP(j,lj) if (s[i][j] == 'B') src = in(i, j);
    Dinic dinic(n, src, snk);
    
    REP(i,li) REP(j,lj) {
      bool boundary = false;
      REP(d,4) {
        int ni = i + DI[d], nj = j + DJ[d];
        if (0 <= ni && ni < li && 0 <= nj && nj < lj) {
          dinic.add(out(i, j), in(ni, nj), inf, 0);
        } else {
          boundary = true;
        }
      }
      if (boundary) dinic.add(out(i, j), snk, inf, 0);

      int w;
      if ('a' <= s[i][j] && s[i][j] <= 'z') w = cs[s[i][j] - 'a'];
      else w = inf;
      
      dinic.add(in(i, j), out(i, j), w, 0);

      if (s[i][j] == 'B') src = in(i, j);
    }

    
    // REP(i,n) pp(cap[i],n);
    // REP(i,li) REP(j,lj) cout << i << ' ' << j << ' ' << cap[in(i, j)][out(i, j)] << endl;
    // REP(i,li) REP(j,lj) cout << i << ' ' << j << ' ' << cap[out(i, j)][snk] << endl;

    //REP(i,li) REP(j,lj) cout << i << ' ' << j << ' ' << in(i,j) << ' ' << out(i,j) << endl;

    int result = dinic.maxFlow();
    if (result >= inf) cout << -1 << endl;
    else cout << result << endl;

    // cout << "#cnt = " << cnt << endl;
  }
}
