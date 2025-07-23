//#include <iostream>
//using namespace std;
//
//class bnode {
//public:
//    int value;
//    bnode* l, * r;
//    bnode(int val) : value(val), l(nullptr), r(nullptr) {}
//};
//
//class bst {
//public:
//    bnode* root;
//    bst() : root(nullptr) {}
//
//    int height(bnode* node) {
//        if (!node) return 0;
//        return 1 + max(height(node->l), height(node->r));
//    }
//
//    int bfac(bnode* node) {
//        if (!node) return 0;
//        return height(node->l) - height(node->r);
//    }
//
//    bnode* rightRot(bnode* y) {
//        bnode* x = y->l;
//        bnode* T2 = x->r;
//
//        x->r = y;
//        y->l = T2;
//
//        return x;
//    }
//
//    bnode* leftRot(bnode* x) {
//        bnode* y = x->r;
//        bnode* T2 = y->l;
//
//        y->l = x;
//        x->r = T2;
//
//        return y;
//    }
//
//    bnode* insert(bnode* node, int val) {
//        if (!node) return new bnode(val);
//
//        if (val < node->value)
//            node->l = insert(node->l, val);
//        else if (val > node->value)
//            node->r = insert(node->r, val);
//        else
//            return node; // Duplicates not allowed
//
//        int bf = bfac(node);
//
//        // Left-Left Case (Right Rotation)
//        if (bf > 1 && val < node->l->value)
//            return rightRot(node);
//
//        // Right-Right Case (Left Rotation)
//        if (bf < -1 && val > node->r->value)
//            return leftRot(node);
//
//        // Left-Right Case (Left Rotation on child, then Right Rotation)
//        if (bf > 1 && val > node->l->value) {
//            node->l = leftRot(node->l);
//            return rightRot(node);
//        }
//
//        // Right-Left Case (Right Rotation on child, then Left Rotation)
//        if (bf < -1 && val < node->r->value) {
//            node->r = rightRot(node->r);
//            return leftRot(node);
//        }
//
//        return node; // Return unchanged node if balanced
//    }
//
//    void insert(int val) {
//        root = insert(root, val);
//    }
//
//    bnode* minValueNode(bnode* node) {
//        bnode* current = node;
//        while (current && current->l != nullptr)
//            current = current->l;
//        return current;
//    }
//
//    bnode* deleteNode(bnode* root, int val) {
//        if (!root) return root;
//
//        // Perform standard BST delete
//        if (val < root->value)
//            root->l = deleteNode(root->l, val);
//        else if (val > root->value)
//            root->r = deleteNode(root->r, val);
//        else {
//            // Node with only one child or no child
//            if (!root->l || !root->r) {
//                bnode* temp = root->l ? root->l : root->r;
//                // No child case
//                if (!temp) {
//                    temp = root;
//                    root = nullptr;
//                }
//                else // One child case
//                    *root = *temp; // Copy contents
//                delete temp;
//            }
//            else {
//                // Node with two children
//                bnode* temp = minValueNode(root->r);
//                root->value = temp->value;
//                root->r = deleteNode(root->r, temp->value);
//            }
//        }
//
//        // If the tree had only one node then return
//        if (!root) return root;
//
//        // Update balance factor and balance the tree
//        int bf = bfac(root);
//
//        // Left Left Case
//        if (bf > 1 && bfac(root->l) >= 0)
//            return rightRot(root);
//
//        // Left Right Case
//        if (bf > 1 && bfac(root->l) < 0) {
//            root->l = leftRot(root->l);
//            return rightRot(root);
//        }
//
//        // Right Right Case
//        if (bf < -1 && bfac(root->r) <= 0)
//            return leftRot(root);
//
//        // Right Left Case
//        if (bf < -1 && bfac(root->r) > 0) {
//            root->r = rightRot(root->r);
//            return leftRot(root);
//        }
//
//        return root;
//    }
//
//    void deleteOneNodeandpalance(int val) {
//        root = deleteNode(root, val);
//    }
//
//    // Helper: Print in-order traversal
//    void inOrder(bnode* node) {
//        if (!node) return;
//        inOrder(node->l);
//        cout << node->value << " ";
//        inOrder(node->r);
//    }
//
//    void printInOrder() {
//        inOrder(root);
//        cout << endl;
//    }
//};
//
//int sum(bnode* root) {
//	if (!root)return 0;
//	return root->value + sum( root->l ) + sum(root->r );
//}
//#include<queue>
//void bfs(bnode* root) {
//    if (!root)return;
//    queue <bnode*>q;
//	q.push(root);
//    while (!q.empty()) {
//		bnode* curr = q.front();
//        q.pop();
//		cout << curr->value << " ";
//		if (curr->l) q.push(curr->l);
//		if (curr->r) q.push(curr->r);
//    }
//}
//
//int main() {
//    bst tree;
//    tree.insert(10);
//    tree.insert(20);
//    tree.insert(30); // Triggers RR rotation
//    tree.insert(40);
//    tree.insert(50);
//    tree.insert(25); // Triggers RL rotation
//	cout << sum(tree.root) << endl;
//    cout << "In-order traversal: ";
//    tree.printInOrder();
//
//    cout << "Deleting 40...\n";
//    tree.deleteOneNodeandpalance(40);
//    tree.printInOrder();
//
//    return 0;
//}