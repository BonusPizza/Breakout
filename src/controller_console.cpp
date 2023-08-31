#include "controller_console.h"

using namespace std;
ConsoleController::ConsoleController(BreakoutModel* model) {
	this->model = model;
};

bool ConsoleController::getAutoplay(){
    return autoplay;
}

//

// gets input from the keyboard and gives it to the model
wchar_t ConsoleController::getInput() {
    wchar_t ch = getch();
    string control;
    if (ch=='x'){
        autoplay = !autoplay;
    }
    
    if (getAutoplay()){
        control = getAutoplayInput(ch);
    }
    else if (!getAutoplay()){
        control = getControl(ch);
    }
    model->control_game(control);
    return ch;
};

string ConsoleController::getControl(wchar_t ch){
    switch(ch){
        case ' ':
            return "startGame";
        case 'a':
            return "moveLeft";
        case 'd':
            return "moveRight";
        case 's':
            return "stop";
    }
    return "";
};

string ConsoleController::getAutoplayInput(wchar_t ch){
    if (model->getWon() || model->getLost() || model->getStart()){
        return getControl(ch);
    }
    else{
        if (model->gamepaddle->getX() > model->gameball->getX()){
            return "moveLeft";
        }
        else if (model->gamepaddle->getX() < model->gameball->getX()){
            return "moveRight";
        }
        else{
            return "stop";
        }
    }
};
