#ifndef GRID_FRAME_VIEW_CONSTANTS
#define GRID_FRAME_VIEW_CONSTANTS

namespace GridFrameViewConstants {

    constexpr const int GRID_ID   = 4001;
    constexpr const int SLIDER_ID = 4002;

    constexpr const int GRID_ROWS          = 20;
    constexpr const int GRID_COLS          = 30;
    constexpr const int GRID_CELL_MIN_SIZE = 20;

    constexpr const int SLIDER_MIN_VALUE = 0;
    constexpr const int SLIDER_MAX_VALUE = 100;

    constexpr const char        *ZOOM_TEXT             = "Zoom:";
    static constexpr const char *CLEAR_GRID_TITLE      = "Do you want to clear the grid?";
    static constexpr const char *CLEAR_GRID_MSG        = "Are you sure you want to clear the entire grid?\n"
                                                         "This action will delete all the currently places nodes";
    static constexpr const char *ON_GRID_CLEARED_TITLE = "Grid Cleared";
    static constexpr const char *ON_GRID_CLEARED_MSG   = "The grid has been successfully cleared.";

    static const wxPoint INVALID_CELL_POSITION{-1,
                                               -1};

    static constexpr uint32_t GRID_LINE_COLOUR       = 0xffaaaaaa;
    static constexpr uint32_t DEFAULT_CELL_COLOUR    = 0xffffffff;
    static constexpr uint32_t START_NODE_CELL_COLOUR = 0xff00ff00;
    static constexpr uint32_t END_NODE_CELL_COLOUR   = 0xff0000ff;
    static constexpr uint32_t BLOCK_NODE_CELL_COLOUR = 0xff000000;

}

#endif // !GRID_FRAME_VIEW_CONSTANTS
