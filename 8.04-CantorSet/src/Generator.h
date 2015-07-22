#ifndef H_GENERATOR
#define H_GENERATOR

#include "ofMath.h"

class Generator {
	private:

	public:
		float monteCarlo();
		double gaussian(float my = 0, float sigma = 100);
};

#endif // H_GENERATOR
