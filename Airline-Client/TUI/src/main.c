#include <ncurses.h>
#include "includes.h"
#include "jsonHandler.h"

int main() {

	cJSON* json = getJson("../../../Airline-Client/test-data/TestUser67-dms.json");
	char* string = cJSON_Print(json);

	WINDOW *left_win, *right_win;
	int height, width, split_width;

	initscr();            /* Start curses mode */
	refresh();
	noecho();             /* Don't echo input keys to the screen */
	curs_set(0);          /* Hide the cursor */

	// Get the dimensions of the entire screen
	getmaxyx(stdscr, height, width);

	// Calculate the split point (e.g., half the width)
	split_width = width / 5;

	// Create the left window
	// newwin(height, width, start_y, start_x)
	left_win = newwin(height, split_width, 0, 0);

	// Create the right window
	// start_x for the right window is the end of the left window
	right_win = newwin(height, width - split_width, 0, split_width);

	// Add borders to visually separate the windows
	box(left_win, 0, 0);
	box(right_win, 0, 0);

	box(left_win, 0, 0);
	box(right_win, 0, 0);
	mvwprintw(left_win, 1, 1, "TestUser67");

	mvwprintw(right_win, 1, 1, "CJ_Link");
	mvwprintw(right_win, 2, 3, "Hello There");

	mvwprintw(right_win, 4, 1, "TestUser67");
	mvwprintw(right_win, 5, 3, "fellaBuddy56");

	// Refresh the windows to display content on the physical screen
	wrefresh(left_win);
	wrefresh(right_win);

	getch();              /* Wait for user input */

	// Clean up windows
	delwin(left_win);
	delwin(right_win);

	endwin();             /* End curses mode */

	return 0;
}
