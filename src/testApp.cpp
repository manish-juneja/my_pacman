#include "testApp.h"

float p_x;
float p_y;
float p_r;
float e_x;
float e_y;
int CounterForGameOver;

//--------------------------------------------------------------
void testApp::setup(){

	mySoundStartGame.loadSound("sounds/pacman_starting_music.mp3");
	mySoundStartGame.setMultiPlay(false);
	
	mySoundMovePacman.loadSound("sounds/pacman_movement.mp3");
	mySoundMovePacman.setMultiPlay(false);

	mySoundCollide.loadSound("sounds/pacman_death.mp3");
	mySoundMovePacman.setMultiPlay(false);
	// mySoundMovePacman.setLoop(true);

	p_x = 400;
	p_y = 500;
	p_r = 15;
    e_x = 375;
	e_y = 175;

	CounterForGameOver=0;

	mySoundStartGame.getIsPlaying(); //Returns false   
		mySoundStartGame.setMultiPlay(false);
		mySoundStartGame.getSpeed();
		mySoundStartGame.setSpeed(1.0f);
		mySoundStartGame.getSpeed();
		mySoundStartGame.play();
	mySoundStartGame.getIsPlaying();

	if(!my_img.loadImage("images/pacman_logo.gif"))
	{

        ofLog(OF_LOG_ERROR,"Errorwhileloadingimage");
	}

	my_img.draw(500,227,ofGetWidth(),ofGetHeight());

	Sleep(5000);

	
	
	/*if((p_x == e_x+12.5) || ( p_y+7.5 == e_y) || (p_y-7.5 == e_y+25)  || (p_x -7.5 == e_x+25) || (p_y == e_y+12.5) || (p_x+7.5 == e_x) || ( p_y ==e_y+12.5)  )
			{
				p_x = 400;
				p_y = 500;
			}
			*/

	ofBackground(1, 1, 100);	
	ofEnableSmoothing();
	ofSetFrameRate(700);
	
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

	ofDrawBitmapString(ofToString(ofGetFrameRate())+"fps", 10, 15);

	ofSetColor(128,128,0);
	ofFill();
	ofRect(e_x,e_y,30,30);

	ofSetColor(128,128,0);
	ofFill();
	ofCircle(p_x, p_y ,p_r);
	///------------------------copied code---
	 for (int i = 1; i < 20; i++) {
		for (int j = 1; j < 15; j++) {
			
		/*	float r = ofRandom(0, 255);
			float g = ofRandom(0, 128);
			float b = ofRandom(128, 255);b 

			float r = 128;
			float g = 128;
			float b =0;

			*/
			ofSetColor(128, 128, 0);
			ofFill();
			ofCircle(i*40, j*40, 1);
			ofNoFill();
			ofCircle(i*40, j*40, 1);
			
		}
	} 
	///----upper code copied to setup-------------

//--- for testing only  till line ()

	ofSetColor(127,255,0);
	ofFill();
	ofCircle(e_x, e_y+15 ,1);

	ofSetColor(127,255,0);
	ofFill();
	ofCircle(e_x+15, e_y ,1);

	ofSetColor(127,255,0);
	ofFill();
	ofCircle(e_x+30, e_y+15 ,1);

	ofSetColor(127,255,0);
	ofFill();
	ofCircle(e_x+15, e_y+30 ,1);

	ofSetColor(127,255,0);
	ofFill();
	ofCircle(p_x+15, p_y ,1);
	
	ofSetColor(127,255,0);
	ofFill();
	ofCircle(p_x-15, p_y ,1);

	ofSetColor(127,255,0);
	ofFill();
	ofCircle(p_x, p_y+15 ,1);
	
	ofSetColor(127,255,0);
	ofFill();
	ofCircle(p_x, p_y-15 ,1);
	
//-- testing code over ----------------------------
	
	//--starting music-----------------------------

/*	mySoundStartGame.getIsPlaying(); //Returns false   
		mySoundStartGame.setMultiPlay(false);
		mySoundStartGame.getSpeed();
		mySoundStartGame.setSpeed(1.0f);
		mySoundStartGame.getSpeed();
		mySoundStartGame.play();
	mySoundStartGame.getIsPlaying();

	Sleep(5000);

	*/
  //--------------------------------------------------
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{

	 if((key == 'w') || (key == 'W') || (key == 's') || (key == 'S') || (key == 'A') || (key == 'a') || (key == 'd') || (key == 'D')) 
		{
		/*	if((p_x == e_x+12.5) || ( p_y+7.5 == e_y) || (p_y-7.5 == e_y+25)  || (p_x -7.5 == e_x+25) || (p_y == e_y+12.5) || (p_x+7.5 == e_x) || ( p_y ==e_y+12.5)  )
			{
				p_x = 400;
				p_y = 500;
			}

 */		//--- loop for simple collision detetction---------------------

			 if(((p_x+15 == e_x) && ( p_y == e_y+15)) || ((p_x-15 == e_x+30) && ( p_y == e_y+15)) || ((p_x == e_x+15) && ( p_y-15 == e_y+30)) || ((p_x == e_x+15) && ( p_y+15 == e_y))   )
			 {
				 // if collision takes place play this sound ------

					mySoundCollide.getIsPlaying();//Returns false
						mySoundCollide.setMultiPlay(false);
						mySoundCollide.setSpeed(1.0f);  // sets speed of sound. I had to make sure its not fast
						mySoundCollide.play();	
						mySoundCollide.getSpeed(); //					
						mySoundCollide.setSpeed(1.0f);
						mySoundCollide.getSpeed();
					mySoundCollide.getIsPlaying();// returns true if sound is playing 

//------wait for 1900 microseconds for the sound to play and then repostion pacman on required (x,y)------------
					Sleep(1900);

					p_x = 400;
					p_y = 500;

					//adding counter for game over -------------

					CounterForGameOver++;

					if(CounterForGameOver == 3)
					{
						cout<<"gameover";
						Sleep(1500);
						abort();
					}
			}
		  
		
//-- sounds made by pacman while moving --- ------------------------          
			mySoundMovePacman.getIsPlaying();
			mySoundMovePacman.setMultiPlay(false);//Returns false   
			mySoundMovePacman.play();   
			mySoundMovePacman.play(); ////Adds new copy of sound to channel and plays over currently playing sound
			mySoundMovePacman.getSpeed();
			mySoundMovePacman.setSpeed(1.0f);
			mySoundMovePacman.getSpeed();
			mySoundMovePacman.getIsPlaying();

	}

	 if((key == 'w') || (key == 'W'))
	 {
 
			if(p_y < -7.5)
			{
				p_y=p_y+607.5;
			}

			else	{	
				p_y = p_y - 5;
			}
			    
			
		}
 
 if((key =='s') || (key =='S')) // 's' key
		{
			
			if(p_y > 607.5)
			{
				p_y = p_y -607.5;
			}
			else
			{
				p_y = p_y + 5;
			}

		
		}
 
 if((key =='d') || (key =='D')) // 'd' key
		{
			if(p_x > 807.5)
			{
				p_x = p_x -807.5;
			}
			else
			{
				p_x = p_x + 5;
			}
		}
 
 if((key=='a') || (key == 'A')) // 'a' key
		{
			if(p_x < -7.5)
			{
				p_x = p_x + 807.5;
			}
			else
			{
				p_x = p_x - 5;
			}
			
		}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}