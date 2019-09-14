#include <iostream>
#include <vector>

#define REP(i,n) for (int i = 0; i < (n); ++i)

using namespace std;

typedef vector<int> vint;

int main() {
  int a, b, c, d;
  while (cin >> a >> b >> c >> d) {
    cout << a + b + c + d << endl;
  }
}
