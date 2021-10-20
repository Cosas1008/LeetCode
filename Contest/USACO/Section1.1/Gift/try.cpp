#include <stdio.h>


using namespace std;

class People
{
public:
	People(string nameIn){name: nameIn; debts : 0};
	void inputMoney(int money);
	void printOut(string nameIn);
private:
	string name;
	int debts;
}

People::inputMoney(int money){
	this.debts += money;
}

People::printOut(string nameIn){

}

typedef templete<T> map<string name, T> PeopleList;

int main()
{
	//gift.in
	FILE *fin, *fout;
	int numOfPeople;
	fin = fopen("gift1.in","r");	// r+?
	if(fin == NULL){
		perror("Error while opening the file.");
		exit(EXIT_FAILURE);
	}else{
		fscanf(fin,"%d\n",numOfPeople);
	}
	for(int i =0; i < numOfPeople; i ++){
		string name;
		fscanf(fin,"%s", name);
		People newPeople(name);
		PeopleList.at(i) = newPeople;
	}

}