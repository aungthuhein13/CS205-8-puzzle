#include "file1_state.h"

State::State(){
    this->final = false;
}

State::State(vector<int> p) {
    vector<int> Goal = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 0};
    this->p = p;
    if(p == Goal){
        this->final = true;
    }
    else{
        this->final = false;
    }
}

bool State::finalState(){
    return this->final;
}

void State::setFinal() {
    this->final = true;
}

vector<int> State::getP(){
    return this->p;
}

int State::getZero(){
    vector<int> temp = this->p;
    int num = temp.size();
    for(int i = 0; i < num; i++)
    {
        if(temp.at(i) == 0){
            //cout << "zeroes found." << endl;
            return i;
        }
    }
    cout << "No zeroes found." << endl;
    return -1;
}