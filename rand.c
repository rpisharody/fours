#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random(const int& lim) {

	// Seed the random number generator
	srand(time(NULL));

	// Now return the value
	return (rand() % lim);
}
