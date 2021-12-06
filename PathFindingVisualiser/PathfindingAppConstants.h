#ifndef PATHFINDINGAPPCONSTANTS_H
#define PATHFINDINGAPPCONSTANTS_H

#include "wx/gdicmn.h"

// IDs
constexpr const int MAIN_FRAME_ID     = 1001;
constexpr const int GRID_FRAME_ID     = 1002;

constexpr const int GRID_ID           = 2001;
constexpr const int SLIDER_ID         = 2002;

constexpr const int FILE_MENU_NEW_ID  = 3001;
constexpr const int FILE_MENU_EXIT_ID = 3002;

// String constants
constexpr const char *MAIN_FRAME_TITLE    = "Pathfinding Visualiser";

constexpr const char *FILE_MENU_TEXT      = "File";
constexpr const char *FILE_MENU_NEW_TEXT  = "New Grid";
constexpr const char *FILE_MENU_EXIT_TEXT = "Exit";

constexpr const char *ZOOM_TEXT           = "Zoom:";

// Sizes
const wxSize MAIN_FRAME_DEFAULT_SIZE {1280, 720};
constexpr const int GRID_ROWS = 20;
constexpr const int GRID_COLS = 30;
constexpr const int GRID_CELL_MIN_SIZE = 20;
constexpr const int SLIDER_MIN_VALUE = 0;
constexpr const int SLIDER_MAX_VALUE = 100;

// Colours
constexpr const uint32_t GRID_LINE_COLOUR = 0xffaaaaaa;

#endif // !PATHFINDINGAPPCONSTANTS_H

