#pragma once

#include <ctime>

#include "ofMain.h"


class testApp : public ofBaseApp{
	public:

		ofSoundPlayer mySoundMovePacman;
		ofSoundPlayer mySoundCollidePacman;
		ofSoundPlayer mySoundStartGame;
		ofSoundPlayer mySoundCollideFruit;

		     ofImage  my_img;
			 ofImage  fruit_apple;
			 ofImage fruit_banana;
			 ofImage fruit_pear;
			 ofImage fruit_cherry;
			 ofImage fruit_strawberry;
			 
			 


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
