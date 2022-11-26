#pragma once

#include "ofMain.h"
//#include "ofApp.h"

class Snake {


public:
    void init();
    void reset();
    void setup();
    void draw();
    void update();
    void startState();
    void gameState();
    void endState();
    void getEvents(int);
    void drawFood();
    void drawBoard();
    void drawSnake();
    ofVec2f getRandomLocation();

    vector<ofVec2f> snake;
    ofVec2f food;
    const int  CELL_SIZE = 20;
    int updown = CELL_SIZE;
    int rightleft = 0;
    uint64_t  preMS = 0;
    int COUNT_DOWN = 3000;
    string state = "START";

    ofTrueTypeFont font;
    ofTrueTypeFont font20;
    ofTrueTypeFont font50;
    ofTrueTypeFont font100;

};

