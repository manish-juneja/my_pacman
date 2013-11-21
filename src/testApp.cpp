#include "testApp.h"


// declaring the vector that might do the job of doing the dynamic array but not used till now ........

vector<vector<vector<float> > > phantom_energy (157, vector<vector<float> > (20, vector<float> (2)));

//all the positions that the fruits may be placed in ,that is the black spaces....a random generator is going to pick on of these coordinates and place the fruit there
int allFruitPosition[143][2] = {{40,40},{80,40},{120,40},{160,40},{200,40},{240,40},{280,40},{320,40},{360,40},{400,40},{440,40},
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

// all the walls that are present in the game that is the blue spaces that are present in the area of the pacman playground ....

int allWallPositions [157][2] = {
    
    {20,20},{60,20},{100,20},{140,20},{180,20},{220,20},{260,20},{300,20},{340,20},{380,20},{420,20},{460,20},{500,20},{540,20},{580,20},{620,20},{660,20},{700,20},{740,20},{780,20},
    
    {20,60},{780,60},
    
    {20,100},{140,100},{260,100},{340,100},{380,100},{420,100},{460,100},{540,100},{660,100},{780,100},
    
    {20,140},{100,140},{140,140},{180,140},{260,140},{380,140},{420,140},{540,140},{620,140},{660,140},{700,140},{780,140},
    
    {20,180},{260,180},{300,180},{380,180},{420,180},{500,180},{540,180},{780,180},
    
    {20,220},{60,220},{100,220},{140,220},{180,220},{620,220},{660,220},{700,220},{740,220},{780,220},
    
    {20,260},{60,260},{100,260},{140,260},{180,260},{260,260},{340,260},{380,260},{460,260},{540,260},{620,260},{660,260},{700,260},{740,260},{780,260},
    
    {340,300},{460,300},
    
    {20,340},{60,340},{100,340},{140,340},{180,340},{260,340},{340,340},{380,340},{420,340},{460,340},{540,340},{620,340},{660,340},{700,340},{740,340},{780,340},
    
    {20,380},{60,380},{100,380},{140,380},{180,380},{620,380},{660,380},{700,380},{740,380},{780,380},
    
    {20,420},{260,420},{300,420},{380,420},{420,420},{500,420},{540,420},{780,420},
    
    {20,460},{100,460},{140,460},{180,460},{260,460},{380,460},{420,460},{540,460},{620,460},{660,460},{700,460},{780,460},
    
    {20,500},{140,500},{260,500},{340,500},{380,500},{420,500},{460,500},{540,500},{660,500},{780,500},
    
    {20,540},{780,540},
    
    {20,580},{60,580},{100,580},{140,580},{180,580},{220,580},{260,580},{300,580},{340,580},{380,580},{420,580},{460,580},{500,580},{540,580},{580,580},{620,580},{660,580},{700,580},{740,580},{780,580}
    
    
};

int flag ;

// some 3d array to define all the wall coordinates  that may come in use in future if the above array is not working ...
//the third dimension is the row number
//there are total 153X2 co-ordinates that are arranged in X x Y x Z
//The z co-ordinate can hold upto 20 values as u imagined and u wanted to make it dynamic so that you can store values 2 to 20 as desired

int xxx[15][20][3] = {
    
    { {0,0,0},{40,0,0},{80,0,0},{120,0,0},{160,0,0},{200,0,0},{240,0,0},{280,0,0},{320,0,0},{360,0,0},{400,0,0},{440,0,0},{480,0,0},{520,0,0},{560,0,0},{600,0,0},{640,0,0},{680,0,0},{720,0,0},{760,0,0}},
    
    { {0,1,40},{760,1,40}},
    
    {{0,2,80},{120,2,80},{240,2,80},{320,2,80},{360,2,80},{400,2,80},{440,2,80},{520,2,80},{640,2,80},{760,2,80}},
    
    {{0,3,120},{80,3,120},{120,3,120},{160,3,120},{240,3,120},{360,3,120},{400,3,120},{520,3,120},{600,3,120},{640,3,120},{680,3,120},{760,3,120}},
    
    {{0,4,160},{240,4,160},{280,4,160},{360,4,160},{400,4,160},{480,4,160},{520,4,160},{760,4,160}},
    
    {{0,5,200},{40,5,200},{80,5,200},{120,5,200},{160,5,200},{600,5,200},{640,5,200},{680,5,200},{720,5,200},{760,5,200}},
    
    {{0,6,240},{40,6,240},{80,6,240},{120,6,240},{160,6,240},{240,6,240},{320,6,240},{360,6,240},{440,6,240},{520,6,240},{600,6,240},{640,6,240},{680,6,240},{720,6,240},{760,6,240}},
    
    {{320,7,280},{440,7,280}},
    
    {{0,8,320},{40,8,320},{80,8,320},{120,8,320},{160,8,320},{240,8,320},{320,8,320},{360,8,320},{400,8,320},{440,8,320},{520,8,320},{600,8,320},{640,8,320},{680,8,320},{720,8,320},{760,8,320}},
    
    {{0,9,360},{40,9,360},{80,9,360},{120,9,360},{160,9,360},{600,9,360},{640,9,360},{680,9,360},{720,360},{760,360}},
    
    {{0,10,400},{240,10,400},{280,10,400},{360,10,400},{400,10,400},{480,10,400},{520,10,400},{760,10,400}},
    
    {{0,11,440},{80,11,440},{120,11,440},{160,11,440},{240,11,440},{360,11,440},{400,11,440},{520,11,440},{600,11,440},{640,11,440},{680,11,440},{760,11,440}},
    
    {{0,12,480},{120,12,480},{240,12,480},{320,12,480},{360,12,480},{400,12,480},{440,12,480},{520,12,480},{640,12,480},{760,480}},
    
    {{0,13,520},{760,13,520}},
    
    {{0,14,560},{40,14,560},{80,14,560},{120,14,560},{160,14,560},{200,14,560},{240,14,560},{280,14,560},{320,14,560},{360,14,560},{400,14,560},{440,14,560},{480,14,560},{520,14,560},{560,14,560},{600,14,560},{640,14,560},{680,14,560},{720,14,560},{760,14,560}},
    
    
};





float pacman_position_x;
float pacman_position_y;
float pacman_radius;

float coordinate_y_up;
float coordinate_y_down;
float coordinate_x_left;
float coordinate_x_right;
float coordinate_x_up;
float coordinate_x_down;
float coordinate_y_left;
float coordinate_y_right;

float enemy_position_x;
float enemy_position_y;
float enemy_position_x_middle;
float enemy_position_y_middle;

float enemy_x_up;
float enemy_y_up;
float enemy_x_left;
float enemy_y_left;
float enemy_x_right;
float enemy_y_right;
float enemy_x_down;
float enemy_y_down;

int CounterForGameOver;

int x_checker_1;
int x_checker_2;
int y_checker_1;
int y_checker_2;

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

int choice;




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
    
	pacman_position_x = 420;
	pacman_position_y = 540;
	pacman_radius     = 20;
    
    coordinate_x_left  = pacman_position_x - 40;
    coordinate_x_right = pacman_position_x + 40;
    coordinate_y_down  = pacman_position_y + 40;
    coordinate_y_up    = pacman_position_y - 40;
    
    enemy_position_x = 360;
	enemy_position_y = 200;
	enemy_position_x_middle = enemy_position_x + 20;
	enemy_position_y_middle = enemy_position_y + 20;
    
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
    
    
	my_img.draw(500,227,800,600);// this is not working
    
	sleep(5);
    
	
	
	/*if((pacman_position_x == enemy_position_x+12.5) || ( pacman_position_y+7.5 == enemy_position_y) || (pacman_position_y-7.5 == enemy_position_y+25)  || (pacman_position_x -7.5 == enemy_position_x+25) || (pacman_position_y == enemy_position_y+12.5) || (pacman_position_x+7.5 == enemy_position_x) || ( pacman_position_y ==enemy_position_y+12.5)  )
     {
     pacman_position_x = 400;
     pacman_position_y = 500;
     }
     */
    
	ofBackground(0,0,0);
	ofEnableSmoothing();
	ofSetFrameRate(24);
    
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
    
    
    /*  for (y_checker_1 = 0; y_checker_1 < 157; y_checker_1++)
     {
     
     if(((allWallPositions[y_checker_1][1] + 20) == coordinate_y_up) && ((allWallPositions[y_checker_1][0]+20) ==pacman_position_x))
     {
     flag =1;
     ofDrawBitmapString("unmatched",830,140);
     
     }
     else
     {
     
     ofDrawBitmapString("matched", 830,140);
     
     flag = 0;
     
     
     }
     }*/
    
    coordinate_x_left   = pacman_position_x - 40;
    coordinate_x_right  = pacman_position_x + 40;
    coordinate_y_down   = pacman_position_y + 40;
    coordinate_y_up     = pacman_position_y - 40;
    coordinate_x_up     = pacman_position_x;
    coordinate_x_down   = pacman_position_x;
    coordinate_y_left   = pacman_position_y;
    coordinate_y_right  = pacman_position_y;
    
    
    enemy_position_x_middle = enemy_position_x + 20;
    enemy_position_y_middle = enemy_position_y + 20;
    
    enemy_x_up    =   enemy_position_x_middle;
    enemy_x_down  =   enemy_position_x_middle;
    enemy_y_left  =   enemy_position_y_middle;
    enemy_y_right =   enemy_position_y_middle;
    enemy_x_left  =   enemy_position_x_middle - 40;
    enemy_x_right =   enemy_position_x_middle + 40;
    enemy_y_up    =   enemy_position_y_middle - 40;
    enemy_y_down  =   enemy_position_y_middle + 40;
    
    
    choice = ofRandom(0,4);
    
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
	//------for recording frames per second///----//debug area ---------------------------
    ofDrawBitmapString("####################", 830, 20);
    ofDrawBitmapString("##   debug area   ##", 830, 35);
    ofDrawBitmapString("####################", 830, 50);
    
    
    
	ofDrawBitmapString(ofToString(ofGetFrameRate())   + " fps", 830, 75);
    ofDrawBitmapString(ofToString(pacman_position_x)  + " pacmam_X_co-ordinate", 830, 90);
    ofDrawBitmapString(ofToString(pacman_position_y)  + " pacman_Y_co-ordinate", 830, 105);
    ofDrawBitmapString(ofToString(coordinate_y_up)    + " upper_y_pacman", 830, 120);
    ofDrawBitmapString(ofToString(coordinate_x_up)    + " upper_x_pacman", 830, 135);
    ofDrawBitmapString(ofToString(coordinate_y_right) + " right_y_pacman", 830, 150);
    ofDrawBitmapString(ofToString(flag)               + " flag", 830, 165);
    
    // ofDrawBitmapString(ofToString(allWallPositions[y_checker_1][1]), 830,135);
    
    // ofDrawBitmapString(ofToString(coordinate_y_up), 760,280);
    
    //----------the enemy-----------------------------------------
    
	ofSetColor(128,128,0);
	ofFill();
	ofRect(enemy_position_x,enemy_position_y,40,40);
    
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
	ofCircle(enemy_position_x, enemy_position_y+20 ,1);
    
	ofSetColor(127,255,0);
	ofFill();
	ofCircle(enemy_position_x+20, enemy_position_y ,1);
    
	ofSetColor(127,255,0);
	ofFill();
	ofCircle(enemy_position_x+40, enemy_position_y+20 ,1);
    
	ofSetColor(127,255,0);
	ofFill();
	ofCircle(enemy_position_x+20, enemy_position_y+40 ,1);
    
	ofSetColor(127,255,0);
	ofFill();
	ofCircle(pacman_position_x+20, pacman_position_y ,1);
	
	ofSetColor(127,255,0);
	ofFill();
	ofCircle(pacman_position_x-20, pacman_position_y ,1);
    
	ofSetColor(127,255,0);
	ofFill();
	ofCircle(pacman_position_x, pacman_position_y+20 ,1);
	
	ofFill();
	ofCircle(pacman_position_x, pacman_position_y-20 ,1);
	
    //-- testing code over ----------------------------
	
	//--starting music-----------------------------
    
    /*	mySoundStartGame.getIsPlaying(); //Returns false
     mySoundStartGame.setMultiPlay(false);
     mySoundStartGame.getSpeed();
     mySoundStartGame.setSpeed(1.0f);
     mySoundStartGame.getSpeed();
     mySoundStartGame.play();
     mySoundStartGame.getIsPlaying();
     
     Sleep(5);
     
     */
    //--------------------------------------------------
    
    fruit_apple.     draw (fruit_apple_random_position_x, fruit_apple_random_position_y, fruit_width,fruit_height);
    fruit_banana.    draw (fruit_banana_random_position_x, fruit_banana_random_position_y, fruit_width,fruit_height);
    fruit_pear.      draw (fruit_pear_random_position_x, fruit_pear_random_position_y, fruit_width,fruit_height);
    fruit_cherry.    draw (fruit_cherry_random_position_x, fruit_cherry_random_position_y, fruit_width,fruit_height);
    fruit_strawberry.draw (fruit_strawberry_random_position_x, fruit_strawberry_random_position_y, fruit_width,fruit_height);
    
    /*if(choice == 0)
     {
     enemy_position_x = enemy_position_x +40;
     }
     else if (choice == 1)
     {
     enemy_position_x = enemy_position_x -40;
     }
     else if (choice == 2)
     {
     enemy_position_y = enemy_position_y -40;
     }
     else if (choice == 3)
     {
     enemy_position_y =enemy_position_y +40;
     }*/
    
    
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
        
        // if(((pacman_position_x+15 == enemy_position_x) && ( pacman_position_y == enemy_position_y+15)) || ((pacman_position_x-15 == enemy_position_x+30) && ( pacman_position_y == enemy_position_y+15)) || ((pacman_position_x == enemy_position_x+15) && ( pacman_position_y-15 == enemy_position_y+30)) || ((pacman_position_x == enemy_position_x+15) && ( pacman_position_y+15 == enemy_position_y))   )
        
        if(((pacman_position_x - enemy_position_x_middle)<=41) && ((pacman_position_y - enemy_position_y_middle)<=41) && ((pacman_position_x - enemy_position_x_middle)>= -41) && ((pacman_position_y - enemy_position_y_middle)>= -41))
            
        {
            
            // if collision takes place play this sound ------
            
            mySoundCollidePacman.getIsPlaying();           //Returns false
            mySoundCollidePacman.setMultiPlay(false);
            mySoundCollidePacman.setSpeed(1.0f);       // sets speed of sound. I had to make sure its not fast
            mySoundCollidePacman.play();
            mySoundCollidePacman.getSpeed();
            mySoundCollidePacman.setSpeed(1.0f);
            mySoundCollidePacman.getSpeed();
            mySoundCollidePacman.getIsPlaying();           // returns true if sound is playing
            
            //------wait for 1900 microseconds for the sound to play and then reposition pacman on required (x,y)------------
            
            sleep(1.9);
            
            pacman_position_x = 420;
            pacman_position_y = 540;
            
            //adding counter for game over -------------
            
            CounterForGameOver++;
            
            if(CounterForGameOver == 3)
            {
                ofDrawBitmapString("GAME OVER", 840, 300);;
                sleep(1.5);
                abort();
            }
        }
        
		
        //-- sounds made by pacman while moving --- ------------------------
        
        mySoundMovePacman.getIsPlaying();
        mySoundMovePacman.setMultiPlay(false);//Returns false   MAN
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
    }
    
    /*            if(((pacman_position_x - fr_apple_middle_x)<=30) && ((pacman_position_y - fr_apple_middle_y)<=30) && ((pacman_position_x - fr_apple_middle_x)>= -30) && ((pacman_position_y - fr_apple_middle_y)>= -30))
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
     
     
     */
    
    /*if((key == 'w') || (key == 'W'))
	 {
     
     if(pacman_position_y < -40)
     {
     pacman_position_y=pacman_position_y+640;
     }
     
     else
     {
     
     for (y_checker_1 = 0; y_checker_1 < 157; y_checker_1++)
     {
     
     if(((allWallPositions[y_checker_1][1] + 20) == coordinate_y_up) && ((allWallPositions[y_checker_1][0]+20) ==pacman_position_x))
     {
     *flagp =1;
     ofDrawBitmapString("unmatched",830,140);
     
     }
     else
     {
     
     ofDrawBitmapString("matched", 830,140);
     
     *flagp = 0;
     
     
     }
     }
     if(*flagp ==0)
     {
     
     pacman_position_y = pacman_position_y -40;
     
     }
     else
     if (*flagp == 1) {
     pacman_position_y = pacman_position_y +0;
     }
     
     /*  else
     {
     pacman_position_y = pacman_position_y +40;
     pacman_position_y = pacman_position_y -40;
     //pacman_position_y = pacman_position_y +0; replacement for the above 2 lines of code perhaps ? ask !?
     //the outer for loop is not working .......................!!!!!!!!!!!!!!!!!!!!!!!!!!!
     
     }
     
     
     
     //pacman_position_y = pacman_position_y -40;
     }
     
     
     }*/
    
    
    /*if((key == 'w') || (key == 'W'))
     
     {
     if(pacman_position_y < -40)
     {
     pacman_position_y=pacman_position_y+640;
     }
     else
     {
     for(int impi = 0;impi<157;impi++)
     {
     
     
     if(allWallPositions[impi][1] +20 !=  coordinate_y_up)
     
     {
     flag = 0;
     }
     else{
     flag = 1;
     }
     
     }
     
     if(flag == 0)
     {
     pacman_position_y = pacman_position_y -40;
     }
     }
     }*/
    
    if((key == 'w') || (key == 'W'))
    {
        if(pacman_position_y < -40)
        {
            pacman_position_y=pacman_position_y+640;
        }
        else
        {
            flag = 0;
            
            for(int i = 0;i<157;i++)
            {
                
                
                
                if((allWallPositions[i][1]   ==  coordinate_y_up) && (allWallPositions[i][0]   == coordinate_x_up) )
                    
                {
                    flag = 1; // wall
                    break;
                }
            }
        }
        
        
        
        if(flag == 0)
        {
            pacman_position_y = pacman_position_y -40;
        }
    }
    
    
    
    
    if((key =='s') || (key =='S')) // 's' key
    {
        
        if(pacman_position_y > 640)
        {
            pacman_position_y = pacman_position_y -640;
        }
        else
        {
            
            
            flag = 0;
            
            for(int i = 0;i<157;i++)
            {
                
                
                
                if((allWallPositions[i][1]   ==  coordinate_y_down) && (allWallPositions[i][0]   == coordinate_x_down) )
                    
                {
                    flag = 1; // wall
                    break;
                }
            }
        }
        
        
        
        if(flag == 0)
        {
            pacman_position_y = pacman_position_y +40;
        }
        //pacman_position_y = pacman_position_y + 40;
    }
    
    
    
    
    if((key =='d') || (key =='D')) // 'd' key
    {
        if(pacman_position_x > 810)
        {
            pacman_position_x = pacman_position_x -840;
        }
        else
        {
            
            
            flag = 0;
            
            for(int i = 0;i<157;i++)
            {
                
                
                
                if((allWallPositions[i][1]   ==  coordinate_y_right) && (allWallPositions[i][0]   == coordinate_x_right) )
                    
                {
                    flag = 1; // wall
                    break;
                }
            }//pacman_position_x = pacman_position_x + 40;
        }
        
        
        if(flag == 0)
        {
            pacman_position_x = pacman_position_x +40;
        }
    }
    
    if((key=='a') || (key == 'A')) // 'a' key
    {
        if(pacman_position_x < -40)
        {
            pacman_position_x = pacman_position_x + 840;
        }
        else
        {
            flag = 0;
            
            for(int i = 0;i<157;i++)
            {
                
                
                
                if((allWallPositions[i][1]   ==  coordinate_y_left) && (allWallPositions[i][0]   == coordinate_x_left) )
                    
                {
                    flag = 1; // wall
                    break;
                }
            }//pacman_position_x = pacman_position_x + 40;
            
            //pacman_position_x = pacman_position_x - 40;
        }
        if(flag == 0)
        {
            pacman_position_x = pacman_position_x -40;
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


/*
 
 #################################################################
 
 oooo$$$$$$$$$$$$oooo
 oo$$$$$$$$$$$$$$$$$$$$$$$$o
 oo$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$o         o$   $$ o$
 o $ oo        o$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$o       $$ $$ $$o$
 oo $ $ "$      o$$$$$$$$$    $$$$$$$$$$$$$    $$$$$$$$$o       $$$o$$o$
 "$$$$$$o$     o$$$$$$$$$      $$$$$$$$$$$      $$$$$$$$$$o    $$$$$$$$
 $$$$$$$    $$$$$$$$$$$      $$$$$$$$$$$      $$$$$$$$$$$$$$$$$$$$$$$
 $$$$$$$$$$$$$$$$$$$$$$$    $$$$$$$$$$$$$    $$$$$$$$$$$$$$  """$$$
 "$$$""""$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$     "$$$
 $$$   o$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$     "$$$o
 o$$"   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$       $$$o
 $$$    $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" "$$$$$$ooooo$$$$o
 o$$$oooo$$$$$  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$   o$$$$$$$$$$$$$$$$$
 $$$$$$$$"$$$$   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$     $$$$""""""""
 """"       $$$$    "$$$$$$$$$$$$$$$$$$$$$$$$$$$$"      o$$$
 "$$$o     """$$$$$$$$$$$$$$$$$$"$$"         $$$
 $$$o          "$$""$$$$$$""""           o$$$
 $$$$o                                o$$$"
 "$$$$o      o$$$$$$o"$$$$o        o$$$$
 "$$$$$oo     ""$$$$o$$$$$o   o$$$$""
 ""$$$$$oooo  "$$$o$$$$$$$$$"""
 ""$$$$$$$oo $$$$$$$$$$
 """"$$$$$$$$$$$
 $$$$$$$$$$$$
 $$$$$$$$$$"
 "$$$""
 
 */