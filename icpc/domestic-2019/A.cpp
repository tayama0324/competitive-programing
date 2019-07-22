#include <iostream>
#include <vector>

#define REP(i,n) for (int i = 0; i < (n); ++i)
#define ALL(c) (c).begin(), (c).end()

using namespace std;

typedef vector<int> vint;

int main() {
  int n, m;
  while (cin >> n >> m && n|m) {
    vint sum(n);
    REP(i,m) REP(j,n) {
      int t; cin >> t; sum[j] += t;
    }
    cout << *max_element(ALL(sum)) << endl;
  }
}
