#ifndef MENU_H
#define MENU_H

/*
create the menu instance
when moving cursor, 
*/

class menu
{

public:
    menu(int rows) : mRows(rows) {}

    int getCursorPos()
    {
        return cursorPos;
    }
    void moveCursor(bool direction);

    void refreshScreen()
    {
        refreshFlag = 0;
        printScreen();
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

void menu::moveCursor(bool direction)
{
    if (direction)
    {
        if (cursorPos < mRows)
            cursorPos++;
        else
            cursorPos = 0;
    }
    else
    {
        if (cursorPos > mRows)
            cursorPos--;
        else
            cursorPos = mRows;
    }

    printCursor(); //could make it public for more flexibility
}

#endif