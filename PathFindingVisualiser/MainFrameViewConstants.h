#ifndef MAIN_FRAME_VIEW_CONSTANTS
#define MAIN_FRAME_VIEW_CONSTANTS

namespace MainFrameViewConstants {

	static constexpr int FILE_NEW_ID      = 2001;
	static constexpr int FILE_EXIT_ID     = 2002;
	static constexpr int TOOL_BAR_ID      = 2003;
	static constexpr int RUN_ALGORITHM_ID = 2004;
	static constexpr int NEW_GRID_ID      = 2005;
	static constexpr int START_NODE_ID    = 2006;
	static constexpr int END_NODE_ID      = 2007;
	static constexpr int BLOCK_NODE_ID    = 2008;
	static constexpr int ERASE_NODE_ID    = 2009;
	static constexpr int CLEAR_GRID_ID    = 2010;

	static constexpr const char *FILE_MENU_TEXT     = "File";
	static constexpr const char *FILE_NEW_TEXT      = "New Grid";
	static constexpr const char *FILE_EXIT_TEXT     = "Exit\tAlt+F4";
	static constexpr const char *RUN_ALGORITHM_TEXT = " Run The Algorithm ";

	static constexpr int PADDING_SIZE = 10;

	static constexpr const char *NEW_GRID_IMG_PATH      = "resources\\newGrid.png";
	static constexpr const char *RUN_ALGORITHM_IMG_PATH = "resources\\run.png";
	static constexpr const char *START_NODE_IMG_PATH    = "resources\\startNode.png";
	static constexpr const char *END_NODE_IMG_PATH      = "resources\\endNode.png";
	static constexpr const char *BLOCK_NODE_IMG_PATH    = "resources\\blockNode.png";
	static constexpr const char *ERASE_NODE_IMG_PATH    = "resources\\eraseNode.png";
	static constexpr const char *CLEAR_GRID_IMG_PATH    = "resources\\clearGrid.png";

	static constexpr const char *START_NODE_TEXT        = "Place The Starting Node";
	static constexpr const char *END_NODE_TEXT          = "Place The Ending Node";
	static constexpr const char *BLOCK_NODE_TEXT        = "Place The Untraversable Node";
	static constexpr const char *ERASE_NODE_TEXT        = "Erase The node";
	static constexpr const char *CLEAR_GRID_TEXT        = "Clear The Entire Grid";

}

#endif // !MAIN_FRAME_VIEW_CONSTANTS
