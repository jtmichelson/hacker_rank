#include <bits/stdc++.h>

using namespace std;
	
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
                }

               return root;
           }
        }

/* You are given a pointer to the root of a binary tree. 
You need to print the level order traversal of this tree. 
In level order traversal, we visit the nodes level by level from left to right. */

    void levelOrder(Node * root) {
        std::queue<Node*> Q;
        Node* temp;
        if (root != nullptr) {
            Q.push(root);
        }
        while (!Q.empty()) {
            temp = Q.front();
            Q.pop();
            if (temp->left != nullptr) {
                Q.push(temp->left);
            }
            if (temp->right != nullptr) {
                Q.push(temp->right);
            }
            std::cout << temp->data << " ";
        }
    }

}; //End of Solution
