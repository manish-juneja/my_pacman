#include "testApp.h"

float pacman_position_x;
float pacman_position_y;
float pacman_radius;
float enemy_position_x;
float enemy_position_y;
int CounterForGameOver;

int fruit_apple_position_x[15]={42,82,122,162,202,242,282,322,362,402,442,482,522,562,602};
int fruit_apple_position_y[15]={42,82,122,162,202,242,282,322,362,402,442,482,522,562,602};
int fruit_apple_random_position_x;    //----random position in x co-ordinate--------------
int fruit_apple_random_position_y;    //----random position in y co-ordinate--------------
int randindex_apple_x;   //----variable used to store random number for initializing in x co-ordinate-------------
int randindex_apple_y;   //----variable used to store random number for initializing on y co-ordinate-------------
int fr_apple_middle_x;   //----for calculating distance between the apple and the pacman for collison----
int fr_apple_middle_y;   //----same as above----------------- 

int fruit_banana_position_x[15]={42,82,122,162,202,242,282,322,362,402,442,482,522,562,602};
int fruit_banana_position_y[15]={42,82,122,162,202,242,282,322,362,402,442,482,522,562,602};
int fruit_banana_random_position_x;
int fruit_banana_random_position_y;
int randindex_banana_x;
int randindex_banana_y;
int fr_banana_middle_x;
int fr_banana_middle_y;

int fruit_pear_position_x[15]={42,82,122,162,202,242,282,322,362,402,442,482,522,562,602};
int fruit_pear_position_y[15]={42,82,122,162,202,242,282,322,362,402,442,482,522,562,602};
int fruit_pear_random_position_x;
int fruit_pear_random_position_y;
int randindex_pear_x;
int randindex_pear_y;
int fr_pear_middle_x;
int fr_pear_middle_y;

int fruit_cherry_position_x[15]={42,82,122,162,202,242,282,322,362,402,442,482,522,562,602};
int fruit_cherry_position_y[15]={42,82,122,162,202,242,282,322,362,402,442,482,522,562,602};
int fruit_cherry_random_position_x;
int fruit_cherry_random_position_y;
int randindex_cherry_x;
int randindex_cherry_y;
int fr_cherry_middle_x;
int fr_cherry_middle_y;

int fruit_width;
int fruit_height;

int checkDistance;


