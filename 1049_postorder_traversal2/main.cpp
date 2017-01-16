#include <iostream>
#include <string>

using namespace std;

string postorder(string preorder, string inorder) {
	if (preorder.size() == 0 || inorder.size() == 0) {
		return "";
	}
	char root = preorder.at(0);
	int pos = inorder.find(root);
	string lchild = postorder(preorder.substr(1, pos), inorder.substr(0, pos));
	string rchild = postorder(preorder.substr(pos + 1), inorder.substr(pos + 1));
	return lchild + rchild + root;
}

int main() {
	string preorder;
	string inorder;
	cin >> preorder >> inorder;
	cout << postorder(preorder, inorder) << endl;
	system("pause");
}
