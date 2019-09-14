#include <iostream>
#include <vector>

#define REP(i,n) for (int i = 0; i < (n); ++i)

using namespace std;

typedef vector<int> vint;
typedef long long ll;

int DI[] = { 0, -1, 0, 1 };
int DJ[] = { 1, 0, -1, 0 };

int main() {
  int x, y;
  while (cin >> x >> y) {
    vint lens(1, 1);
    int sx = 1, sy = 1, cx = 0, cy = 0;
    REP(i,100) {
      // cout << "# " << i << ' ' << cx << ' ' << cy << ' ' << sx << ' ' << sy << endl;

      if (cx <= x && x < cx + sx && cy <= y && y < cy + sy) {
        cout << i % 3 + 1 << endl;
        break;
      }

      int len = (lens.size() < 2 ? 1 : lens[lens.size() - 1] + lens[lens.size() - 2]);
      lens.push_back(len);
      if (i % 4 == 0) {
        sx += len;
      } else if (i % 4 == 1) {
        sy += len;
      } else if (i % 4 == 2) {
        cx -= len;
        sx += len;
      } else {
        sy += len;
        cy -= len;
      }
    }
  }
}
