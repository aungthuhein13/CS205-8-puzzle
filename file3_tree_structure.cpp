#include "file3_tree_structure.h"
using namespace std;

Tree::Tree(){
    this->root = NULL;
}

Tree::Tree(Node* root){
    this->nodes = 1;
    this->max_nodes = 1;
    this->node_rn.push(root);
    this->root = root;
}

int Tree::get_max_nodes(){
    return this->max_nodes;
}

priority_queue<Node*, vector<Node*>, compare> Tree::get_nodern(){
    return this->node_rn;
}

void Tree::remove_node(){
    --this->nodes;
    this->node_rn.pop();
}

void Tree::update_node(Node* temp){
    if(temp->getChild("left") != NULL){
        if(!this->check_if_explored(temp->getChild("left"))) {
            ++this->nodes;
            this->node_rn.push(temp->getChild("left"));
        }
    }

    if(temp->getChild("right") != NULL){
        if(!this->check_if_explored(temp->getChild("right"))){
            ++this->nodes;
            this->node_rn.push(temp->getChild("right"));
        }
    }

    if(temp->getChild("up") != NULL){
        if(!this->check_if_explored(temp->getChild("up"))){
            ++this->nodes;
            this->node_rn.push(temp->getChild("up"));
        }
    }
    
    if(temp->getChild("down") != NULL) {
        if(!this->check_if_explored(temp->getChild("down"))){
            ++this->nodes;
            this->node_rn.push(temp->getChild("down"));
        }
    }

    if(this->nodes > this->max_nodes){
        this->max_nodes = this->nodes;
    }

}

void Tree::update_explored_node(Node* expandedNode){
    this->node_explore.push_back(expandedNode);
}

bool Tree::check_if_explored(Node* node){
    for(int i = 0; i < this->node_explore.size(); i++){
        if(this->node_explore.at(i)->get_state() == node->get_state()){
            return true;
        }
    }
    return false;
}

Node* Tree::getRoot(){
    return this->root;
}
bool Tree::final_goal_root(){
    return this->root->goalState();
}
