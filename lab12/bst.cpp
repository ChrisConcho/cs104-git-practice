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
        
        if (root->left == nullptr || bsthelper(root->left,root,1)){
            flag += 1;
        }
        else{
            return false;
        }
    }
    else if (isBST(root->right)){
        if(root->right == nullptr ||bsthelper(root->right,root,0)){
            flag += 1;
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
bool bsthelper(Node* check,Node* root, int x){
    if (check == nullptr){
        return true;
    }
    else if (x ==1){
        if ( check->key < root->key){
            if (bsthelper(check->left, root, 1) && bsthelper(check->right, root, 1)){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    else{
        if( check->key > root->key){
            if(bsthelper(check->right,root, 0) && bsthelper(check->left,root,0)){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
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
