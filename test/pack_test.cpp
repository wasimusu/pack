#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "../src/pack.cpp"

using namespace std;

TEST(simple_test, square_grid) {

    vector<BoundingBox> rects;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            rects.emplace_back(BoundingBox(10, 10, 10, 10));
        }
    }
    pack_rectangles(rects, 40, 40);
    std::sort(rects.begin(), rects.end(), [](const BoundingBox &first, const BoundingBox &second) {
        return first.index_r == second.index_r ? first.index_c >= second.index_c : first.index_r > second.index_r;
    });

    std::cout << "\nPacking squares in a square grid " << endl;
    for (int i = 0; i < rects.size(); i++) {
        std::cout << rects[i].index_r << ", " << rects[i].index_c << std::endl;
    }
}

TEST(simple_test, rectangle_grid_horizontal) {
    vector<BoundingBox> rects;
    for (int i = 0; i < 4; i++) {
        rects.emplace_back(BoundingBox(10, 10, 10, 10));
    }
    pack_rectangles(rects, 10, 40);

    std::cout << "\nPacking squares in a horizontal grid " << endl;
    for (int i = 0; i < rects.size(); i++) {
        std::cout << rects[i].index_r << ", " << rects[i].index_c << std::endl;
    }
}

TEST(simple_test, rectangle_grid_vertical) {
    vector<BoundingBox> rects;
    for (int i = 0; i < 4; i++) {
        rects.emplace_back(BoundingBox(10, 10, 10, 10));
    }
    pack_rectangles(rects, 40, 10);
    std::cout << "\nPacking squares in a vertical grid " << endl;
    for (int i = 0; i < rects.size(); i++) {
        std::cout << rects[i].index_r << ", " << rects[i].index_c << std::endl;
    }
}