#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

long long int INT_MAX=1000000000000000;

// Definition for binary tree
struct TreeNode {
     long long val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* insertInBST(TreeNode* root, int x) {
	if (root == NULL) {
		TreeNode* tmp = new TreeNode(x);
	return tmp;
}

if (x < root->val) {
	root->left = insertInBST(root->left , x);
		return root;
	} else {
		root->right = insertInBST(root->right, x);
		return root;
	}
}

TreeNode* createBST() {
	TreeNode* root = NULL;
	int x;
	cin >> x;

	//Take input until user inputs -1
	while (true) {
		if (x == -1) break;
		root = insertInBST(root, x);
		cin >> x;
	}
	return root;
}

/* This function traverse the skewed binary tree and
   stores its nodes pointers in vector nodes[] */
void storeBSTNodes(TreeNode* root, vector<TreeNode*> &nodes)
{
    // Base case
    if (root==NULL)
        return;
 
    // Store nodes in Inorder (which is sorted
    // order for BST)
    storeBSTNodes(root->left, nodes);
    nodes.push_back(root);
    storeBSTNodes(root->right, nodes);
}
 
/* Recursive function to construct binary tree */
TreeNode* buildTreeUtil(vector<TreeNode*> &nodes, int start,
                   int end)
{
    // base case
    if (start > end)
        return NULL;
 
    /* Get the middle element and make it root */
    int mid = (start + end)/2;
    TreeNode *root = nodes[mid];
 
    /* Using index in Inorder traversal, construct
       left and right subtress */
    root->left  = buildTreeUtil(nodes, start, mid-1);
    root->right = buildTreeUtil(nodes, mid+1, end);
 
    return root;
}
 
// This functions converts an unbalanced BST to
// a balanced BST
TreeNode* buildTree(TreeNode* root)
{
    // Store nodes of given BST in sorted order
    vector<TreeNode *> nodes;
    storeBSTNodes(root, nodes);
 
    // Constructs BST from nodes[]
    int n = nodes.size();
    return buildTreeUtil(nodes, 0, n-1);
}
 
/* Function to do preorder traversal of tree */
void preOrder(TreeNode* node)
{
    if (node == NULL)
        return;
    preOrder(node->left);
    preOrder(node->right);
}

void print_tree(TreeNode* node, int indent)
{
    if (node)
    {
        print_tree(node->right, indent + 1);
        std::cout << std::setw(indent*4) << "" << node->val << '\n';
        print_tree(node->left, indent + 1);
    }
}

void maxDiffUtil(struct TreeNode *ptr, int k, int &min_diff,
                                      int &min_diff_key)
{
    if (ptr == NULL)
        return ;
 
    // If k itself is present
    /*if (ptr->val == k)
    {
        min_diff_key = k;
        return;
    }*/
 
    // update min_diff and min_diff_key by checking
    // current node value
    if (min_diff > abs(ptr->val - k) && abs(ptr->val - k) != 0)
    {
        min_diff = abs(ptr->val - k);
        min_diff_key = ptr->val;
    }
    if (abs(ptr->val - k) == 0) {
        min_diff = min_diff;
        min_diff_key = min_diff_key;
    }

    // cout<<min_diff;
    // printf("\n");
    // if k is less than ptr->key then move in
    // left subtree else in right subtree
    if (k < ptr->val || k == ptr->val)
        maxDiffUtil(ptr->left, k, min_diff, min_diff_key);
    else
        maxDiffUtil(ptr->right, k, min_diff, min_diff_key);
}
 
// Wrapper over maxDiffUtil()
int maxDiff(TreeNode *root, int k)
{
    // Initialize minimum difference
    int min_diff = INT_MAX, min_diff_key = -1;
 
    // Find value of min_diff_key (Closest key
    // in tree with k)
    maxDiffUtil(root, k, min_diff, min_diff_key);
 
    return min_diff_key;
}

int main() {
	// Input BST, eg. 4 3 1 5 2 -1. O(n)
	cout<<"Input Tree elements : ";
	TreeNode* root = createBST();
    
    // Balance BST for improving performance on search O(n)
    root = buildTree(root);
    preOrder(root);

    // Show balanced BST
    printf("Balanced BST is : \n");
    print_tree(root, 0);
    printf("\n");
    
    // Find the closest element in Binary Search Tree. (O(log n) if BST is balanced).
    long long k = 3;
    cout << maxDiff(root, k);

    // Output the result by find closest element on each input data then compare which element that is changed then most decrease the summary subtraction on input.
    //TODO//
    
	return 0;
}
