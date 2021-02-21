/*
This problem was asked by Google.

Implement locking in a binary tree.
A binary tree node can be locked or unlocked only if all of its descendants or ancestors are not locked.

Design a binary tree node class with the following methods:

> is_locked, which returns whether the node is locked

> lock, which attempts to lock the node. If it cannot be locked, then it should return false. 
  Otherwise, it should lock it and return true.

> unlock, which unlocks the node. If it cannot be unlocked, then it should return false. 
  Otherwise, it should unlock it and return true.

You may augment the node to add parent pointers or any other property you would like. 
You may assume the class is used in a single-threaded program, so there is no need for actual locks or mutexes. 
Each method should run in O(h), where h is the height of the tree.
*/

#include <iostream>
using namespace std;

class TreeNode {
private:
    bool _has_locked_descendants(TreeNode* node) {
        if (node == nullptr) {
            return false;
        }
        return node->locked || _has_locked_descendants(node->left) || _has_locked_descendants(node->right);
    }

    bool _has_locked_ancestors(TreeNode* node) {
        TreeNode* iter = node->parent;
        while (iter) {
            if (iter->locked) {
                return true;
            }
            iter = iter->parent;
        }
        return false;
    }

public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    bool locked;
    
    TreeNode(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
        locked = false;
    }

    bool is_locked() {
        return locked;
    }

    bool lock() {
        if (_has_locked_descendants(this) || _has_locked_ancestors(this)) {
            return false;
        }
        locked = true;
        return true;
    }

    bool unlock() {
        if (_has_locked_descendants(this) || _has_locked_ancestors(this)) {
            return false;
        }
        locked = false;
        return true;
    }
};

class TreeNode2 {
private:
    void _set_has_locked_ancestors(TreeNode2* node, bool val) {
        if (node == nullptr) {
            return;
        }
        node->has_locked_ancestors = val;
        _set_has_locked_ancestors(node->left, val);
        _set_has_locked_ancestors(node->right, val);
    }

    void _set_has_locked_descendants(TreeNode2* node, bool val) {
        while (node) {
            node->has_locked_descendants = val;
            node = node->parent;
        }
    }

public:
    int data;
    TreeNode2* left;
    TreeNode2* right;
    TreeNode2* parent;
    bool locked;
    bool has_locked_descendants;
    bool has_locked_ancestors;

    TreeNode2(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
        locked = false;
        has_locked_descendants = false;
        has_locked_ancestors = false;
    }

    bool is_locked() {
        return locked;
    }

    bool lock() {
        if (this->has_locked_descendants || this->has_locked_ancestors) {
            return false;
        }
        locked = true;
        _set_has_locked_descendants(this->parent, true);
        _set_has_locked_ancestors(this->left, true);
        _set_has_locked_ancestors(this->right, true);
        return true;
    }

    bool unlock() {
        if (this->has_locked_descendants) {
            return false;
        }
        locked = false;
        _set_has_locked_descendants(this->parent, false);
        _set_has_locked_ancestors(this->left, false);
        _set_has_locked_ancestors(this->right, false);
        return true;
    }
};