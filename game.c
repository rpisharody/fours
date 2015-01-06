#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <algorithm>

#include "rand.h"

using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::cerr;

string get_word(const char* filename, int nWord){
	ifstream is(filename, std::ifstream::in);
	if ( ! is.is_open() ) {
		cerr << "Cannot open " << filename << endl;
		exit (1);
	}

	// Get the size of the file
	is.seekg(0, is.end);
	std::streampos pos = is.tellg();
	int nLine = pos / (nWord + 1);
	int newpos = random (nLine);
	is.seekg(newpos*5, is.beg);
	string Word;
	std::getline (is, Word);
	is.close();
	std::transform (Word.begin(), Word.end(), Word.begin(), ::tolower);
	return (Word);
}

bool analyze(string guessed, string Actual, int nWord) {
	int White = 0, Grey = 0;
	guessed = guessed.substr(0, nWord);
	string::iterator ii = Actual.begin();
	string::iterator jj = guessed.begin();
	while ( ii != Actual.end() ) {
		if (*ii == *jj) {
			*jj = '0';
			*ii = '0';
			++White;
		}
		++jj;
		++ii;
	}
	string tmp;
	for ( jj = guessed.begin(); jj != guessed.end(); ++jj ) {
		if (*jj != '0') 
			tmp += *jj;
	}
	guessed = tmp;
	tmp.clear();
	for ( jj = Actual.begin(); jj != Actual.end(); ++jj ) {
		if (*jj != '0') 
			tmp += *jj;
	}
	Actual = tmp;
	tmp.clear();
	for ( jj = guessed.begin(); jj != guessed.end(); ++jj )
		if ( std::search (Actual.begin(), Actual.end(), jj, jj+1) != Actual.end() )
			++Grey;

	cout << "White : " << White << endl
	     << "Grey  : " << Grey << endl;
	if (White == nWord)
		return false;
	 else 
		return true;
}
