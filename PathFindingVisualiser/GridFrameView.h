#ifndef GRID_FRAME_VIEW
#define GRID_FRAME_VIEW

#include <map>

#include "wx/grid.h"
#include "wx/sizer.h"
#include "wx/slider.h"
#include "wx/stattext.h"
#include "wx/statusbr.h"

#include "GridFrameViewConstants.h"
#include "NodeTypeSetCellProcessor.h"
#include "PlaceableNodeType.h"

/** forward declaration - circular dependancy */
class GridFrame;

/** @brief Grid frame view. Defines the look of the grid frame. */
class GridFrameView {

private:

    GridFrame *m_gridFrame;

    wxPanel *m_mainPanel;

    wxBoxSizer *m_mainSizer;

    wxGrid *m_grid;

    wxStatusBar *m_statusBar;

    wxBoxSizer *m_statusBarSizer;

    wxSlider *m_zoomSlider;

    wxStaticText *m_zoomText;

    wxBoxSizer *m_footerSizer;

    PlaceableNodeType m_currentNodeType;

    wxColour m_currentNodeColour;

    wxPoint m_previousStartPoint;
    wxPoint m_previousEndPoint;

    /** @brief Initialises the grid and its elements. */
    void initGrid();

    /** @brief Initialises the status bar and its elements. */
    void initStatusBar();

public:

    /**
     * @brief Constructor.
     * @param gridFrame - grid frame to define the look for.
    */
    GridFrameView(GridFrame *gridFrame);

    /**
     * @brief Clears the grid cells.
    */
    void clearGrid();

    /**
     * @brief Shows the confirmation message dialog for clearing the grid and returns the choice.
     * @return the chosen option id ( wxID_YES / wxID_NO )
    */
    int showClearGridConfirmationDialog();

    /** @brief Shows the message that the grid was successfully cleared. */
    void showGridClearedSuccessMessage();

    /**
     * @brief Sets the currentNodeType and currentNodeColour.
     * @param nodeType to set
    */
    void setCurrentNodeType(PlaceableNodeType nodeType);

    /**
     * @brief Set the cell to the current node type.
     * @param row 
     * @param col 
    */
    void setCellToCurrentNode(int row,
                              int col);

    /**
     * @brief Set the size of the cells.
     * @param size 
    */
    void SetCellsSize(int size);

    /**
     * @brief grid getter.
     * @return the grid
    */
    wxGrid* getGrid() const;

    /**
     * @brief slider getter.
     * @return the slider
    */
    wxSlider *getSlider() const;

    /**
     * @brief currentNodeType getter.
     * @return the currentNodeType
    */
    PlaceableNodeType& getCurrentNodeType();

    /**
     * @brief currentNodeColour getter.
     * @return the currentNodeColour
    */
    wxColour getCurrentNodeColour() const;

    /**
     * @brief previousStartPoint getter.
     * @return the previousStartPoint
    */
    wxPoint getPreviousStartPoint() const;

    /**
     * @brief previousStartPoint setter.
     * @param point the point to set
    */
    void setPreviousStartPoint(wxPoint point);

    /**
     * @brief previousEndPoint getter.
     * @return the previousEndPoint
    */
    wxPoint getPreviousEndPoint() const;

    /**
     * @brief previousEndPoint setter.
     * @param point the point to set
    */
    void setPreviousEndPoint(wxPoint point);

};

#endif // GRID_FRAME_VIEW
