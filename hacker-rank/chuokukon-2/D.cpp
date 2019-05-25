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
    vector< pair<int,int> > v(m);
    REP(i,m) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());

    int coverable = 0, covered = 0, result = 0;
    REP(i,m) {
      if (v[i].first > covered + 1) {
        if (coverable >= v[i].first - 1) {
          result++;
          covered = coverable;
        } else {
          result = -1;
          break;
        }
      }
      coverable = v[i].second;
    }
    if (covered < n) {
      if (coverable >= n) result++; else result = -1;
    }
    cout << result << endl;
  }
}
