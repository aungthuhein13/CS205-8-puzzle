#ifndef ___FILE2_NODE_H___
#define ___FILE2_NODE_H___
#include "file1_state.h"
#include <string>
#include <cmath>
using namespace std;

class Node{
    private:
        Node* up;
        Node* down;
        Node* left; 
        Node* right;
        Node* parent;
        State node;
        string heuristic;
        int uniform;
        int heuristic_cost;
    public:
        Node();
        Node(vector<int>, int, string, Node* = NULL);
        int uni();
        int heu();
        int calc(string);
        vector<Node*> getChildren();
        void expand();
        Node* getChild(string);
        bool goalState();
        void printState();
        Node* get_parent();
        vector<int> get_state();
};

#endif