#include <iostream>
#include <vector>

#define REP(i,n) for (int i = 0; i < (n); ++i)
#define ALL(c) (c).begin(), (c).end()

using namespace std;

typedef vector<int> vint;

int main() {
  int li, lj;
  while (cin >> li >> lj && li | lj) {
    vector<string> v(li);
    REP(i,li) cin >> v[i];
    vector<pair<int,int>> ps(256);
    REP(i,li) REP(j,lj) {
      if (v[i][j] != '_') ps[v[i][j]] = make_pair(i, j);
    }

    string s; cin >> s;
    int result = ps[s[0]].first + ps[s[0]].second + 1;
    REP(i,s.length()-1) {
      int pi = ps[s[i]].first, pj = ps[s[i]].second;
      int ni = ps[s[i+1]].first, nj = ps[s[i+1]].second;
      // cout << s[i] << ' ' << s[i+1] << pi << ' ' << pj << ' ' << ni << ' ' << nj << endl;
      result += abs(pi - ni) + abs(pj - nj) + 1;
    }
    cout << result << endl;
  }
}
