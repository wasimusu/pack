#include <bits/stdc++.h>
#include "../src/pack.cpp"

using namespace std;

int main() {
  vector<BoundingBox> rects;
  for (int i = 0; i < 4; i++) {
    rects.emplace_back(BoundingBox(10, 10, 10, 10));
  }

  int estimated_width = 40, estimated_height = 10;
  pack_rectangles(rects, std::ref(estimated_height), std::ref(estimated_width));

  std::cout << "\nPacking squares in a horizontal grid " << endl;
  for (int i = 0; i < rects.size(); i++) {
    std::cout << rects[i].index_r << ", " << rects[i].index_c << std::endl;
  }

  return 0;
}
