#include <iostream>

using namespace std;

int main() {
  string s;
  while (cin >> s) {
    int a = s.length(), z = 0;
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == 'A') a = min(a, i);
      if (s[i] == 'Z') z = max(z, i);
    }
    cout << z - a + 1 << endl;
  }
}
