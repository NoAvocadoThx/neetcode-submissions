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
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> oldToNew;
       return dfs(node, oldToNew);
    }

    Node* dfs(Node* node, unordered_map<Node*, Node*>& mems  )
    {
        if(node == nullptr) return nullptr;

        if(mems.count(node))
        {
            return mems[node];
        }

        Node* newNode = new Node(node->val);
        mems[node]  = newNode;
        for(Node* nei : node->neighbors)
        {
            newNode->neighbors.push_back(dfs(nei,mems));
        }
        return newNode;
    }
};
