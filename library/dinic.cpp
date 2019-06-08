const int inf = 1 << 29;

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
