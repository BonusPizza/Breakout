#include "view_console.h"
#include "view_console.h"
#include <ncurses.h>
#include <stdlib.h>
#include <string>


ConsoleView::ConsoleView(BreakoutModel* model) {
	setup_view();
	this->model = model;
	this->model->addObserver(this);
};

ConsoleView::~ConsoleView() {
    endwin();
};


void ConsoleView::drawBounds() {
    for(int i = 1; i < model->getGameWidth() - 1; i++) {
        mvaddch(2, i, ceilingTexture);
    }
    for(int i = 3; i <= model->getGameHeight(); i++) {
        mvaddch(i, 0, wallTexture);
        mvaddch(i, model->getGameWidth() - 1, wallTexture);
    }
};

void ConsoleView::drawScore() {
    mvprintw(0,0, "Highscore: %d", model->getHScore());
    mvprintw(0,model->getGameWidth()-23, "Press \'x\' for Autoplay.");
    mvprintw(1,0, "Current Score: %d", model->getCScore());
};

void ConsoleView::drawConditions() {
    if(model->getLost()){
        mvprintw(model->getGameHeight()/2, model->getGameWidth()/2-6, "You've Lost!");
        mvprintw(model->getGameHeight()/2+1, model->getGameWidth()/2-13, "Press \'SPACE\' to try again.");
    }
    if(model->getWon()){
        mvprintw(model->getGameHeight()/2, model->getGameWidth()/2-6, "You've Won!");
        mvprintw(model->getGameHeight()/2+1, model->getGameWidth()/2-14, "Press \'SPACE\' to play again.");
    }
    if(model->getStart()){
        mvprintw(model->getGameHeight()/2, model->getGameWidth()/2-3, "LEVEL %d", model->getLevel());
        mvprintw(model->getGameHeight()/2+1, model->getGameWidth()/2-11, "Press \'SPACE\' to start.");
    }
};

void ConsoleView::drawPaddle() {
    
    if(model->gamepaddle->getWidth() == 7){
        mvaddch(model->gamepaddle->getY(), model->gamepaddle->getX()-3, '\\');
        mvaddch(model->gamepaddle->getY(), model->gamepaddle->getX()-2, 'T');
        mvaddch(model->gamepaddle->getY(), model->gamepaddle->getX()-1, 'T');
        mvaddch(model->gamepaddle->getY(), model->gamepaddle->getX(), 'T');
        mvaddch(model->gamepaddle->getY(), model->gamepaddle->getX()+1, 'T');
        mvaddch(model->gamepaddle->getY(), model->gamepaddle->getX()+2, 'T');
        mvaddch(model->gamepaddle->getY(), model->gamepaddle->getX()+3, '/');        
    } else {
        mvaddch(model->gamepaddle->getY(), model->gamepaddle->getX()-2, '/');
        mvaddch(model->gamepaddle->getY(), model->gamepaddle->getX()-1, 'T');
        mvaddch(model->gamepaddle->getY(), model->gamepaddle->getX(), 'T');
        mvaddch(model->gamepaddle->getY(), model->gamepaddle->getX()+1, 'T');
        mvaddch(model->gamepaddle->getY(), model->gamepaddle->getX()+2, '\\');
    }
};

void ConsoleView::drawBall() {
    mvaddch(model->gameball->getY(), model->gameball->getX(), 'o');
};

void ConsoleView::drawBricks(){
    
   for(int i = 0; i < 5*13; i++) {
       if(!model->gamebricks[i]->getIsDestroyed()){
           if(model->gamebricks[i]->getType() == 1) { 
                mvaddch(model->gamebricks[i]->getY(), model->gamebricks[i]->getX(), '[');
                mvaddch(model->gamebricks[i]->getY(), model->gamebricks[i]->getX()+1, '?');
                mvaddch(model->gamebricks[i]->getY(), model->gamebricks[i]->getX()+2, ']');
           } 
           else { 
                mvaddch(model->gamebricks[i]->getY(), model->gamebricks[i]->getX(), '[');
                mvaddch(model->gamebricks[i]->getY(), model->gamebricks[i]->getX()+1, '=');
                mvaddch(model->gamebricks[i]->getY(), model->gamebricks[i]->getX()+2, ']');
           } 
       }
    }
    
};


void ConsoleView::update() {
    // libncurses standard loop calls
    erase();
    refresh();
    
    // building the game view
    drawBounds();

    // Show points of player 
    drawScore();

    // Show game conditions
    drawConditions();

    // Draw different objects. 
    // Draw paddle
    drawPaddle();
    
    // Draw ball
    drawBall();
    
    // Draw bricks
    drawBricks();
    
};

void ConsoleView::setup_view() {
    // Init ncurses
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    timeout(30);
};
