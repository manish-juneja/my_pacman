#pragma once

#include <ctime>

#include "ofMain.h"


class testApp : public ofBaseApp{
	public:

		ofSoundPlayer mySoundMovePacman;
		ofSoundPlayer mySoundCollide;
		ofSoundPlayer mySoundStartGame;
		     ofImage  my_img;


		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		
};
