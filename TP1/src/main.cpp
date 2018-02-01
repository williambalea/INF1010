/* 
 * File:   main.cpp
 * Author: bram
 *
 * Created on November 8, 2015, 8:39 PM
 */

#include <iostream>
#include "HashMap.h"

using namespace std;

/* */

void readFile(string NomFichier){
	ifstream file;
	file.open(NomFichier);
	string word;
	char x;
	word.clear();

	while (file >> word){
		x = file.get();

		while (x != ' '){
			word = word + x;
			x = file.get();
		}

		cout << word << endl;
		word.clear();
	}
}

int main(int argc, char** argv, string nomFichier) {
	readFile(nomFichier);

	//utilisation normale
	HashMap hmap;
	hmap.put("v1", 1);
	hmap.put("v3", 1);
	hmap.put("v11", 1);
	hmap.put("v13", 13);

	int value;
	bool res = hmap.get("v13", value);
	if (res)
		cout << value << endl;

	hmap.remove("v1");
	res = hmap.get("v1", value);
	if (res)
		cout << "ERROR: " << value << endl;

	std::vector<std::string> keys = hmap.getKeys();
	for (int i = 0; i < keys.size(); i++) {
		cout << keys[i] << endl;
	}

	return 0;
}

