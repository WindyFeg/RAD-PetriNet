#ifndef PETRINET
#define PETRINET

// Library
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Place {
private:
    int nTokens;
    string name;

public:
    Place(string, int);
    void setToken(int);
    void addToken(int);
    void minusToken(int);
    int getToken();
    void print();
    ~Place(){};

    friend class Net;
};

class Transition {
private:
    string name;
    vector<Place*> in;
    vector<Place*> out;

public:
    Transition(string n) : name(n){};
    void addArcOut(Place*);
    void addArcIn(Place*);
    bool isEnabled();
    void firing();
    void print();
    void printTransition();

    friend class Net;
};

class Net {
public:
    int nP;
    int nT;
    vector<Place*> p;
    vector<Transition*> t;

    Place* getPlace(string);
    Transition* getTrans(string);
    void addArcOut(string, string);
    void addArcIn(string, string);

public:
    Net() : nP(0), nT(0){}
    string getPlaces();
    string getTransitions();
    int* getMarking();
    int* firing(Transition*);
    int* setInitialM(int);
    void addPlace(string, int);
    void addTransition(string name);
    void addArc(string sou, string des);
    bool changStageUtil(int M[], vector<int*> res);
    void changeStage(int);
    long long countMarking(); // Phong

    void addPlaces(string*, int);
    void addTransitions(string*, int);
    void addArcs(string*, int);
    void initial(int*, int);
    string toString(int problem);
    void setMarking(vector<int> s);
    
};

#endif