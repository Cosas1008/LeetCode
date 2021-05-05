#include<vector>

using namespace std;

class City{
    // Number of X
    // constructor
public:
    City(int id){
        this->cityID = id;
        this->hasWarehouse = false;
    }
    void AddStatiion(Warehouse& wh){
        warehouse = wh;
        this->hasWarehouse = true;
    }
    void AddConnection(int cityID){
        connect.push_back(cityID);
    }
private:
    Warehouse warehouse; // Warehouse
    int cityID;
    bool hasWarehouse;
    vector<int> connect;
};

class Warehouse {
public:
    Warehouse(int number, int cost){

    };
private:
    int numberofX;
    int cost;
};

int main()
{
    int 
}