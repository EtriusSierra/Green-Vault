#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

// What are the stops on a route?
class Route{

    private:
        string IDName;
        vector<string> stopList;

    public:
        Route();

        void setIDName(string ID);
        string getIDName();

        void addStop(string S);
        void removeStop(int pos);
        void getStops();

};

Route::Route(){
    IDName = "Unknown";
}

void Route::setIDName(string ID){
    IDName = ID;
}

string Route::getIDName(){
    return IDName;
}

void Route::addStop(string S){
    stopList.push_back(S);
}

void Route::removeStop(int ind){
    if (stopList.size() != 0){
        if (ind-1 < stopList.size() && ind-1 > 0){
            stopList.erase(stopList.begin() + ind-1);
        }
        else {
            cout << "Invalid index." << endl;
        }
    }
    else {
        cout << "No Stops Added." << endl;
    }
}

void Route::getStops(){
    for (int i = 0; i < stopList.size(); i++){
        cout << stopList.at(i) << " -> "; 
    }
    cout << "END OF STOPS." << endl;
}

// What are the routes on a bus line?
class BusLine{

    private:
        int IDNum;
        vector<Route*> routeList;

    public:
        BusLine();

        void setIDNum(int ID);
        int getIDNum();

        void addRoute(Route* R);
        void removeRoute(int ind);
        void getRoutes();   

};

BusLine::BusLine(){
    IDNum = -1;
}

void BusLine::setIDNum(int ID){
    IDNum = ID;
}

void BusLine::addRoute(Route* R){
    routeList.push_back(R);    
}

void BusLine::removeRoute(int ind){
    if (routeList.size() != 0){
        if (ind-1 < routeList.size() && ind-1 > 0){
            routeList.erase(routeList.begin() + ind-1);
        }
        else {
            cout << "Invalid index." << endl;
        }
    }
    else {
        cout << "No Routes Added." << endl;
    }
}

int BusLine::getIDNum(){
    return IDNum;
}

void BusLine::getRoutes(){
    
    for (int j = 0; j < routeList.size(); j++){
        cout << (routeList.at(j))->getIDName() << " -> ";
    }
    cout << "END OF ROUTES." << endl;
}

// What bus line has been chosen for a given bus?
class Bus{

    private:
        BusLine* chosenLine;
        string chosenTime;

    public:
        Bus();

        void setLine(BusLine* CL);
        void setTime(string T);

        void getLine();
        void getTime();   

};

Bus::Bus(){
    chosenTime = -1;
}

void Bus::setLine(BusLine* CL){
    chosenLine = CL;
}

void Bus::setTime(string T){
    chosenTime = T;
}

void Bus::getLine(){
    cout << chosenLine->getIDNum() << endl;
}

void Bus::getTime(){
    cout << chosenTime << endl;
}


int main(){

    cout << endl;

    // Setup routes.    
    Route *roadA;
    Route *roadB;
    roadA = new Route();
    roadB = new Route();

    roadA->setIDName("Pivot");
    roadB->setIDName("Romel");

    roadA->addStop("2A");
    roadA->addStop("5B");
    roadB->addStop("3F");
    roadB->addStop("15C");
    roadB->addStop("22G");
    roadB->addStop("34A");

    roadB->removeStop(3);

    cout << "Route: " << roadA->getIDName() << endl;
    roadA->getStops();
    cout << "Route: " << roadB->getIDName() << endl;
    roadB->getStops();
    cout << endl;

    // Setup bus lines.
    BusLine *lineA;
    BusLine *lineB;
    lineA = new BusLine();
    lineB = new BusLine();

    lineA->setIDNum(42);
    lineB->setIDNum(69);

    lineA->addRoute(roadB);
    lineB->addRoute(roadA);
    lineB->addRoute(roadB);

    cout << "BusLine: " << lineA->getIDNum() << endl;
    lineA->getRoutes();
    cout << "BusLine: " << lineB->getIDNum() << endl;
    lineB->getRoutes();
    cout << endl;

    // Setup a bus.
    Bus *MSB;
    MSB = new Bus();

    MSB->setTime("0900");
    MSB->setLine(lineB);
    MSB->setLine(lineA);

    cout << "Magical School Bus line: ";
    MSB->getLine();
    cout << "Arrival time: ";
    MSB->getTime();
    cout << endl;

    // Cleanup
    delete roadA, roadB, lineA, lineB, MSB;
}