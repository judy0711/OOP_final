#include <ncurses.h>
#include <unistd.h>
#include <iostream>
#include "variables.h"
#include "Driver.h"

using namespace std;

MainDriver::MainDriver() {}

MainDriver::~MainDriver() {
    endwin();
}

void MainDriver::init() {
    initscr();
    curs_set(0);
    noecho();
    nodelay(stdscr, true);
    start_color();
    init_pair(COLOR_SET_EMPTY, COLOR_WHITE, COLOR_BLACK);
    init_pair(COLOR_SET_WALL, COLOR_WHITE, COLOR_WHITE);
    init_pair(COLOR_SET_PLAYER, COLOR_YELLOW, COLOR_BLACK);
    init_pair(COLOR_SET_GOAL, COLOR_WHITE, COLOR_GREEN);
    init_pair(COLOR_SET_ENEMY, COLOR_WHITE, COLOR_RED);
    init_pair(COLOR_SET_GAME_OVER, COLOR_RED, COLOR_YELLOW);
    init_pair(COLOR_SET_VICTORY, COLOR_GREEN, COLOR_YELLOW);
}

char MainDriver::getUserInput() {
    return getch();
}

void MainDriver::setFinished() {
    nodelay(stdscr, false);
}

void MainDriver::updatePixel(int x, int y, char c, int color) {
    attron(COLOR_PAIR(color));
    mvaddch(y, x, c);
    attroff(COLOR_PAIR(color));
}

void MainDriver::updateString(int x, int y, string text, int color) {
    attron(COLOR_PAIR(color));
    mvaddstr(y, x, text.c_str());
    attroff(COLOR_PAIR(color));
}

void MainDriver::render() {
    refresh();
    usleep(100000);
}