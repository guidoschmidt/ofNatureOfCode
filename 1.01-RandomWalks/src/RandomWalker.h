#ifndef H_RANDOMWALKER
#define H_RANDOMWALKER

#include <iostream>
#include "ofGraphics.h"

using namespace std;

class RandomWalker {
	private:
		int m_x;
		int m_y;
		int m_randomCounts[20];
		void *_walkStrategy();
		void defaultStrategy();

	public:
		RandomWalker(unsigned int width = 1024,
					 unsigned int height = 768);
		void step(void (*function)(int&, int&));
		void draw(int mouseX, int mouseY);
};

#endif // H_RANDOMWALKER


