#include <iostream>
#include "file3_tree_structure.h"
using namespace std;

void print_trace_back(Node* node){
    if (node == NULL) {
        return;
    }
    print_trace_back(node->get_parent());
    node->printState();
    cout << endl;
}

void Uniform_search(Tree test){
    cout << "Inital node: " << endl;

    if (test.final_goal_root()){
        test.getRoot()->printState();
        cout << "Goal state!" << endl << endl;
        cout << "Number of nodes expanded: 0 nodes." << endl;
        cout << "Max queue size: 1." << endl;
        print_trace_back(test.getRoot());
        return;
    }
    Node* temp = NULL;
    Node* child = NULL;
    vector<Node*> children;
    int nodesExpanded = 0;

    if (test.get_nodern().empty()){
        cout << "Failed" << endl;
        return;
    }

    while (!test.get_nodern().empty()){
        temp = test.get_nodern().top();
        test.remove_node();
        test.update_node(temp);
        if (nodesExpanded > 0){
            cout << "The best state to expand with a g(n) = " << temp->uni() << " and h(n) = " << temp->heu() << " is..." << endl;
        }

        temp->expand();
        nodesExpanded++;
        children = temp->getChildren();

        for (int i = 0; i < children.size(); ++i){
            child = children.at(i);
            if (child->goalState()){
                cout << "Goal state!" << endl << endl;
                cout << "Number of nodes expanded: " << nodesExpanded << " nodes." << endl;
                cout << "Max queue size: " << test.get_max_nodes() << endl;
                print_trace_back(child);
                return;
            }
        }
        test.update_node(temp);
    }
}

// ref: https://www.geeksforgeeks.org/a-search-algorithm/
void Heuristic_search(Tree test){
    Node* temp = NULL;
    int nodesExpanded = 0;

    if (test.get_nodern().empty()){
        cout << "Failed" << endl;
    }

    cout << "Inital node: " << endl;

    while (!test.get_nodern().empty()){
        temp = test.get_nodern().top();
        test.remove_node();

        if (temp->goalState()){
            if (nodesExpanded == 0){
                temp->printState();
            }
            cout << "Goal state!!!" << endl;
            cout << "Number of nodes expanded: " << nodesExpanded << " nodes." << endl;
            cout << "Max queue size: " << test.get_max_nodes() << endl;
            print_trace_back(temp);
            return;
        }

        if (nodesExpanded > 0){
            cout << "The best state to expand with a g(n) = " << temp->uni() << " and h(n) = " << temp->heu() << " is..." << endl;
        }
        temp->expand();
        nodesExpanded++;
        test.update_explored_node(temp);
        test.update_node(temp);
    }
    cout << endl;
}

int main(){
    int user = 0;
    int num = 0;
    int algo = 0;
    int play = 0;
    vector<int> puzzle;
    //bool play = true;
    cout << "Welcome to 8-puzzle solver." << endl;
    cout << "Type \'1'\ to use a default puzzle or \'2'\ to enter your own puzzle." << endl;

    cin >> user;

        if (user == 1){
            puzzle = {
                1,2,3,
                4,5,6,
                7,8,0};
        }

        else if (user == 2){
            cout << "Enter the first row" << endl;
            for (int i = 0; i < 3; i++)
            {
                cin >> num;
                puzzle.push_back(num);
            }
            cout << "Enter the second row" << endl;
            for (int i = 0; i < 3; i++)
            {
                cin >> num;
                puzzle.push_back(num);
            }
            cout << "Enter the third row" << endl;
            for (int i = 0; i < 3; i++)
            {
                cin >> num;
                puzzle.push_back(num);
            }
        }

        cout << endl;
        cout << "Enter your choice of algorithm" << endl;
        cout << "1) Uniform Cost Search" << endl;
        cout << "2) A* with the Misplaced Tile heuristic." << endl;
        cout << "3) A* with the Manhattan distance heuristic" << endl;
        cin >> algo;
        cout << endl;

        if (algo == 1){
            Node* node = new Node(puzzle, 0, "UCS");
            Tree tree = Tree(node);
            Uniform_search(node);
        }
        else if (algo == 2){
            Node* node = new Node(puzzle, 0, "Misplaced Tile");
            Tree tree = Tree(node);
            Heuristic_search(tree);
        }
        else if (algo == 3){
            Node* node = new Node(puzzle, 0, "Manhattan");
            Tree tree = Tree(node);
            Heuristic_search(tree);
        }
    return 0;
}






