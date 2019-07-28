/*
 * Author: Y.W. Chen
 * Date: Sep 10th, 2017
 */

//binary tree height
int height(Node* root) 
{
    if(!root){
        return 0;
    }
    int height_Left=0, height_Right=0;
    if(root->left){
        height_Left = 1 + height(root->left);
    }
    if(root->right){
        height_Right = 1 + height(root->right);
    }
    return (height_Left > height_Right)? height_Left : height_Right;
}

//binary tree size
int size(Node* root)
{
    if(!root){
        return 0;
    }
    return size(root->left) + 1 + size(root->right);
}
