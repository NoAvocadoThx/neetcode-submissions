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
        unordered_map<Node*, Node*> visited;
         return dfs(node, visited);
    }

    Node* dfs(Node* node, unordered_map<Node*, Node*>& maps)
    {
        if(!node) return nullptr;
        if(maps.count(node))
        {
            return maps[node];
        }

        Node* newNode = new Node(node->val);
        maps[node] = newNode;
        for(Node* nodeNei : node->neighbors)
        {   
            newNode->neighbors.push_back(dfs(nodeNei, maps));
        }
        return newNode;
    }
};
