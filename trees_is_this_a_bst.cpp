/* Hidden stub code will pass a root argument to the function below. 
Complete the function to solve the challenge. 

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/

#include<climits>
bool checkBST(Node* root) {
    return checkBSTUtil(root, INT_MIN, INT_MAX);
}
bool checkBSTUtil(Node* root, int minVal, int maxVal) {
    if (root == nullptr) {
        return true;
    }
    else if (root->data < maxVal
            && root->data > minVal
            && checkBSTUtil(root->left, minVal, root->data)
            && checkBSTUtil(root->right, root->data, maxVal)) {
        return true;
    }
    else {
        return false;
    }
}
