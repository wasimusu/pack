#pragma once
#ifndef _BOUNDINGBOX_H
#define _BOUNDINGBOX_H

#include <vector>

struct BoundingBox {
  std::vector<int> TriangleIndex;

  int rowmin;
  int rowmax;
  int colmin;
  int colmax;

  int width;
  int height;

  float ocuupancy_percent = 0;

  // Position of the bounding box after inside the canvas after packing
  int index_r = -1;
  int index_c = -1;

  BoundingBox() :
      rowmin(0),
      colmin(0),
      rowmax(0),
      colmax(0),
      height(0),
      width(0) {}

  BoundingBox(int pos_r, int pos_c, int row_min, int row_max, int col_min, int col_max) :
      rowmin(pos_r),
      colmin(pos_c),
      rowmax(row_max),
      colmax(col_max),
      height(row_max - row_min),
      width(col_max - col_min) {}

  BoundingBox(int pos_r, int pos_c, int height, int width) :
      rowmin(pos_r),
      colmin(pos_c),
      rowmax(pos_r + height),
      colmax(pos_c + width),
      height(height),
      width(width) {}

  void compute_dim() {
    this->height = rowmax - rowmin;
    this->width = colmax - colmin;
  }
};

#endif

