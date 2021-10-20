/*
ID: yuweiic1
LANG: C++
TASK: gift1
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class People{

private:
    string name;
    int money;
public:
    People(string nameIn, int moneyIn){name=nameIn; money=moneyIn;};

    bool operator== (const People &people){
        if(this->name == people.name){
            return  true;
        }
        return false;
    }

    bool operator== (string name){
        if(this->name == name)
            return true;
        return false;
    }
    void setMoney(int coming)
    {
        this->money += coming;
    }

    string getName(){
        return this->name;
    }

    int getMoney(){
        return this->money;
    }

//    friend bool operator== (const People &p1, const People &p2){
//        if(p1.name == p2.name){
//            return true;
//        }
//        return false;
//    }
};

typedef std::vector<People>::iterator iteratorPeople;

int main() {
    ifstream fin("gift1.in");
    ofstream fout("gift1.out");

    int numOfPeople;
    vector<People> people;

    fin >> numOfPeople;
    people.reserve(numOfPeople);

    for(int i =0; i < numOfPeople; i++){
        string name;
        fin >> name;
        People newPeople = People(name,0);
        people.push_back(newPeople);
    }
    string name;
    int remainAmount , totalAmount, individualAmount ,divider;

    fin >> name >> totalAmount >> divider;
    int l = 0;
    while(l < numOfPeople)
    {
        iteratorPeople borrower  = find(people.begin(), people.end(), name);
        if(divider !=0){
            remainAmount = totalAmount % divider;
            individualAmount = (totalAmount - remainAmount) / divider;

            borrower->setMoney(remainAmount - totalAmount);

            for(int i = 0; i < divider; i ++){
                string loan;
                fin >> loan;
                iteratorPeople loaner = find(people.begin(), people.end(), loan);
                loaner->setMoney(individualAmount);
            }

        }
        l++;
        fin >> name >> totalAmount >> divider;
    }
    for(iteratorPeople it = people.begin(); it != people.end(); it++){
        fout << it->getName() << " ";
        fout << it->getMoney() <<"\n";
        cout << it->getName() << " ";
        cout << it->getMoney() <<"\n";
    }

    return 0;
}