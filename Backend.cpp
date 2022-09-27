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
    

        for(int i = 0; i < noVer; i++){
            // assigning the all the pointers in the array to NULL
                head[i] = NULL; 
                gateArr[i] = gates[i];
                Vertice temp;
                temp.index = i;
                temp.gateType = gateArr[i];
                vertexArr.push_back(temp);
        }
        // creating the edge paths
        for(int j = 0; j < noEdges; j++){
            this->startVert = edgeMap[j].startVertice;
            this->endVert = edgeMap[j].endVertice;
            Vertice* newVertice = getAdjNode(this->startVert, head[this->endVert], gateArr[this->endVert]);
            head[this->endVert] = newVertice;
        }
    }

    // Destructor
    ~TheGraph() {
        for (int i = 0; i < noVert; i++){
            delete[] head[i];
            delete[] head;
        }
    }

    // this function assigns the inputs ( 0 and 1) to the specified gates
    void settingInputs(vector<int> inputArr, int index, int size, bool signal){
        for(int i = 0; i < size; i++){
            Vertice* newVertice = new Vertice;
            newVertice->index = index;
            // index = -1 -> output = true
            // index = -2 -> output = false
            newVertice->output = signal;
            newVertice->next = head[inputArr[i]];
            head[inputArr[i]] = newVertice;
        }
    }

    // operationof the AND gate
    bool ANDgate(vector <bool> signals){
        int size = signals.size();
        bool result = signals[0];
        for(int k = 1; k < size; k++){
            result = result && signals[k];
        }
        return result;
    }

    // operation of the OR Gate
    bool ORgate(vector <bool> signals){
        int size = signals.size();
        bool result = signals[0];
        for(int k = 1; k < size; k++){
            result = result || signals[k];
        }
        return result;
    }

    // operation of the NOT Gate
    bool NOTgate(vector <bool> signals){
        if(signals[0] == true){
            return false;
        }else if(signals[0] == false){
            return true;
        }
    }

    // operation of the XOR Gate
    bool XORgate(vector <bool> signals){
        int size = signals.size();
        bool result = signals[0];
        for(int k = 1; k < size; k++){
            if(result == signals[k]){
                result = false;
            }else{
                result = true;
            }
        }
        return result;
    }

    // recursive function that travels through the graph and returns the output
    bool getOutput(Vertice* ptr, int index){
        // if(ptr == NULL){
        //     cout<<"NULL"<<endl;
        // }
        bool output;
        if(index == -1){
            return true;
        }else if(index == -2){
            return false;
        }
        else{
            string gateName = vertexArr[index].gateType; 
            vector <bool> signals;
            while(ptr != NULL){
                bool s = getOutput(head[ptr->index], ptr->index);
                signals.push_back(s);
                ptr = ptr->next;
            }
            
            if(gateName == "AND"){
                return ANDgate(signals);
            }else if(gateName == "OR"){
                return ORgate(signals);
            }else if(gateName == "NOT"){
                return NOTgate(signals); 
            }else if(gateName == "XOR"){
                return XORgate(signals);
            }
            signals.clear();
        }       
    }
};

int main(){
    fstream inputFile;
    string line;
    //string gateName;
    vector <string> gates;
    //vector <vector <int>> edges;
    vector <int> trueInputs;
    vector <int> falseInputs;
    string temp = "";

    vector<Edge> eMap;

    // *************************************************************************************************
    // open the file
    inputFile.open("gui_output.txt", ios::in);

     if(inputFile.is_open()){

        // reading names of gates____________________________________________
        getline(inputFile, line);
        for(int i = 2; i < line.size(); i++){

            // check for a uppercase letter
            if((int)line[i] > 64 && (int)line[i] < 91){
                temp = temp + line[i];

            }else if((int)line[i] == 39 && temp.size() > 1){
                gates.push_back(temp);
                temp = "";
            }
        }

        // reading the edge list size
        //int edgeSize;
        //getline(inputFile, line);
        //edgeSize = stoi(line);

        //reading the edge_______________________________________
        getline(inputFile, line);
        int tempNo = 0;
        Edge ob1;
        bool get = false;
        vector <int> total_nums;

        for(int i = 2; i < line.size(); i++){

            // check for a number
            if((int)line[i] > 47 && (int)line[i] < 58){
                tempNo = tempNo*10 + ((int)line[i] - 48);
                get = true;

            }else if(get){
                total_nums.push_back(tempNo);
                tempNo = 0;
                get = false;
            }
        }
}