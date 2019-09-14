#include <iostream>
#include <vector>

#define REP(i,n) for (int i = 0; i < (n); ++i)

using namespace std;

typedef vector<int> vint;

int main() {
  int n;
  while (cin >> n) {
    int result = 0;
    if (65 <= n && n <= 90) result = 1;
    else if (97 <= n && n <= 122) result = 2;
    cout << result << endl;
  }
}
