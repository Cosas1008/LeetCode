/*
ID: yuweiic1
LANG: C++
TASK: namenum
*/
#include <iostream>
#include <fstream>

using namespace std;

string touchmapping(const string &);

int main()
{
	ifstream fin("namenum.in"), dict("dict.txt");
	
	string namenum;
	fin >> namenum;
	
	fin.close();

	string name;
	bool found = false;
	ofstream fout("namenum.out");

	while(dict >> name){
		if(namenum.length() == name.length() && touchmapping(name) == namenum){
			fout << name << endl;
			found = true;
		}
	}

	if(!found) fout << "NONE" << endl;

	dict.close();
	fout.close();

	return 0;
}


// ref from https://usaco-cpp.blogspot.com/2012/03/problem-29-name-that-number.html
// good method
string touchmapping(const string &name)
{
	string serial = "";
	for(int i = 0; i < name.length(); ++i){
		if(name[i] == 'Q' || name[i] == 'Z'){
			return "1";
		}
		if(name[i] < 'Q'){
			serial += ((name[i] - 'A') / 3) + '2';
		}
		else{
			serial += ((name[i] - 'Q') / 3) + '7';
		}
	}
	return serial;
}