//--------------------------------------------------------------
void testApp::setup(){

	fruit_width=40;
	fruit_height=40;


	//-------randomizing the fruit positions------------------
	 randindex_apple_x = rand() % 15; //---taking a random number from 0-15 and storing it in randindex_apple_x----------
	fruit_apple_random_position_x = fruit_apple_position_x[randindex_apple_x];
	 randindex_apple_y = rand() % 15;
	fruit_apple_random_position_y = fruit_apple_position_y[randindex_apple_y];


	 randindex_banana_x = rand() % 15;
	fruit_banana_random_position_x = fruit_banana_position_x[randindex_banana_x];
	 randindex_banana_y = rand() % 15;
	fruit_banana_random_position_y = fruit_banana_position_y[randindex_banana_y];


	randindex_pear_x = rand() % 15;
	fruit_pear_random_position_x = fruit_pear_position_x[randindex_pear_x];
	 randindex_pear_y = rand() % 15;
	fruit_pear_random_position_y = fruit_pear_position_y[randindex_pear_y];

	randindex_cherry_x = rand() % 15;
	fruit_cherry_random_position_x = fruit_cherry_position_x[randindex_cherry_x];
	 randindex_cherry_y = rand() % 15;
	fruit_cherry_random_position_y = fruit_cherry_position_y[randindex_cherry_y];



	fr_apple_middle_x=fruit_apple_random_position_x+20;
	fr_apple_middle_y=fruit_apple_random_position_y+20;

	fr_cherry_middle_x=fruit_cherry_random_position_x+20;
	fr_cherry_middle_y=fruit_cherry_random_position_y+20;

	fr_pear_middle_x=fruit_pear_random_position_x+20;
	fr_pear_middle_y=fruit_pear_random_position_y+20;

	fr_banana_middle_x=fruit_banana_random_position_x+20;
	fr_banana_middle_y=fruit_banana_random_position_y+20;



//----loading sounds of pacman-----------------------------------------------
	mySoundStartGame.loadSound("sounds/pacman_starting_music.mp3");
	mySoundStartGame.setMultiPlay(false);
	
	mySoundMovePacman.loadSound("sounds/pacman_movement.mp3");
	mySoundMovePacman.setMultiPlay(false);

	mySoundCollidePacman.loadSound("sounds/pacman_death.mp3");
	mySoundCollidePacman.setMultiPlay(false);
	// mySoundMovePacman.setLoop(true);

	mySoundCollideFruit.loadSound("sounds/pacman_eatfruit.mp3");
	mySoundCollideFruit.setMultiPlay(false);

	pacman_position_x = 400;
	pacman_position_y = 500;
	pacman_radius = 15;
    enemy_position_x = 375;
	enemy_position_y = 175;

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

	
	
	/*if((pacman_position_x == enemy_position_x+12.5) || ( pacman_position_y+7.5 == enemy_position_y) || (pacman_position_y-7.5 == enemy_position_y+25)  || (pacman_position_x -7.5 == enemy_position_x+25) || (pacman_position_y == enemy_position_y+12.5) || (pacman_position_x+7.5 == enemy_position_x) || ( pacman_position_y ==enemy_position_y+12.5)  )
			{
				pacman_position_x = 400;
				pacman_position_y = 500;
			}
			*/

	ofBackground(0, 0, 00);	
	ofEnableSmoothing();
	ofSetFrameRate(700);

	//---------loading images of fruits -----------------------------
	if(!fruit_apple.loadImage("images/apple.png"))
	{
		ofLog(OF_LOG_ERROR,"Error while loading image");

	}

	if(!fruit_banana.loadImage("images/banana.png"))
	{
		ofLog(OF_LOG_ERROR,"Error while loading image");
	}

	if(!fruit_pear.loadImage("images/pear.png"))
	{
		ofLog(OF_LOG_ERROR,"Error while loading image");
	}
	
	if(!fruit_cherry.loadImage("images/cherry.png"))
	{
		ofLog(OF_LOG_ERROR,"Error while loading image");
	}
	
	
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

	//rectangular bars----------------------------------------------
	ofSetColor(1,1,255,1);
	ofFill();
	ofRect(1,1,53.33,156.52);


	//------for recording frames per second---------------------------
	ofDrawBitmapString(ofToString(ofGetFrameRate())+"fps", 10, 15);

//----------the enemy-----------------------------------------
	ofSetColor(128,128,0);
	ofFill();
	ofRect(enemy_position_x,enemy_position_y,30,30);

//---------the pacman-------------------------------------------
	ofSetColor(128,128,0);
	ofFill();
	ofCircle(pacman_position_x, pacman_position_y ,pacman_radius);
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
	ofCircle(enemy_position_x, enemy_position_y+15 ,1);

	ofSetColor(127,255,0);
	ofFill();
	ofCircle(enemy_position_x+15, enemy_position_y ,1);

	ofSetColor(127,255,0);
	ofFill();
	ofCircle(enemy_position_x+30, enemy_position_y+15 ,1);

	ofSetColor(127,255,0);
	ofFill();
	ofCircle(enemy_position_x+15, enemy_position_y+30 ,1);

	ofSetColor(127,255,0);
	ofFill();
	ofCircle(pacman_position_x+15, pacman_position_y ,1);
	
	ofSetColor(127,255,0);
	ofFill();
	ofCircle(pacman_position_x-15, pacman_position_y ,1);

	ofSetColor(127,255,0);
	ofFill();
	ofCircle(pacman_position_x, pacman_position_y+15 ,1);
	
	ofSetColor(127,255,0);
	ofFill();
	ofCircle(pacman_position_x, pacman_position_y-15 ,1);
	
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
fruit_apple.draw(fruit_apple_random_position_x,fruit_apple_random_position_y,fruit_width,fruit_height);
fruit_banana.draw(fruit_banana_random_position_x,fruit_banana_random_position_y,fruit_width,fruit_height);
fruit_pear.draw(fruit_pear_random_position_x,fruit_pear_random_position_y,fruit_width,fruit_height);
fruit_cherry.draw(fruit_cherry_random_position_x,fruit_cherry_random_position_y,fruit_width,fruit_height);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{

	 if((key == 'w') || (key == 'W') || (key == 's') || (key == 'S') || (key == 'A') || (key == 'a') || (key == 'd') || (key == 'D')) 
		{
		/*	if((pacman_position_x == enemy_position_x+12.5) || ( pacman_position_y+7.5 == enemy_position_y) || (pacman_position_y-7.5 == enemy_position_y+25)  || (pacman_position_x -7.5 == enemy_position_x+25) || (pacman_position_y == enemy_position_y+12.5) || (pacman_position_x+7.5 == enemy_position_x) || ( pacman_position_y ==enemy_position_y+12.5)  )
			{
				pacman_position_x = 400;
				pacman_position_y = 500;
			}

 */		//--- loop for simple collision detetction---------------------

			 if(((pacman_position_x+15 == enemy_position_x) && ( pacman_position_y == enemy_position_y+15)) || ((pacman_position_x-15 == enemy_position_x+30) && ( pacman_position_y == enemy_position_y+15)) || ((pacman_position_x == enemy_position_x+15) && ( pacman_position_y-15 == enemy_position_y+30)) || ((pacman_position_x == enemy_position_x+15) && ( pacman_position_y+15 == enemy_position_y))   )
			 {
				 // if collision takes place play this sound ------

					mySoundCollidePacman.getIsPlaying();//Returns false
						mySoundCollidePacman.setMultiPlay(false);
						mySoundCollidePacman.setSpeed(1.0f);  // sets speed of sound. I had to make sure its not fast
						mySoundCollidePacman.play();	
						mySoundCollidePacman.getSpeed(); //					
						mySoundCollidePacman.setSpeed(1.0f);
						mySoundCollidePacman.getSpeed();
					mySoundCollidePacman.getIsPlaying();// returns true if sound is playing 

//------wait for 1900 microseconds for the sound to play and then reposition pacman on required (x,y)------------
					Sleep(1900);

					pacman_position_x = 400;
					pacman_position_y = 500;

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
	if((((pacman_position_x - fr_apple_middle_x)<=30) && ((pacman_position_y - fr_apple_middle_y)<=30) && ((pacman_position_x - fr_apple_middle_x)>= -30) && ((pacman_position_y - fr_apple_middle_y)>= -30)) || (((pacman_position_x - fr_pear_middle_x)<=30) && ((pacman_position_y - fr_pear_middle_y)<=30) && ((pacman_position_x - fr_pear_middle_x)>= -30) && ((pacman_position_y - fr_pear_middle_y)>= -30)) || (((pacman_position_x - fr_cherry_middle_x)<=30) && ((pacman_position_y - fr_cherry_middle_y)<=30) && ((pacman_position_x - fr_cherry_middle_x)>= -30) && ((pacman_position_y - fr_cherry_middle_y)>= -30)) || (((pacman_position_x - fr_banana_middle_x)<=30) && ((pacman_position_y - fr_banana_middle_y)<=30) && ((pacman_position_x - fr_banana_middle_x)>= -30) && ((pacman_position_y - fr_banana_middle_y)>= -30)) )
	{
            mySoundCollideFruit.getIsPlaying();
            mySoundCollideFruit.setMultiPlay(false);
            mySoundCollideFruit.play();
            mySoundCollideFruit.getSpeed();
            mySoundCollideFruit.setSpeed(1.0f);
            mySoundCollideFruit.getSpeed();
            mySoundCollideFruit.getIsPlaying();
	}

	 if((key == 'w') || (key == 'W'))
	 {
 
			if(pacman_position_y < -7.5)
			{
				pacman_position_y=pacman_position_y+607.5;
			}

			else	{	
				pacman_position_y = pacman_position_y - 5;
			}
			    
			
		}
 
 if((key =='s') || (key =='S')) // 's' key
		{
			
			if(pacman_position_y > 607.5)
			{
				pacman_position_y = pacman_position_y -607.5;
			}
			else
			{
				pacman_position_y = pacman_position_y + 5;
			}

		
		}
 
 if((key =='d') || (key =='D')) // 'd' key
		{
			if(pacman_position_x > 807.5)
			{
				pacman_position_x = pacman_position_x -807.5;
			}
			else
			{
				pacman_position_x = pacman_position_x + 5;
			}
		}
 
 if((key=='a') || (key == 'A')) // 'a' key
		{
			if(pacman_position_x < -7.5)
			{
				pacman_position_x = pacman_position_x + 807.5;
			}
			else
			{
				pacman_position_x = pacman_position_x - 5;
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