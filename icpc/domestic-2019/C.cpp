#include <iostream>
#include <vector>
#include <set>

#define REP(i,n) for (int i = 0; i < (int)(n); ++i)
#define ALL(c) (c).begin(), (c).end()

using namespace std;

typedef vector<int> vint;

void DFS(const vint &w, int a, vint &v, int depth, set<int> &result) {
  if (depth == (int)v.size()) {
    // cout << "v: "; REP(i,v.size()) cout << v[i] << ' ' ; cout << endl;
    int sum = 0;
    REP(i,v.size()) sum += w[i] * v[i];
    int candidate = abs(a - sum);
    result.insert(candidate);
    return;
  }
  v[depth] = -1; DFS(w, a, v, depth+1, result);
  v[depth] =  0; DFS(w, a, v, depth+1, result);
  v[depth] =  1; DFS(w, a, v, depth+1, result);
}

set<int> intersect(const set<int> &a, const set<int> &b) {
  set<int> result;
  for (auto &e : a) if (b.count(e)) result.insert(e);
  return result;
}

int main() {
  int n, m;
  while (cin >> n >> m && n | m) {
    vint a(n);
    REP(i,n) cin >> a[i];
    vint w(m);
    REP(i,m) cin >> w[i];
    vint v(m);

    set<int> result;
    result.insert(0);
    REP(i,n) {
      set<int> st;
      DFS(w, a[i], v, 0, st);
      // cout << "candidates for " << a[i] << ": ";
      // for (auto &e: st) cout << e << ' ' ; cout << endl;
      if (result.count(0)) {
        if (st.count(0)) result = intersect(result, st);
        else result = st;
      } else {
        if (st.count(0)) { ; }
        else result = intersect(result, st);
      }
    }
    if (result.size() == 0) {
      cout << -1 << endl;
    } else {
      cout << *result.begin() << endl;
    }
  }
}
