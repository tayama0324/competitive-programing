#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <numeric>

#define REP(i,n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

int main() {
  vector<string> v(3);
  REP(i,3) cin >> v[i];
  sort(v.begin(), v.end());

  string result = accumulate(v.begin(), v.end(), string(""));
  do {
    string s = accumulate(v.begin(), v.end(), string(""));
    result = min(result, s);
  } while (next_permutation(v.begin(), v.end()));
  
  cout << result << endl;
}
