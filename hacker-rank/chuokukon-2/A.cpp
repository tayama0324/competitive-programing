#include <iostream>

using namespace std;

int main() {
  int h, m;
  cin >> h >> m;
  int cnt = 0;
  while (h < 12) {
    m++;
    if (m == 60) { m = 0; ++h; }
    cnt++;
  }
  cout << cnt << endl;
}
