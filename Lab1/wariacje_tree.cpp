#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int value;
	int depth;
	vector<Node*> children;
	vector<int> used;
};

bool isUsed(Node* node, int value) {
	for (int i = 0; i < node->used.size(); i++) {
		if (node->used[i] == value) {
			return true;
		}
	}
	return false;
}

void generateTree(Node* node, int m, int n) {
	if (m == 0) {
		return;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (!isUsed(node, i + 1)) {
				Node* child = new Node;
				child->value = i + 1;
				child->depth = node->depth + 1;
				child->used = node->used;
				child->used.push_back(i + 1);
				node->children.push_back(child);
				generateTree(child, m - 1, n);
			}
		}
	}
}

bool noReps(vector<int> v) {
	for (int i = 1; i < v.size(); i++) {
		if (v[i] < v[i - 1]) {
			return false;
		}
	}
	return true;
}

void printTree(Node* node, int m, vector<int> v) {
	if (node->depth == m && noReps(v)) {
		for (int i = 0; i < m; i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}
	else {
		for (int i = 0; i < node->children.size(); i++) {
			v[node->depth] = node->children[i]->value;
			printTree(node->children[i], m, v);
		}
	}
}

int main() {
	int m = 4, n = 6;
	//cin >> m;
	Node *root = new Node;
	root->value = 0;
	root->depth = 0;
	generateTree(root, m, n);
	printTree(root, m, vector<int>(m));
}