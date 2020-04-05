#include "iostream"
#include "queue"

using namespace std;


//Nary Node
class NaryNode {
public:
    int data;
    vector<NaryNode *> next;

    explicit NaryNode(int d) {
        data = d;
    }
};


void preOrderNary(NaryNode *root) {
    if (!root) return;

    cout << root->data << " ";
    int i = 0;
    while (i < root->next.size()) {
        preOrderNary(root->next[i]);
        i++;
    }
}

void postOrderNary(NaryNode *root) {
    if (!root) return;

    int i = 0;
    while (i < root->next.size()) {
        postOrderNary(root->next[i]);
        i++;
    }
    cout << root->data << " ";
}

void inOrderNary(NaryNode *root) {
    if (!root) return;

    int n = (int) root->next.size();
    for (int i = 0; i < n - 1; i++) {
        inOrderNary(root->next[i]);
    }

    cout << root->data << " ";
    if (n > 0) inOrderNary(root->next[n - 1]);
}

void levelOrderNary(NaryNode *root) {
    queue<NaryNode *> q;
    q.push(root);
    while (!q.empty()) {
        int x = q.size();
        for (int i = 0; i < x; i++) {
            NaryNode *temp = q.front();
            q.pop();
            cout << temp->data << " ";
            int j = 0;
            while (j < temp->next.size()) {
                q.push(temp->next[j]);
                j++;
            }
        }
    }
}


int main() {


    //N-array tree(Tree with more than 2 children)
    NaryNode *nAryRoot;
    nAryRoot = new NaryNode(1);
    nAryRoot->next.push_back(new NaryNode(2));
    nAryRoot->next.push_back(new NaryNode(3));
    nAryRoot->next.push_back(new NaryNode(4));

    nAryRoot->next[1]->next.push_back(new NaryNode(5));
    nAryRoot->next[1]->next.push_back(new NaryNode(6));

    nAryRoot->next[2]->next.push_back(new NaryNode(7));
    nAryRoot->next[2]->next.push_back(new NaryNode(8));
    nAryRoot->next[2]->next.push_back(new NaryNode(9));
    nAryRoot->next[2]->next.push_back(new NaryNode(10));

    //preOrderNary
    cout << endl << "PreOrder Nary: ";
    preOrderNary(nAryRoot);
    cout << endl;

    //postOrderNary
    cout << endl << "PostOrder Nary: ";
    postOrderNary(nAryRoot);
    cout << endl;

    //inOrderNary
    cout << endl << "InOrder Nary: ";
    inOrderNary(nAryRoot);
    cout << endl;

    //levelOrderNary
    cout << endl << "LevelOrder Nary: ";
    levelOrderNary(nAryRoot);
    cout << endl;

    return 0;
}
