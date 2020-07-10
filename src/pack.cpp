#include <iostream>
#include "pack.h"

/**
 * @brief computes if input rectangle fits inside the canvas rectangle
 * @returns returns boolean value indicating if the input rectangle fits inside canvas rectangle
 * */
bool fits(BoundingBox &canvas, BoundingBox &input_rect) {
  return ((canvas.rowmax - canvas.rowmin) >= (input_rect.rowmax - input_rect.rowmin) &&
      (canvas.colmax - canvas.colmin) >= (input_rect.colmax - input_rect.colmin));
}

/**
 * @brief split the canvas into two other smaller canvas after placing input rectangle at the top right corner of the canvas
 * @param canvas the rectangle inside which we are placing input rectangle
 * @param [out] output_rect1, output_rect2 the resulting rectangles after placing input rectangle into canvas
 * */
void split(BoundingBox &canvas, BoundingBox &input, BoundingBox &output_rect1, BoundingBox &output_rect2) {
  output_rect1 = BoundingBox(canvas.rowmin, canvas.colmin + input.width, input.height, canvas.width - input.width);
  output_rect2 = BoundingBox(canvas.rowmin + input.height, canvas.colmin, canvas.height - input.height, canvas.width);
}

// Insert items into a tree using DFS
void insert(TreeNode *root, BoundingBox &item) {

  std::vector<TreeNode *> stack = {root};
  while (!stack.empty()) {
    auto root = stack.back();
    stack.pop_back();

    if (!root) continue;

    if (fits(root->value, item)) {

      // Insert if leaf
      if (!root->left && !root->right) {
        BoundingBox output1, output2;
        split(root->value, item, output1, output2);
        root->right = new TreeNode(output1);
        root->left = new TreeNode(output2);

        // Assigning position to the rectangle in the canvas
        item.index_r = root->value.rowmin;
        item.index_c = root->value.colmin;

        return;
      }

      // Add the node's child to the stack
      stack.push_back(root->left);
      stack.push_back(root->right);
    }
  }

}

/**
 * @brief Packs all the rectangles into a bigger rectangle (canvas). The estimated height and width of the canvas will
 * grow if required.
 * @param bBox vector of rectangles
 * @param height estimate for height of the canvas
 * @param width estimate for the width of the canvas
 * @returns the input height and width are manipulated to reflect the actual height and width of the canvas after packing rectangle
 * */
void pack_rectangles(std::vector<BoundingBox> &bBox, int &height, int &width) {
  // TODO: Determine the height and width of the canvas yourself

  BoundingBox canvas(0, 0, height, width);
  TreeNode *root = new TreeNode(canvas);

  int max_width = 0, max_height = 0;
  for (auto &box : bBox) {
    insert(root, box);
    max_width = std::max(max_width, box.index_c + box.width);
    max_height = std::max(max_height, box.index_r + box.height);
  }

  // Equivalent of cropping the canvas. All the input rectangles fit inside the canvas of this size
  height = max_height;
  width = max_width;
}
