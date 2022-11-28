#include "Snake.h"


//---------------------------------
void Snake::init() {
    snake.clear();
    food.set(0, 0);
    updown = CELL_SIZE;
    rightleft = 0;
    preMS = ofGetElapsedTimeMillis();
    COUNT_DOWN = 3000;
    state = "START";

}
//----------------------------------
void Snake::reset() {
    init();
    setup();
}
//----------------------------------
void Snake::setup() {

    for (int i = 0; i < 3; i++) {
        ofVec2f s;
        s.set(ofGetWidth() / 2 - 10, ofGetHeight() / 2 - i * CELL_SIZE - 10 - 100);
        snake.push_back(s);
    }

    font.load("arial.ttf", 12);
    font20.load("equilibrium.ttf", 20);
    font50.load("equilibrium.ttf", 50);
    font100.load("equilibrium.ttf", 100);

    food = getRandomLocation();

    preMS = ofGetElapsedTimeMillis();
}

//----------------------------------
void Snake::update() {
    // state START
    if (state == "START") {
        uint64_t  delta = ofGetElapsedTimeMillis() - preMS;
        if (delta > COUNT_DOWN) {
            state = "GAME";
            return;
        }
        return;
    }
    // state GAME
    if (state == "GAME") {
        gameState();
        return;
    }
    // state END
    if (state == "END") {
        // check keypressed()
        return;
    }
}

//----------------------------------
void Snake::draw() {

    if (state == "START") {
        uint64_t  delta = ofGetElapsedTimeMillis() - preMS;
        ofBackground(255);
        drawBoard();
        ofSetColor(100, 100, 255);
        ofFill();
        font50.drawString("SNAKE", ofGetWidth() / 2 - font50.stringWidth("SNAKE") / 2, ofGetHeight() / 2 - 50);
        string count = ofToString(COUNT_DOWN / 1000 - int(delta / 1000));
        font20.drawString(count, ofGetWidth() / 2 - font20.stringWidth(count) / 2, ofGetHeight() / 2 + 50);
        return;
    }

    if (state == "GAME") {
        ofBackground(180);
        drawBoard();
        drawSnake();
        drawFood();
        return;
    }

    if (state == "END") {
        ofSetColor(90);
        font100.drawString("Game", ofGetWidth() / 2 - font100.stringWidth("Game") / 2, ofGetHeight() / 2 - 50);
        font100.drawString("Over!", ofGetWidth() / 2 - font100.stringWidth("Over!") / 2, ofGetHeight() / 2 + 50);
        ofPushStyle();
        ofSetColor(255, 255, 0);
        font.drawString("ENTER to restart!", ofGetWidth() / 2, ofGetHeight() / 2 + 100);
        ofPopStyle();
        drawSnake();
        drawFood();
        return;
    }
}

//---------------------------------
void Snake::gameState() {
    ofVec2f head = snake[0];
    float _x = head.x + rightleft;
    float _y = head.y + updown;

    if ((_x > ofGetWidth() - 20) || (_x < 20) || (_y > ofGetHeight() - 20) || (_y < 20)) {
        state = "END";
        return;
    }
    //------
    ofVec2f s(_x, _y);
    snake.insert(snake.begin(), s);
    snake.pop_back();

    head = snake[0];
    int len = snake.size();
    ofVec2f last = snake[len - 1];

    if ((head.x == food.x) && (head.y == food.y)) {
        ofVec2f nextCell(last.x + rightleft, last.y + updown);
        snake.push_back(nextCell);
        food = getRandomLocation();
    }
}

//----------------------------------
void Snake::drawFood() {

    ofSetHexColor(0x00FEFE);
    if (state == "END") ofSetHexColor(0x545454);
    ofFill();
    ofDrawRectangle(food.x, food.y, CELL_SIZE, CELL_SIZE);
}


//----------------------------------
void Snake::drawSnake() {
    ofPushStyle();
    ofSetHexColor(0x524947);
    if (state == "END") ofSetHexColor(0x545454);
    ofFill();
    for (uint16_t i = 0; i < snake.size(); i++) {
        ofVec2f v = snake.at(i);
        ofDrawEllipse(v.x, v.y, CELL_SIZE, CELL_SIZE);
    }
    ofPopStyle();
}

//----------------------------------
void Snake::drawBoard() {
    ofSetColor(50, 100, 100);
    ofFill();
    ofDrawRectangle(ofGetWidth() / 2, ofGetHeight() / 2, 400, 400);
}


//----------------------------------
void Snake::getEvents(int key) {

    if (key == OF_KEY_UP) {
        if (updown == 0) updown = -CELL_SIZE;
        rightleft = 0;
    }

    if (key == OF_KEY_DOWN) {
        if (updown == 0) updown = CELL_SIZE;
        rightleft = 0;
    }

    if (key == OF_KEY_RIGHT) {
        if (rightleft == 0) rightleft = CELL_SIZE;
        updown = 0;
    }

    if (key == OF_KEY_LEFT) {
        if (rightleft == 0) rightleft = -CELL_SIZE;
        updown = 0;
    }
}


//---------------------------------
ofVec2f Snake::getRandomLocation() {
    ofVec2f v;
    v.x = int(ofRandom(1, ofGetWidth()/CELL_SIZE-1));
    v.y = int(ofRandom(1, ofGetHeight()/CELL_SIZE)-1);
    v.x = v.x * CELL_SIZE;  
    v.y = v.y * CELL_SIZE;
    return v;
}
