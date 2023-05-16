#include "file2_node.h"
using namespace std;

Node::Node(){
    this->left = NULL; 
    this->right = NULL;
    this->up = NULL;
    this->down = NULL;
    this->parent = NULL;
    this->node = State();
    this->heuristic = "UCS";
    this->uniform = 0;
    this->heuristic_cost = 0;
}

Node::Node(vector<int> p, int uniform, string heuristic, Node* parent){
    this->node = State(p);
    this->left = NULL; 
    this->right = NULL;
    this->up = NULL;
    this->down = NULL;
    this->parent = parent;
    this->uniform = uniform;
    this->heuristic_cost = calc(heuristic);
    this->heuristic = heuristic;
}

int Node::calc(string heuristic){
    //  Reference: https://stackoverflow.com/questions/39759721/calculating-the-manhattan-distance-in-the-eight-puzzle
    if(heuristic == "UCS"){
        return 0;
    }

    vector<int> Goal = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 0};
    vector<int> node = this->node.getP();  
    int cost = 0; 
      
    if(heuristic == "Manhattan"){
        for(int i = 0; i < Goal.size(); i++){
            if((Goal.at(i) != node.at(i)) && (node.at(i) != 0)) {
                cost += abs((node.at(i)-1)%3 - (i%3)) + abs(floor((node.at(i)-1)/3) - floor(i/3));
            }
        }
    }

    else if(heuristic == "Misplaced Tile"){
        for(int i = 0; i < Goal.size(); i++){
            if((Goal.at(i) != node.at(i)) && (node.at(i) != 0)){
                cost++;
            }
        }
    }

    return cost;
}

Node* Node::getChild(string temp){
    if(temp == "left"){
        return this->left;
    }
    else if(temp == "right"){
        return this->right;
    }
    else if(temp == "up"){
        return this->up;
    }
    else if(temp == "down"){
        return this->down;
    }
    else{
        throw invalid_argument("Invalid direction specified");
    }
}

vector<Node*> Node::getChildren()
{
    vector<Node*> temp;
    if(this->left != NULL){
        temp.push_back(this->left);
    }
    if(this->right != NULL){
        temp.push_back(this->right);
    }
    if(this->up != NULL){
        temp.push_back(this->up);
    }
    if(this->down != NULL){
        temp.push_back(this->down);
    }

    return temp;
}

void Node::expand(){
    vector<int> p = this->node.getP();
    vector<int> temp = p; 
    int temp_int = 0;
    int z_index = this->node.getZero();

    printState();
    cout << "Expanding node" << endl;

    if(z_index <= 5){
        temp_int = temp.at(z_index);
        temp.at(z_index) = temp.at(z_index + 3);
        temp.at(z_index + 3) = temp_int;
        this->down = new Node(temp, this->uni() + 1, this->heuristic, this);
    }
    temp = p;
    if((z_index == 0) || (z_index == 3) || (z_index == 6) || (z_index == 1) || (z_index == 4) || (z_index == 7)){
        temp_int = temp.at(z_index);
        temp.at(z_index) = temp.at(z_index + 1);
        temp.at(z_index + 1) = temp_int;
        this->right = new Node(temp, this->uni() + 1, this->heuristic, this);
    }

    temp = p;

    if(z_index >= (p.size() / 3)){
        temp_int = temp.at(z_index);
        temp.at(z_index) = temp.at(z_index - 3);
        temp.at(z_index - 3) = temp_int;
        this->up = new Node(temp, this->uni() + 1, this->heuristic, this);
    }

    temp = p;
    if((z_index == 2) || (z_index == 5) || (z_index == 8) || (z_index == 1) || (z_index == 4) || (z_index == 7)){
        temp_int = temp.at(z_index);
        temp.at(z_index) = temp.at(z_index - 1);
        temp.at(z_index - 1) = temp_int;
        this->left = new Node(temp, this->uni() + 1, this->heuristic, this);
    }
}

bool Node::goalState(){
    return this->node.finalState();
}

void Node::printState(){
    vector<int> p = this->node.getP();
    for(int i = 1; i <= p.size(); ++i){
        cout << p.at(i - 1) <<  " ";
        if((i % 3) == 0) {
            cout << endl;
        }
    }
}

int Node::uni(){
    return this->uniform;
}

int Node::heu(){
    return this->heuristic_cost;
}

Node* Node::get_parent(){
    return this->parent;
}

vector<int> Node::get_state(){
    return this->node.getP();
}