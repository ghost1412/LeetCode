/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {

private:
unordered_map<int, Node*> nodeRef;

public:

    vector<Node*> copyNeighbors(vector<Node*>& neighbors) {
        vector<Node*> neighborsCopy;

        for (int i=0; i < neighbors.size(); i++) {
            Node* copiedNeighbor = copyNodes(neighbors[i]);
            neighborsCopy.push_back(copiedNeighbor);
        }
        return neighborsCopy;
    }

    Node* copyNodes(Node* node) {
        if (node == NULL) return nullptr;
        int val = node->val;
        if (this->nodeRef.find(val) != this->nodeRef.end()) {
            return nodeRef[val];
        }
        Node* newNode = new Node(val, {});
        this->nodeRef[val] = newNode;

        newNode->neighbors = copyNeighbors(node->neighbors);
        return newNode;
    }

    Node* cloneGraph(Node* node) {
        return copyNodes(node);
    }
};
