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
public:
    unordered_map<int, Node*> nodeRef;
    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;
        if (nodeRef.find(node->val) != nodeRef.end()) return nodeRef[node->val];
        Node* copy = new Node(node->val);
        nodeRef[node->val] = copy;
        for(int i=0; i<node->neighbors.size(); i++) {

            Node* copy2 = cloneGraph(node->neighbors[i]);
            copy->neighbors.push_back(copy2);
        }
        return copy;
    }
};
