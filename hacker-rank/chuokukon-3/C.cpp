#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <numeric>
#include <set>
#include <queue>

#define REP(i,n) for (int i = 0; i < (int)(n); ++i)

const int DI[] = { -1, 0, 1, 0 };
const int DJ[] = { 0, 1, 0, -1 };

using namespace std;

struct pt {
  int i, j;
  bool operator<(const pt &o) const {
    if (i != o.i) return i < o.i;
    return j < o.j;
  }
};

set<pt> BFS(int si, int sj, const vector<pt> &v) {
  set<pt> vset(v.begin(), v.end());
  set<pt> result;
  queue<pt> qu;
  const int limit = 100000;
  for (qu.push((pt) { si, sj }); qu.size(); qu.pop()) {
    if (result.size() > limit) { return set<pt>(); }
    
    pt p = qu.front();
    if (vset.count(p)) continue;
    if (result.count(p)) continue;
    result.insert(p);

    REP(i,4) qu.push((pt) { p.i + DI[i], p.j + DJ[i] });
  }
  return result;
}

int main() {
  int si, sj, di, dj;
  while (cin >> si >> sj >> di >> dj) {
    int n; cin >> n;
    vector<pt> v(n);
    REP(i,n) cin >> v[i].i >> v[i].j;

    auto spt = BFS(si, sj, v);
    auto dpt = BFS(di, dj, v);

    if (spt.empty() && dpt.empty()) cout << "Yes" << endl;
    else if (spt.count((pt) { di, dj} )) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}
