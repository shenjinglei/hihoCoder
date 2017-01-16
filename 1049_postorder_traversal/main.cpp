#include <iostream>
#include <string>

using namespace std;

struct node {
	char value;
	node* lchild;
	node* rchild;
};

typedef struct node* tree;

tree deserialize(string preorder, string inorder) {
	if (preorder.size() == 0 || inorder.size() == 0) {
		return NULL;
	}
	tree root = new struct node;
	root->value = preorder.at(0);
	int pos = inorder.find(root->value);
	root->lchild = deserialize(preorder.substr(1,pos), inorder.substr(0, pos));
	root->rchild = deserialize(preorder.substr(pos+1), inorder.substr(pos+1));
	return root;
}

string serialize(tree root) {
	if (root == NULL) {
		return "";
	}
	string s = serialize(root->lchild);
	s += serialize(root->rchild);
	s += root->value;
	return s;
}

int main() {
	string preorder;
	string inorder;
	cin >> preorder >> inorder;
	tree root = deserialize(preorder, inorder);
	cout << serialize(root);
	system("pause");
}