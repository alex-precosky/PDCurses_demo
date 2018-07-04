#include "curses.h"

#include <iostream>

void DrawLogo(WINDOW* parentWin, int x);
void DrawTitle(WINDOW* parentWin);

void DrawTitle(WINDOW* parentWin)
{
	WINDOW* win = derwin(parentWin, 5, 31, 3, 15);

	bool title[] = {
		1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
		1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
		1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 
		1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 
		1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 
	};


	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	wmove(win, 0, 0);
	wattron(win, A_BOLD);
	for (auto ch : title)
	{
		if (ch)
			waddch(win, ACS_CKBOARD);
		else
			waddch(win, ' ');
	}
	wrefresh(win);
}

void DrawLogo(WINDOW* parentWin, int x)
{

	WINDOW* win = derwin(parentWin, 7, 12, 1, x);

	bool logo[] = { 
		 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0 ,
		 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0 ,
		 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,
		 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1 ,
		 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1 ,
		 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 ,
		 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0 
	};

	init_pair(2, COLOR_GREEN, COLOR_BLUE);
	wbkgd(win, COLOR_PAIR(2));

	wmove(win, 0, 0);
	wattron(win,A_BOLD);
	for (auto ch : logo)
	{
		if (ch)
			waddch(win, ACS_CKBOARD);
		else
			waddch(win, ' ');
	}


	wrefresh(win);

}


int main(int argc, char** argv)
{
	WINDOW* win;

	setlocale(LC_ALL, "");
	initscr();
	start_color();

	win = newwin(9, 60, 1, 0);

	init_pair(1, COLOR_WHITE, COLOR_BLUE);
	wbkgd(win, COLOR_PAIR(1));

	erase();
	werase(win);

	box(win, ACS_VLINE, ACS_HLINE);



	DrawLogo(win, 1);
	DrawTitle(win);
	DrawLogo(win, 47);

	move(10, 0);
	printw("It's working! You are using PDCurses!");
	refresh();

	int val;
	wgetch(win);

	return 0;
}

