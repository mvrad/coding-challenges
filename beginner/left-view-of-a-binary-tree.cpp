/*
 * Print Left View of a Binary Tree
 * 
 * Given a binary tree, write an efficient algorithm to print its left view.
 * 
 *              _____1_____
 *            /            \
 *          2              3
 *        /   \          /   \
 *      4     NULL     5      6
 *    / \            / \     / \
 * NULL NULL       7  NULL NULL 8
 *               / \           / \
 *            NULL NULL     NULL NULL
 *
 * Output: 1, 2, 4, 7
 */

// 1. Iterative Implementation (BFS)
// Complexity | Time: Linear O(n), Space: Requires O(n) extra space

/*
 * In the iterative version of the solution, perform a level order traversal (a kind of
 * Breadth-First Search, BFS) on the tree. Level order traversal can be modified to
 * maintain nodes at the current level. Basically, if the current node is the first
 * node at the current level, print it.
 */

#include <iostream>
#include <list>

using namespace std;

// Store a binary tree node in a data structure
struct Node
{
  int data;
  Node *left, *right;
  // Initialize the binary tree by first creating the root node and two null nodes
  Node (int data)
  {
    this->data = data;
    this->left = this->right = nullptr;
  }
};

// Iterative function to print the left view of a binary tree
void leftView(Node* root)
{
  // Return if the tree is empty
  if (root == nullptr) {
    return;
  }
  // Create an empty queue and enqueue the root node
  list<Node*> queue;
  queue.push_back(root);
  // Pointer to store the current node
  Node* curr = nullptr;
  // Loop until queue is empty
  while (!queue.empty())
  {
    // Calculate the total number of nodes at the current level
    int size = queue.size(), i = 0;
    // Process every node of the current level and enqueue their non-empty left and
    // right child
    while (i++ < size)
    {
      curr = queue.front();
      queue.pop_front();
      // If this is the first node of the current level, print it
      if (i == 1)
      {
        cout << curr->data << " " << endl;
      }
      if (curr->left)
      {
        queue.push_back(curr->left);
      }
      if (curr->right)
      {
        queue.push_back(curr->right);
      }
    }
  }
}

// 2. Recursive Implementation Using Preorder Traversal (DFS)
// Complexity | Time: Linear O(n), Space: Requires O(1) extra space

/*
 * This problem can also be solved in constant space and linear time. Once again, we are
 * traversing the tree in a pre-order traversal while maintaining the max level visited
 * so far. If the current level exceeds the max level, then the current node becomes the
 * first node of the current level, and is printed while updating the last level to the
 * current level.
 */

using namespace std;

// Recursive function to print the left view of a given binary tree
void leftView2(Node* root, int level, int &last_level)
{
  // Base case: empty tree
  if (root == nullptr) {
    return;
  }
  // If the current node is the first node of the current level
  if (last_level < level)
  {
    // Print the node's data
    cout << root->data << " " << endl;
    // Update the last level to the current level
    last_level = level;
  }
  // Recur for the left and right subtree by increasing the level by 1
  leftView2(root->left, level + 1, last_level);
  leftView2(root->right, level + 1, last_level);
}

// Function to print the left view of a given binary tree
void leftView2(Node* root)
{
  int last_level = 0;
  leftView2(root, 1, last_level);
}

// Driver to test functions

int main()
{
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->right->left = new Node(5);
  root->right->right = new Node(6);
  root->right->left->left = new Node(7);
  root->right->right->right = new Node(8);
  leftView2(root);
  return 0;
}