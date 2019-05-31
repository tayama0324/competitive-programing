#include <iostream>

using namespace std;

int main() {
  long long n;
  while (cin >> n) {
    long long result = (n / 11) * 2;
    n %= 11;
    if (n > 0) result += 1;
    if (n > 6) result += 1;
    cout << result << endl;
  }
}
