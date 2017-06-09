#include <iostream>

using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};

node* lca(node* root, int v1, int v2) {
	int val = root->data;
	while (!((val>=v1 && val<=v2) || (val<=v1 && val>=v2))) {
		if (v1<val) root = root->left;
		else root = root->right;
		val = root->data;
	}
	return root;
}

int main() {

}