#include "testApp.h"

int allFruitPosition[143][2] = { {40,40},{80,40},{120,40},{160,40},{200,40},{240,40},{280,40},{320,40},{360,40},{400,40},{440,40},
    {480,40},{520,40},{560,40},{600,40},{640,40},{680,40},{720,40},
    
    {40,80},{80,80},{160,80},{200,80},{280,80},{480,80},{560,80},{600,80},{680,80},{720,80},
    
    {40,120},{200,120},{280,120},{320,120},{440,120},{480,120},{560,120},{720,40},
    
    {40,160},{80,160},{120,160},{160,160},{200,160},{320,160},{440,160},{560,160},{600,160},{640,160},
    {680,160},{720,160},
    
    {200,200},{240,200},{280,200},{320,200},{360,200},{400,200},{440,200},{480,200},{520,200},{560,200},
    
    {200,240},{280,240},{400,240},{480,240},{560,240},
    
    {0,280},{40,280},{80,280},{120,280},{160,280},{200,280},{240,280},{280,280},{360,280},{400,280},{480,280},
    {520,280},{560,280},{600,280},{640,280},{680,280},{720,280},{760,280},
    
    {200,320},{280,320},{480,320},{560,320},
    
    {200,360},{240,360},{280,360},{320,360},{360,360},{400,360},{440,360},{480,360},{520,360},{560,360},
    
    {40,400},{80,400},{120,400},{160,400},{200,400},{320,400},{440,400},{560,400},{600,400},{640,400},
    {680,400},{720,400},
    
    {40,440},{200,440},{280,440},{320,440},{440,440},{480,440},{560,440},{720,40},
    
    {40,480},{80,480},{160,480},{200,480},{280,480},{480,480},{560,480},{600,480},{680,480},{720,480},
    
    {40,520},{80,520},{120,520},{160,520},{200,520},{240,520},{280,520},{320,520},{360,520},{400,520},{440,520},
    {480,520},{520,520},{560,520},{600,520},{640,520},{680,520},{720,520},
    
    
};

float pacman_position_x;
float pacman_position_y;
float pacman_radius;
float enemy_position_x;
float enemy_position_y;
float enemy_position_x_middle;
float enemy_position_y_middle;
int CounterForGameOver;

int fruit_apple_position_x[15]={82,122,162,202,242,282,322,362,402,442,482,522,562,602};
int fruit_apple_position_y[15]={82,122,162,202,242,282,322,362,402,442,482,522,562,602};
int fruit_apple_random_position_x;    //----random position in x co-ordinate--------------
int fruit_apple_random_position_y;    //----random position in y co-ordinate--------------
int randindex_apple_x;   //----variable used to store random number for initializing in x co-ordinate-------------
int randindex_apple_y;   //----variable used to store random number for initializing on y co-ordinate-------------
int fr_apple_middle_x;   //----for calculating distance between the apple and the pacman for collison----
int fr_apple_middle_y;   //----same as above-----------------

int fruit_banana_position_x[15]={82,122,162,202,242,282,322,362,402,442,482,522,562,602};
int fruit_banana_position_y[15]={82,122,162,202,242,282,322,362,402,442,482,522,562,602};
int fruit_banana_random_position_x;
int fruit_banana_random_position_y;
int randindex_banana_x;
int randindex_banana_y;
int fr_banana_middle_x;
int fr_banana_middle_y;

int fruit_pear_position_x[15]={82,122,162,202,242,282,322,362,402,442,482,522,562,602};
int fruit_pear_position_y[15]={82,122,162,202,242,282,322,362,402,442,482,522,562,602};
int fruit_pear_random_position_x;
int fruit_pear_random_position_y;
int randindex_pear_x;
int randindex_pear_y;
int fr_pear_middle_x;
int fr_pear_middle_y;

int fruit_cherry_position_x[15]={82,122,162,202,242,282,322,362,402,442,482,522,562,602};
int fruit_cherry_position_y[15]={82,122,162,202,242,282,322,362,402,442,482,522,562,602};
int fruit_cherry_random_position_x;
int fruit_cherry_random_position_y;
int randindex_cherry_x;
int randindex_cherry_y;
int fr_cherry_middle_x;
int fr_cherry_middle_y;

