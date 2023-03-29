#include <iostream>
#include <vector>

using namespace std;

// Definition for binary tree
struct TreeNode {
     long long int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(long long int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* insertInBST(TreeNode* root, long long int x) {
	if (root == NULL) {
		TreeNode* tmp = new TreeNode(x);
	    return tmp;
    }

    if (x < root->val) {
        root->left = insertInBST(root->left , x);
        return root;
    } 
    else {
        root->right = insertInBST(root->right, x);
        return root;
    }
}

vector<long long int> height;
long long int smn=0;

TreeNode* createBST(int n) {
	TreeNode* root = NULL;
	long long int x;
    for(int i=0; i<n; i++) {
      cin >> x; 
      root = insertInBST(root, x); 
      height.push_back(x);
    }
    for(int i=0;i<n;i++){
      if(i!=n-1){
        smn+=abs(height[i]-height[i+1]);
      }
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

void maxDiffUtil(struct TreeNode *ptr, long long int k, long long int &min_diff,
                                      long long int &min_diff_key)
{
    if (ptr == NULL)
        return ;
 
    // If k itself is present
    if (ptr->val == k)
    {
        if (ptr->left != NULL)
            maxDiffUtil(ptr->left, k, min_diff, min_diff_key);
        else
            maxDiffUtil(ptr->right, k, min_diff, min_diff_key);
    }
 
    // update min_diff and min_diff_key by checking
    // current node value
    // cout << "Mindiff " << min_diff << endl;
    if (min_diff > abs(ptr->val - k) && abs(ptr->val - k) != 0)
    {
        min_diff = abs(ptr->val - k);
        min_diff_key = ptr->val;
    }

    // if k is less than ptr->key then move in
    // left subtree else in right subtree
    if (k < ptr->val)
        maxDiffUtil(ptr->left, k, min_diff, min_diff_key);
    else
        maxDiffUtil(ptr->right, k, min_diff, min_diff_key);
}

int maxDiff(TreeNode *root, long long int k)
{
    // Initialize minimum difference
    long long int min_diff = 1000000000000, min_diff_key = -1;
 
    // Find value of min_diff_key (Closest key
    // in tree with k)
    maxDiffUtil(root, k, min_diff, min_diff_key);
 
    return min_diff_key;
}

int main() {
	// Input BST, eg. 4 3 1 5 2 -1. O(n)
    int n;
	cin>>n;
	TreeNode* root = createBST(n);
    
    // Balance BST for improving performance on search O(n)
    root = buildTree(root);

    int mn=smn;
    // cout<<mn<<endl; 
    for(int i=0;i<n;i++){
       if(i==0){
         int df;
         df=maxDiff(root, height[1]);
         //cout<<df<<"\n";
         if( smn-abs(height[0]-height[1])+abs(df-height[1]) < mn && df!=height[i+1]){
            mn = smn-abs(height[0]-height[1]) + abs(df-height[1]);
         }
       } 
       else if(i!=n-1){
         int f=maxDiff(root, height[i+1]);
         int b=maxDiff(root, height[i-1]);
         //cout<<endl;
         //cout<<f<<"\n";
         //cout<<b<<"\n";
         if((smn - (abs(height[i]-height[i+1]) + abs(height[i]-height[i-1])) + (abs(f-height[i+1]) + abs(f-height[i-1]))) < mn && f!=height[i+1] && f!=height[i-1]){
            mn = (smn - (abs(height[i]-height[i+1]) + abs(height[i]-height[i-1])) + (abs(f-height[i+1]) + abs(f-height[i-1])));
         }
         if((smn - (abs(height[i]-height[i+1]) + abs(height[i]-height[i-1])) + (abs(b-height[i+1]) + abs(b-height[i-1]))) < mn && b!=height[i+1] && b!=height[i-1]){
            mn = (smn - (abs(height[i]-height[i+1]) + abs(height[i]-height[i-1])) + (abs(b-height[i+1]) + abs(b-height[i-1])));
         }
       } else {
         int df;
         df=maxDiff(root, height[i-1]);
         //cout<<df<<"\n";
         if(smn-abs(height[i]-height[i-1])+abs(df-height[i-1]) < mn && df!=height[i-1]){
            mn = smn-abs(height[i]-height[i-1]) + abs(df-height[i-1]);
         }
       }
      
       //cout<<mn<<endl; 
    }
    
    cout<<mn;
    
	return 0;
}

/*
6
2 5 6 3 1 4
*/

/*
5
4 3 1 5 2
*/

/*
5
10 15 20 12 19
*/