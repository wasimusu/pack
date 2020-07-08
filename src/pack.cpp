#include <iostream>
#include "pack.h"

/**
*  Returns bool value indicating whether input_rect fits inside destination rectangle.

*/
bool fits(BoundingBox &canvas, BoundingBox &input_rect) {
    return ((canvas.rowmax - canvas.rowmin) >= (input_rect.rowmax - input_rect.rowmin) &&
            (canvas.colmax - canvas.colmin) >= (input_rect.colmax - input_rect.colmin));
}

void split(BoundingBox &canvas, BoundingBox &input, BoundingBox &output_rect1, BoundingBox &output_rect2) {
    output_rect1 = BoundingBox(canvas.rowmin, canvas.colmin + input.width, input.height, canvas.width - input.width);
    output_rect2 = BoundingBox(canvas.rowmin + input.height, canvas.colmin, canvas.height - input.height, canvas.width);
}


// Insert items into a tree using DFS
void insert(TreeNode *root, BoundingBox &item) {

    // TODO: Ideally this function should not know what the default values are for index_c && index_r
    if (item.index_c != -1 && item.index_r != -1)
        return;

    if (fits(root->value, item)) {

        // Insert if leaf
        if (!root->left && !root->right) {
            BoundingBox output1, output2;
            split(root->value, item, output1, output2);
            root->left = new TreeNode(output1);
            root->right = new TreeNode(output2);

            // Packing output
            item.index_r = root->value.rowmin;
            item.index_c = root->value.colmin;

            return;
        }

        // Explore downward the tree otherwise
        insert(root->left, item);
        insert(root->right, item);
    }

    // TODO: Increase the canvas size
}

void pack_rectangles(std::vector<BoundingBox> &bBox, int height = 100, int width = 100) {
    // TODO: Determine the height and width of the canvas yourself

    BoundingBox canvas(0, 0, height, width);
    TreeNode *root = new TreeNode(canvas);

    for (auto &box : bBox) {
        insert(root, box);
    }
}
