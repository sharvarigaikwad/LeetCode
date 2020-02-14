/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<Node *, Node *> new_nodes;
        if(!node)
        {
            return node;
        }
        return cloneGraphHelper(node, new_nodes);
    }
    Node * cloneGraphHelper(Node * node, map<Node *, Node *> & new_nodes)
    {
        vector<Node *> neigh = node->neighbors, new_neigh;
        Node * new_node = new Node();
        new_node->val = node->val; 
        new_nodes[node] = new_node;
        for(Node * sib: neigh)
        {
            if(sib && new_nodes.count(sib))
            {
                new_neigh.push_back(new_nodes[sib]);
            }
            else if(sib)
            {
                new_neigh.push_back(cloneGraphHelper(sib, new_nodes));
            }
        }
        new_node->neighbors = new_neigh;
        return new_node;
    }
};