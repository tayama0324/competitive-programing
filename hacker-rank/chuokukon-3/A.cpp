#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>

#define REP(i,n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

int main() {
  int n, m;
  while (cin >> n >> m) {
    vector<string> v(n);
    REP(i,n) cin >> v[i];
    int si, sj, gi, gj;
    REP(i,n) REP(j,m) {
      if (v[i][j] == 'S') { si = i, sj = j; }
      if (v[i][j] == 'G') { gi = i, gj = j; }
    }
    cout << abs(si - gi) + abs(sj - gj) << endl;
  }
}
