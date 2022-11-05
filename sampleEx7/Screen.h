#ifndef EXERCISE_7_32_H
#define EXERCISE_7_32_H

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::ostream;

class Screen;

class Window_mgr 
{
    public:
        //location ID for eaceh screen on the window
        using ScreenIndex = vector<Screen>::size_type;
        //reset the Screen at the given position to all blanks
        void clear(ScreenIndex);

    private:
        vector<Screen> screens; // { Screen(24, 80, ' 'f) } sample input
}

class Screen{
    friend void Window_mgr::clear(ScreenIndex);
    public:
        using pos = string::size_type; 

        Screen() = default;
        //initialize contents to hold given number of blanks
        Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') { }
        //screen contents with character
        Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) { }
        char get() const 
            { return contents[cursor]; }
        inline char get(pos ht, pos wd) const;
        Screen &move(pos r, pos c);
        Screen &set(char c);
        Screen &set(pos ht, pos wd, char c);
        //display overloaded on whether the object is const or not
        Screen &display(ostream &os) { do_display(os); return *this; }
        const Screen &display(ostream &os) const { do_display(os); return *this; }

    private:
        void do_display(ostream&os) const { os << contents << '\n'; }
        pos cursor = 0;
        pos height = 0, width = 0;
        string contents;
        
};

void Window_mgr::clear(ScreenIndex i)
{
    //s is a reference to the Screen we want to clear
    Screen &s = screens[i];
    //reset the contents of that Screen we want to clear
    s.contents = string(s.height * s.width, ' ');
}

inline Screen& Screen::move(pos r, pos c)
{
    //compute row location
    pos row = r * width;
    //move cursor to column within row
    cursor = row + c;
    return *this;
}

char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}

inline Screen &Screen::set(char c)
{
    //set new value at where cursor currently is
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch)
{
    //set specified location to given value
    contents[r*width + col] = ch;
    return *this;
}

#endif