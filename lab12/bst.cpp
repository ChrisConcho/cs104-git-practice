#include "bst.h"

#include <stack>
#include <queue>
#include <set>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <climits>

using namespace std;

//Helper functions?
bool isBST(Node *root) {
    int flag = 0;
    if ( root == nullptr){
        return true;
    }
    else if (isBST(root->left)){
        
        if (root->left == nullptr || root->left->key < root->key){
            if ( root->left-left == nullptr ||root->left->left->key){
                if ( root->left->right == nullptr || root->left->right->key < root->key){
                        flag += 1;
                }
            }
        }
        else{
            return false;
            }
    }
    else if (isBST(root->right)){
        if(root->right == nullptr || root->right->key > root->key){
            if ( root->right-left == nullptr ||root->right->left->key){
                if ( root->right->right == nullptr || root->right->right->key > root->key){
                        flag += 1;
                }
            }
        }
        else{
            return false;
        }
    }
    if ( flag == 2){
        return true;
    }
    return false;
}
    
//Helper functions?
bool isBalanced(Node *root) {
    if ( helper(root,1) == -1){
        return false;
    }
    else{
        return true;
    }
}

int helper(Node* check, int x){
    if ( check == nullptr){
        return x;
    }
    else{
        int left = helper(check->left, x+1);
        int right = helper(check->right, x+1);
        if ( left == -1 || right == -1){
            return -1;
        }
        else if ( left - right >= 1 || left-right< -1){
            return -1;
        }
        else{
            if ( left>right){
                return left;
            }
            else{
                return right;
            }
        }
    }
}
