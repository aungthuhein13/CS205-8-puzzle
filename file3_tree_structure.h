#ifndef __FILE3_TREE_STRUCTURE_H__
#define __FILE3_TREE_STRUCTURE_H__

#include <queue>
#include "file2_node.h"
using namespace std;
// Ref :https://stackoverflow.com/questions/20826078/priority-queue-comparison
struct compare{
    bool operator()(Node* temp1, Node* temp2){
        return (temp1->uni() + temp1->heu()) > (temp2->uni() + temp2->heu());
    }
};

class Tree{
    private:
        Node* root;
        int nodes;
        int max_nodes;
        priority_queue<Node*, vector<Node*>, compare> node_rn;
        vector<Node*> node_explore;
    public:
        Tree();
        Tree(Node*);
        int get_max_nodes();
        priority_queue<Node*, vector<Node*>, compare> get_nodern();
        void remove_node();
        void update_node(Node*);
        void update_explored_node(Node*);
        bool check_if_explored(Node*);
        Node* getRoot();
        bool final_goal_root();
};
#endif