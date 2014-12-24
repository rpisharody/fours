#include <iostream>
#include <string>
#include "game.h"


using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::string;

int main (int argc, char *argv[]) {
	if (argc < 2) {
		cerr << "Usage : " << argv[0] << " <filename>" << endl;
		return 1;
	}

	string Word = get_word(argv[1], 4);
	cout << "I have a word in my mind." << endl;
	cout << "What would you guess : " ; 
	string guess; cin >> guess;
	while ( analyze(guess, Word) ) {
		cout << "Not quite. What else ? ";
		cin >> guess;
	}

	cout << "Congratulations ... " << endl;
	return 0;
}
