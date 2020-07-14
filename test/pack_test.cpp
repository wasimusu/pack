#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "../src/pack.cpp"

using namespace std;

/**
 * @brief just tests if all the rects are assigned unique position of not.
 * @warning also check if they are within the bounds of allowed width range and height range.
 * */
bool all_positions_occupied(std::vector<BoundingBox> &rects) {
  std::set<std::pair<int, int>> positions;

  for (const auto &rect:rects) {
    std::cout << rect.index_c << ", " << rect.index_r << std::endl;
    positions.insert({rect.index_r, rect.index_c});
  }

  return rects.size() == positions.size();
}

TEST(simple_test, square_grid) {

  vector<BoundingBox> rects;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      rects.emplace_back(BoundingBox(10, 10, 10, 10));
    }
  }

  int estimated_width = 40, estimated_height = 40;
  pack_rectangles(rects, std::ref(estimated_height), std::ref(estimated_width));

  std::cout << "\nPacking squares in a square grid " << endl;
  EXPECT_EQ(all_positions_occupied(rects), true);
}

TEST(simple_test, rectangle_grid_horizontal) {
  vector<BoundingBox> rects;
  for (int i = 0; i < 4; i++) {
    rects.emplace_back(BoundingBox(10, 10, 10, 10));
  }

  int estimated_width = 40, estimated_height = 10;
  pack_rectangles(rects, std::ref(estimated_height), std::ref(estimated_width));

  std::cout << "\nPacking squares in a horizontal grid " << endl;
  EXPECT_EQ(all_positions_occupied(rects), true);
}

TEST(simple_test, rectangle_grid_vertical) {
  vector<BoundingBox> rects;
  for (int i = 0; i < 4; i++) {
    rects.emplace_back(BoundingBox(10, 10, 10, 10));
  }

  int estimated_width = 10, estimated_height = 40;
  pack_rectangles(rects, std::ref(estimated_height), std::ref(estimated_width));

  std::cout << "\nPacking squares in a vertical grid " << endl;
  EXPECT_EQ(all_positions_occupied(rects), true);
}

TEST(mixed_squares, one_quad_small) {
  vector<BoundingBox> rects;
  const int BIG_SQ_SIDE = 8;
  for (int i = 0; i < 3; i++) {
    rects.emplace_back(BoundingBox(i, i, BIG_SQ_SIDE, BIG_SQ_SIDE));
  }
  for (int i = 0; i < 4; i++) {
    rects.emplace_back(BoundingBox(i, i, BIG_SQ_SIDE / 2, BIG_SQ_SIDE / 2));
  }

  int estimated_width = BIG_SQ_SIDE * 2, estimated_height = BIG_SQ_SIDE * 2;
  pack_rectangles(rects, std::ref(estimated_height), std::ref(estimated_width));

  std::cout << "\nPacking mixed squares. One quad of small squares." << endl;
  EXPECT_EQ(all_positions_occupied(rects), true);
}

TEST(mixed_squares, two_quad_small) {
  vector<BoundingBox> rects;
  const int BIG_SQ_SIDE = 8;
  for (int i = 0; i < 2; i++) {
    rects.emplace_back(BoundingBox(i, i, BIG_SQ_SIDE, BIG_SQ_SIDE));
  }
  for (int i = 0; i < 8; i++) {
    rects.emplace_back(BoundingBox(i, i, BIG_SQ_SIDE / 2, BIG_SQ_SIDE / 2));
  }

  int estimated_width = BIG_SQ_SIDE * 2, estimated_height = BIG_SQ_SIDE * 2;
  pack_rectangles(rects, std::ref(estimated_height), std::ref(estimated_width));

  std::cout << "\nPacking mixed squares. One quad of small squares." << endl;
  EXPECT_EQ(all_positions_occupied(rects), true);
}

TEST(mixed_squares, three_quad_small) {
  vector<BoundingBox> rects;
  const int BIG_SQ_SIDE = 8;
  for (int i = 0; i < 1; i++) {
    rects.emplace_back(BoundingBox(i, i, BIG_SQ_SIDE, BIG_SQ_SIDE));
  }
  for (int i = 0; i < 12; i++) {
    rects.emplace_back(BoundingBox(i, i, BIG_SQ_SIDE / 2, BIG_SQ_SIDE / 2));
  }

  int estimated_width = BIG_SQ_SIDE * 2, estimated_height = BIG_SQ_SIDE * 2;
  pack_rectangles(rects, std::ref(estimated_height), std::ref(estimated_width));

  std::cout << "\nPacking mixed squares. One quad of small squares." << endl;
  EXPECT_EQ(all_positions_occupied(rects), true);
}


TEST(brick, unique_pairs) {
  vector<BoundingBox> rects;

  const int BIG_SQ_SIDE = 20;
  rects.emplace_back(BoundingBox(0, 0, 2, 10));
  rects.emplace_back(BoundingBox(0, 0, 2, 10));

  rects.emplace_back(BoundingBox(0, 0, 2, 8));
  rects.emplace_back(BoundingBox(0, 0, 2, 12));

  rects.emplace_back(BoundingBox(0, 0, 2, 6));
  rects.emplace_back(BoundingBox(0, 0, 2, 14));

  rects.emplace_back(BoundingBox(0, 0, 2, 7));
  rects.emplace_back(BoundingBox(0, 0, 2, 13));

  std::sort(rects.begin(), rects.end(), [](const BoundingBox &first, const BoundingBox &second) {
    return first.width < second.width;
  });

  int estimated_width = BIG_SQ_SIDE, estimated_height = 4 * 2;
  pack_rectangles(rects, std::ref(estimated_height), std::ref(estimated_width));

  std::cout << "\nPacking bricks. Mixed width rectangles." << endl;
  EXPECT_EQ(all_positions_occupied(rects), true);
}
