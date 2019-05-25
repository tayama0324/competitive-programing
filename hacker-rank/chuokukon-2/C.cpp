#include <iostream>
#include <string>
#include <algorithm>

#define REP(i,n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

int main() {
  int n;
  while (cin >> n) {
    int result = 2;
    for (int i = 2; i * i <= n; ++i) {
      while (n % i == 0) {
        n /= i;
        result = i;
      }
    }
    cout << max(result, n) << endl;
  }
}
