#include <iostream>
#include <string>
#include <algorithm>

#define REP(i,n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

int main() {
  int n; string s;
  cin >> n >> s;
  cout << n - count(s.begin(), s.end(), 'A') << endl;
}
