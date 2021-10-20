#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;
class Person{
public:
    Person(string na){name: na; debts : 0;};
    void loan(int);
    int getDebts();

private:
    string name;
    int debts;
};

void Person::loan(int money) {
    this->debts += money;
}

int Person::getDebts() {
    return this->debts;
}
typedef std::vector<Person> PersonList;
int main() {
    PersonList personList;
    PersonList::iterator it = personList.begin();
    FILE *fp;
    char giftIn[255];
    fp = fopen("gift1.in","r");
    if(fp == NULL){
        int numberOfPerson = 0;
        fgets(giftIn,2,(FILE*)fp);   // number of people in this list
        numberOfPerson = atoi(giftIn);
        // for loop for adding the people into peopleList vector
        for(int i =0; i < numberOfPerson;i++){
            char newName[255];
            fgets(newName,255,fp);
            string strName(newName);
            Person newPerson(strName);
            personList.push_back(newPerson);
        }

        int money, Num_people;
        fscanf(fp,"%d %d", money, Num_people);
        cout << "money is " << money << endl;
        cout << "How many people : " << Num_people << endl;
            // find out how much money each transaction takes for borrowers
            // find out the total money for the loaner

            //find the loaner and set loan to it's debts

            //find the borrower and set debts

        //print the debts with format of (%s\t%s, name, debts)
    }

    fclose(fp);

    return 0;
}