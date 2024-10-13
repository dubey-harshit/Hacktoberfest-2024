#include <iostream>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *createTree(TreeNode *root){
	cout << "Enter data to insert (-1 for no child): ";
	int data;
	cin >> data;
	root = new TreeNode(data);

	if (data == -1)
		return NULL;

	cout << "Enter data for left child of " << data << endl;
	root->left = createTree(root->left);
	cout << "Enter data for right child of " << data << endl;
	root->right = createTree(root->right);

	return root;
}

pair<bool, int> optimizedIsBalanced(TreeNode *root){
	if (root == NULL){
		pair<bool, int> p = make_pair(true, 0);
		return p;
	}

	pair<bool, int> left = optimizedIsBalanced(root->left);
	pair<bool, int> right = optimizedIsBalanced(root->right);

	bool leftAns = left.first;
	bool rightAns = right.first;

	bool diff = abs(left.second - right.second) <= 1;

	pair<bool, int> ans;
	ans.second = max(left.second, right.second) + 1;

	ans.first = leftAns && rightAns && diff;
	return ans;
}

bool isBalanced(TreeNode *root){
	return optimizedIsBalanced(root).first;
}

int main()
{
	TreeNode *root;
	root = createTree(root);

	cout << isBalanced(root) << endl;
	return 0;
}
