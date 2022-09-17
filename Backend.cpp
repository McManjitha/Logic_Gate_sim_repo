#include<iostream>
#include<vector>
using namespace std;


// vertice class; Logic gate
struct Vertice{
    Vertice* next;
    bool output = NULL;
    int index;
    string gateType = "";
};

// siganl path
struct Edge{
    int startVertice;
    int endVertice;
};

class TheGraph{
private:
    int noVert; // no of vertices
    int startVert; // stating vertice of the edge
    int endVert; // ending vertice of the edge
    vector <Vertice> vertexArr;
};