//
// Created by Miruna on 5/19/2021.
//

#ifndef UNTITLED_OBSERVER_H
#define UNTITLED_OBSERVER_H

#include <vector>
#include <algorithm>

using namespace std;

class Observer{

public:
    virtual void update() = 0;
};

class Observable{

private:
    vector<Observer*> observers;

public:

    void add_observer(Observer* obs){
        observers.push_back(obs);
    }

    void remove_observers(Observer* obs){
        observers.erase(remove(observers.begin(), observers.end(), obs), observers.end());
    }

    void notify(){
        for(auto obs: observers)
            obs->update();
    }
};

#endif //UNTITLED_OBSERVER_H
