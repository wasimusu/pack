#pragma once
#ifndef _PACKER_H
#define _PACKER_H

#include "boundingBox.h"

struct TreeNode {
    BoundingBox value;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode(BoundingBox item) : value(item) {};
};

/**
 * Returns bool value indicating whether input_rect fits inside destination rectangle.
 */
bool fits(BoundingBox &canvas, BoundingBox &input_rect);

void split(BoundingBox &canvas, BoundingBox &input, BoundingBox &output_rect1, BoundingBox &output_rect2);

// Insert items into a tree using DFS
void insert(TreeNode *root, BoundingBox &item);

// Pack rectangles into a canvas
void pack_rectangles(std::vector<BoundingBox> &bBox, int& height, int& width);

#endif