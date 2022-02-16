#include "AABBTree.h"
#include "insert_box_into_box.h"
#include <limits>

AABBTree::AABBTree(
  const std::vector<std::shared_ptr<Object> > & objects,
  int a_depth): 
  depth(std::move(a_depth)), 
  num_leaves(objects.size())
{
  ////////////////////////////////////////////////////////////////////////////
  if (num_leaves == 1) {
    this->left = objects[0];
    this->right = nullptr;
    insert_box_into_box(this->left->box, this->box);

  } else if (num_leaves == 2) {
    this->left = objects[0];
    this->right = objects[1];
    insert_box_into_box(this->left->box, this->box);
    insert_box_into_box(this->right->box, this->box);

  } else {
    int longest_axis;
    double largest_difference = -std::numeric_limits<double>::infinity();
    double xyz_min = std::numeric_limits<double>::infinity();
    double xyz_max = -std::numeric_limits<double>::infinity();
    for (int i = 0; i < num_leaves; i++) {
      for (int j = 0; j < 3; j++) {
        if (objects[i]->box.min_corner[j] < xyz_min) {
          xyz_min = objects[i]->box.min_corner[j];
        }
        if (objects[i]->box.max_corner[j] > xyz_max) {
          xyz_max = objects[i]->box.max_corner[j];
        }
        if ((abs(xyz_max - xyz_min)) > largest_difference) {
          largest_difference = (abs(xyz_max - xyz_min));
          longest_axis = j;
        }
      }
    }

    std::vector<std::shared_ptr<Object> > objects_copy;
    objects_copy = objects;
    std::sort(objects_copy.begin()
              , objects_copy.end()
              , [longest_axis] (const std::shared_ptr<Object> &a, const std::shared_ptr<Object> &b)
              {
                return a->box.center()[longest_axis] < b->box.center()[longest_axis];
              });

    std::vector<std::shared_ptr<Object> > left_objects(objects_copy.begin(), objects_copy.begin() + (num_leaves / 2));
    std::vector<std::shared_ptr<Object> > right_objects(objects_copy.begin() + (num_leaves / 2), objects_copy.end());

    std::shared_ptr<AABBTree> left_subtree = std::make_shared<AABBTree>(left_objects, depth + 1);
    std::shared_ptr<AABBTree> right_subtree = std::make_shared<AABBTree>(right_objects, depth + 1);

    this->left = left_subtree;
    this->right = right_subtree;

    insert_box_into_box(this->left->box, this->box);
    insert_box_into_box(this->right->box, this->box);
  }
  
  ////////////////////////////////////////////////////////////////////////////
}
