#ifndef ___STATE_H___
#define ___STATE_H___
#include <iostream>
#include <vector>
using namespace std;

class State{
    private:
        vector<int> p;
        bool final;
    public:
        State();
        State(vector<int>);
        vector<int> getP();
        bool finalState();
        int getZero();
        void setFinal();
        
};
#endif