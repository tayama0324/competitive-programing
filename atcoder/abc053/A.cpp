#include <iostream>

using namespace std;

int main() {
  int x;
  while (cin >> x) {
    if (x < 1200) cout << "ABC" << endl;
    else cout << "ARC" << endl;
  }
}
