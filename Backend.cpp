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

    Vertice* getAdjNode(int value, Vertice* head, string gate){
        Vertice* newVertice = new Vertice;
        newVertice->index = value;
        newVertice->output = NULL;
        newVertice->next = head;
        newVertice->gateType = gate;
        return newVertice;
    }

public:
    Vertice** head;

    // constructor
    TheGraph(int noVer, vector <Edge>edgeMap, int noEdges, vector<string> gates){ 
        // create a array of pointers
        head = new Vertice*[noVer]();
        this->noVert = noVer;
        string gateArr[noVer];
    }

    for(int i = 0; i < noVer; i++){
        // assigning the all the pointers in the array to NULL
            head[i] = NULL; 
            gateArr[i] = gates[i];
            Vertice temp;
            temp.index = i;
            temp.gateType = gateArr[i];
            vertexArr.push_back(temp);
    }
};