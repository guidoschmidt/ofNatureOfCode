#include "Generator.h"

float Generator::monteCarlo() {
	while (true) {
		float randomOne = ofRandom(1);
		float probability = randomOne;
		float randomTwo = ofRandom(1);
		if (randomTwo > probability) {
			return randomOne;
		}
	}
}

double Generator::gaussian(float my, float sigma) {
	return my + (sigma * monteCarlo());
}
