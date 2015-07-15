#include "RandomWalker.h"

RandomWalker::RandomWalker(unsigned int width, unsigned int height) {
	m_x = width/2;
	m_y = height/2;
	m_randomCounts[20] = {20};
	fill(m_randomCounts, m_randomCounts+sizeof(m_randomCounts)/sizeof(int), 0);
}

//--- Walking strategies
void RandomWalker::defaultStrategy() {
	//--- Every directionis equaly weighted ---
	int stepm_x = (rand() % 3) - 1;
	int stepy = (rand() % 3) - 1;
	m_x += stepm_x;
	m_y += stepy;
}


void RandomWalker::step(void (*function)(int&, int&)) {
	if(!function)
		defaultStrategy();
	else
		// Call step function
		function(m_x, m_y);
}

void RandomWalker::draw(int mouseX, int mouseY) {
	ofSetColor(0, 0, 0);
	ofCircle(m_x, m_y, 2);

	int index =  (int)( rand() % 19 );
	const int arrayLength = sizeof(m_randomCounts)/sizeof(int);
	m_randomCounts[index]++;
	ofSetColor(200, 45, 110);
	int w = 1024/(arrayLength-1);

	for(unsigned int i=0; i < arrayLength; ++i) {
		ofSetColor(i*12, 45, 110);
		ofRect(i*w, 0, w-2, m_randomCounts[i]);
	}
}
