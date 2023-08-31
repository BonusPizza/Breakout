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

/*
Es könnten nun weiter Controller beispielsweise in Form des Maus-Cursors implementiert werden.
Hierfür könnte man die x-Koordinate des Cursors auf dem Spielfeld und die Position des Paddles abfragen und dann je nach Position die Kontrollanweisung "moveLeft" oder "moveRight" an die Funktion control_game des models übergeben.
Wenn der Cursor sich rechts vom paddle befindet soll dieses sich nach rechts bewegt (links entsprechend).
So könnte das Spiel mit einer Maus oder einem Touchpad gespielt werden.
*/
