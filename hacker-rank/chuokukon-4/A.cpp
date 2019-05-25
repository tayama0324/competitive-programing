#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <numeric>
#include <set>
#include <queue>
#include <map>

#define REP(i,n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i,b,e) for (int i = (b); i < (int)(e); ++i)

const int DI[] = { -1, 0, 1, 0 };
const int DJ[] = { 0, 1, 0, -1 };

using namespace std;

int main() {
  vector<string> v;
  REP(i,26) v.push_back(string("") + (char)('a' + i) + "lang"); 
  REP(i,26) REP(j,26) v.push_back(string("")+ (char)('a' + i) + (char)('a' + j) + "lang");
  sort(v.begin(), v.end());
  int n;
  cin >> n;
  cout << v[n-1] << endl;
}
