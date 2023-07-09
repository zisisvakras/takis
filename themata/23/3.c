#include <stdlib.h>
typedef struct Treenode* Treeptr;

struct Treenode {
    int value;
    Treeptr right;
    Treeptr left;
};

int pathssum(Treeptr root, int sum) {
    if (!root) return sum == 0;
    sum -= root->value;
    if (!root->left && !root->right) return sum == 0;
    if (!root->left) return pathssum(root->right, sum);
    if (!root->right) return pathssum(root->left, sum);
    return pathssum(root->right, sum) + pathssum(root->left, sum);
}