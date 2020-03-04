#ifndef MENU_H
#define MENU_H

class menu
{

public:
    menu(int rows) : mRows(rows) {}

    int getCursorPos()
    {
        return cursorPos;
    }
    void setCursorPos(bool direction);

    void refreshScreen()
    {
        refreshFlag = 0;
        printScreen();
    }
    void set_screen_to_print()
    {

    }

private:
    int mRows;
    int cursorPos;
    void printCursor();

    bool refreshFlag;
    void (*printScreen)();
};

//direction macros for setCursorPos
#define UP 1
#define DOWN 0

void menu::setCursorPos(bool direction)
{
    switch (direction)
    {
    case UP:
        if (cursorPos < mRows)
            cursorPos++;
        else
            cursorPos = 0;
        break;
    case DOWN:
        if (cursorPos > mRows)
            cursorPos--;
        else
            cursorPos = mRows;
        break;

    default:
        break;
    }
    printCursor();  //could make it public for more flexibility
}



#endif