int fruit_strawberry_position_x[15]={82,122,162,202,242,282,322,362,402,442,482,522,562,602};
int fruit_strawberry_position_y[15]={82,122,162,202,242,282,322,362,402,442,482,522,562,602};
int fruit_strawberry_random_position_x;
int fruit_strawberry_random_position_y;
int randindex_strawberry_x;
int randindex_strawberry_y;
int fr_strawberry_middle_x;
int fr_strawberry_middle_y;


int fruit_width;
int fruit_height;




//--------------------------------------------------------------
void testApp::setup(){
    
	fruit_width=40;
	fruit_height=40;
    
    
	//-------randomizing the fruit positions------------------
    /*	 randindex_apple_x = rand() % 14; //---taking a random number from 0-15 and storing it in randindex_apple_x----------
     fruit_apple_random_position_x = fruit_apple_position_x[randindex_apple_x];
	 randindex_apple_y = rand() % 14;
     fruit_apple_random_position_y = fruit_apple_position_y[randindex_apple_y];
     
     
	 randindex_banana_x = rand() % 14;
     fruit_banana_random_position_x = fruit_banana_position_x[randindex_banana_x];
	 randindex_banana_y = rand() % 14;
     fruit_banana_random_position_y = fruit_banana_position_y[randindex_banana_y];
     
     
     randindex_pear_x = rand() % 14;
     fruit_pear_random_position_x = fruit_pear_position_x[randindex_pear_x];
	 randindex_pear_y = rand() % 14;
     fruit_pear_random_position_y = fruit_pear_position_y[randindex_pear_y];
     
     randindex_cherry_x = rand() % 14;
     fruit_cherry_random_position_x = fruit_cherry_position_x[randindex_cherry_x];
	 randindex_cherry_y = rand() % 14;
     fruit_cherry_random_position_y = fruit_cherry_position_y[randindex_cherry_y];
     
	 randindex_strawberry_x = rand() % 14;
     fruit_strawberry_random_position_x = fruit_strawberry_position_x[randindex_strawberry_x];
	 randindex_strawberry_y = rand() % 14;
     fruit_strawberry_random_position_y = fruit_strawberry_position_y[randindex_strawberry_y];
     */
    
    randindex_apple_x = rand() % 143; //---taking a random number from 0-153 and storing it in randindex_apple_x----------
	fruit_apple_random_position_x = allFruitPosition[randindex_apple_x][0];
	fruit_apple_random_position_y = allFruitPosition[randindex_apple_x][1];
    
    
    randindex_banana_x = rand() % 143;
	fruit_banana_random_position_x = allFruitPosition[randindex_banana_x][0];
	fruit_banana_random_position_y = allFruitPosition[randindex_banana_x][1];
    
    
	randindex_pear_x = rand() % 143;
	fruit_pear_random_position_x = allFruitPosition[randindex_pear_x][0];
	fruit_pear_random_position_y = allFruitPosition[randindex_pear_x][1];
    
	randindex_cherry_x = rand() % 143;
	fruit_cherry_random_position_x = allFruitPosition[randindex_cherry_x][0];
	fruit_cherry_random_position_y = allFruitPosition[randindex_cherry_x][1];
    
    randindex_strawberry_x = rand() % 143;
	fruit_strawberry_random_position_x = allFruitPosition[randindex_strawberry_x][0];
	fruit_strawberry_random_position_y = allFruitPosition[randindex_strawberry_x][1];
    
    
    
	fr_apple_middle_x=fruit_apple_random_position_x+20;
	fr_apple_middle_y=fruit_apple_random_position_y+20;
    
	fr_cherry_middle_x=fruit_cherry_random_position_x+20;
	fr_cherry_middle_y=fruit_cherry_random_position_y+20;
    
	fr_pear_middle_x=fruit_pear_random_position_x+20;
	fr_pear_middle_y=fruit_pear_random_position_y+20;
    
	fr_banana_middle_x=fruit_banana_random_position_x+20;
	fr_banana_middle_y=fruit_banana_random_position_y+20;
    
	fr_strawberry_middle_x=fruit_strawberry_random_position_x+20;
	fr_strawberry_middle_y=fruit_strawberry_random_position_y+20;
    
    
    
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
	enemy_position_x_middle = enemy_position_x + 15;
	enemy_position_y_middle = enemy_position_y + 15;
    
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
    
	sleep(5);
    
	
	
	/*if((pacman_position_x == enemy_position_x+12.5) || ( pacman_position_y+7.5 == enemy_position_y) || (pacman_position_y-7.5 == enemy_position_y+25)  || (pacman_position_x -7.5 == enemy_position_x+25) || (pacman_position_y == enemy_position_y+12.5) || (pacman_position_x+7.5 == enemy_position_x) || ( pacman_position_y ==enemy_position_y+12.5)  )
     {
     pacman_position_x = 400;
     pacman_position_y = 500;
     }
     */
    
	ofBackground(0,0,0);
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
    
	if(!fruit_strawberry.loadImage("images/strawberry.png"))
	{
		ofLog(OF_LOG_ERROR,"Error while loading image");
	}
	
	
}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    //MAKING THE ARENA FOR PLAY !---------------------------------------
	
	//rectangular bars BASIC PROPERTIES FOR ALL----------------------------------------------
	ofSetColor(1,1,255);
	ofFill();
    
	//Top right corner rect--------------------
	ofRect(1,1,40,220);
	// just below it ((1))-------------------------
	ofRect(1,201,200,40);
	// another one just below it((2)) ---------------
	ofRect(1,261,200,20);
	//the one that joins ((1)) and ((2))---------
	ofRect(181,241,20,20);
    
	//Bottom right corner rect-----------------
	ofRect(1,380,40,220);
	//just above it ((3))----------------------------
	ofRect(1,360,200,40);
	// another one just above it((4)) --------------
	ofRect(1,321,200,20);
	// joining ((3)) and ((4)) ------------------------
	ofRect(181,341,20,20);
    
	//Top left corner rect ----------------------
	ofRect(760,1,60,220);
	//just below it ((5))---------------------------
	ofRect(600,200,200,40);
	//another one just below it ((6)) ---------------------
	ofRect(600,260,200,20);
	//joining (5)) and ((6))--------------------------
	ofRect(600,240,20,20);
    
	//bottom left corner rect -----------------------
	ofRect(760,380,60,220);
	//just above it ((7)) ---------------------------
	ofRect(600,360,200,40);
	//another one just above it ((8)) ----------------------
	ofRect(600,320,200,20);
	//joining ((7)) and ((8))--------------------------------
	ofRect(600,340,20,20);
    
	//TOP AND BOTTOM RECTANGLES ------------------------------
	ofRect(41,0,720,40);
	ofRect(41,560,720,40);
    
    
	//Rectangles in b/w (bottom right tetris like piece) ----------
	ofRect(80,440,120,40);
	ofRect(120,480,40,40);
	//bottom left tetris like piece -----------------------------
	ofRect(600,440,120,40);
	ofRect(640,480,40,40);
	//top right tetris like piece--------------------------------
	ofRect(80,120,120,40);
	ofRect(120,80,40,40);
	//top left tetris like piece ----------------------------------
	ofRect(600,120,120,40);
	ofRect(640,80,40,40);
    
	//Rectangles in between BOTTOM LEFT  -------------------------------------------
	ofRect(240,400,40,120);
	//TOP LEFT------------------------------------------------------
	ofRect(240,80,40,120);
	//TOP RIGHT----------------------------------------------------
	ofRect(520,80,40,120);
	//BOTTOM RIGHT -------------------------------------------------
	ofRect(520,400,40,120);
    
	//2 BIG 80 X 120 RECT AT THE BOTTOM AND THE TOP--------------------------
	ofRect(360,400,80,120);
	ofRect(360,80,80,120);
    
	//4 cute squares --------------------------------------------------------
	ofRect(240,240,40,40);
	ofRect(240,320,40,40);
	ofRect(520,240,40,40);
	ofRect(520,320,40,40);
    
	//8 squares-----------------------------------------------------------
	ofRect(280,160,40,40);
	ofRect(320,80,40,40);
	ofRect(280,400,40,40);
	ofRect(320,480,40,40);
	ofRect(440,480,40,40);
	ofRect(480,400,40,40);
	ofRect(480,160,40,40);
	ofRect(440,80,40,40);
    
	//middle rectangle with a exit for monsters --------------------------------------------------------
	ofRect(320,240,80,40);
	ofRect(440,240,40,40);
	ofRect(320,320,160,40);
	ofRect(320,280,40,40);
	ofRect(440,280,40,40);
	//------for recording frames per second---------------------------
	ofDrawBitmapString(ofToString(ofGetFrameRate())+"fps", 400, 300);
    
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
    fruit_strawberry.draw(fruit_strawberry_random_position_x,fruit_strawberry_random_position_y,fruit_width,fruit_height);
    
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
            sleep(1.9);
            
            pacman_position_x = 400;
            pacman_position_y = 500;
            
            //adding counter for game over -------------
            
            CounterForGameOver++;
            
            if(CounterForGameOver == 3)
            {
                cout<<"gameover";
                sleep(1.5);
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
    
    
    //---- sounds made by pacman while eating fruits-------------------------------------------------
	if((((pacman_position_x - fr_apple_middle_x)<=30) && ((pacman_position_y - fr_apple_middle_y)<=30) && ((pacman_position_x - fr_apple_middle_x)>= -30) && ((pacman_position_y - fr_apple_middle_y)>= -30)) || (((pacman_position_x - fr_pear_middle_x)<=30) && ((pacman_position_y - fr_pear_middle_y)<=30) && ((pacman_position_x - fr_pear_middle_x)>= -30) && ((pacman_position_y - fr_pear_middle_y)>= -30)) || (((pacman_position_x - fr_cherry_middle_x)<=30) && ((pacman_position_y - fr_cherry_middle_y)<=30) && ((pacman_position_x - fr_cherry_middle_x)>= -30) && ((pacman_position_y - fr_cherry_middle_y)>= -30)) || (((pacman_position_x - fr_banana_middle_x)<=30) && ((pacman_position_y - fr_banana_middle_y)<=30) && ((pacman_position_x - fr_banana_middle_x)>= -30) && ((pacman_position_y - fr_banana_middle_y)>= -30)) || (((pacman_position_x - fr_strawberry_middle_x)<=30) && ((pacman_position_y - fr_strawberry_middle_y)<=30) && ((pacman_position_x - fr_strawberry_middle_x)>= -30) && ((pacman_position_y - fr_strawberry_middle_y)>= -30)))
	{
        mySoundCollideFruit.getIsPlaying();
        mySoundCollideFruit.setMultiPlay(false);
        mySoundCollideFruit.play();
        mySoundCollideFruit.getSpeed();
        mySoundCollideFruit.setSpeed(1.0f);
        mySoundCollideFruit.getSpeed();
        mySoundCollideFruit.getIsPlaying();
        
        if(((pacman_position_x - fr_apple_middle_x)<=30) && ((pacman_position_y - fr_apple_middle_y)<=30) && ((pacman_position_x - fr_apple_middle_x)>= -30) && ((pacman_position_y - fr_apple_middle_y)>= -30))
        {
            fruit_apple.clear();
        }
        if(((pacman_position_x - fr_pear_middle_x)<=30) && ((pacman_position_y - fr_pear_middle_y)<=30) && ((pacman_position_x - fr_pear_middle_x)>= -30) && ((pacman_position_y - fr_pear_middle_y)>= -30))
        {
            fruit_pear.clear();
        }
        if(((pacman_position_x - fr_banana_middle_x)<=30) && ((pacman_position_y - fr_banana_middle_y)<=30) && ((pacman_position_x - fr_banana_middle_x)>= -30) && ((pacman_position_y - fr_banana_middle_y)>= -30))
        {
            fruit_banana.clear();
        }
        if(((pacman_position_x - fr_cherry_middle_x)<=30) && ((pacman_position_y - fr_cherry_middle_y)<=30) && ((pacman_position_x - fr_cherry_middle_x)>= -30) && ((pacman_position_y - fr_cherry_middle_y)>= -30))
        {
            fruit_cherry.clear();
        }
        if(((pacman_position_x - fr_strawberry_middle_x)<=30) && ((pacman_position_y - fr_strawberry_middle_y)<=30) && ((pacman_position_x - fr_strawberry_middle_x)>= -30) && ((pacman_position_y - fr_strawberry_middle_y)>= -30))
        {
            fruit_strawberry.clear();
        }
        
        
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