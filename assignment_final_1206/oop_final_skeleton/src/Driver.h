#ifndef _DRIVER_H
#define _DRIVER_H

#include <string>

using namespace std;

//// You don't need to care about these classes. ////

class BaseDriver {
public:
    virtual ~BaseDriver() {}

    virtual void init() = 0;

    virtual char getUserInput() = 0;

    virtual void updatePixel(int x, int y, char c, int color) = 0;

    virtual void updateString(int x, int y, string text, int color) = 0;

    virtual void render() = 0;

    virtual void setFinished() {}
};

class MainDriver : public BaseDriver {
public:
    MainDriver();

    ~MainDriver();

    void init();

    char getUserInput();

    void updatePixel(int x, int y, char c, int color);

    void updateString(int x, int y, string text, int color);

    void render();

    void setFinished();
};

#endif
