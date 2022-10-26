#ifndef GRID_FRAME_H
#define GRID_FRAME_H

#include "wx/mdi.h"
#include "wx/msgdlg.h"
#include "wx/timer.h"
#include "wx/toolbar.h"

#include "GridFrameConstants.h"
#include "GridFrameView.h"
#include "GridFrameViewConstants.h"
#include "MainFrame.h"
#include "PlaceableNodeType.h"

#include "../PathfindingAlgorithms/Grid.h"


/** @brief Grid presenter. Defines the logic behind controls */
class GridFrame : public wxMDIChildFrame {

private:

    GridFrameView m_view;

    pathAlgs::Grid m_grid;

    pathAlgs::Point m_startPoint;

    pathAlgs::Point m_endPoint;

    std::deque<pathAlgs::Point> m_lastTraversalOrder;
    std::deque<pathAlgs::Point> m_traversalOrder;
    size_t m_traversalOrderCount;

    pathAlgs::GridNodePtr m_lastGoalNode;
    float m_goalNodeDepth;
    pathAlgs::GridNode *m_shortestPathCurrentNode;

    int m_currentAlgoritm;

    bool m_isCurrentlyVisualising;

    wxTimer *m_visualisationCellColouringTimer;

    const int m_visualisationSpeed = 5;

    /**
     * @brief Creates TraversabilityMap from the internal grid values.
     * 
     * @return TraversabilityMap
    */
    pathAlgs::TraversabilityMap getTraversabilityMap();

    /** @brief Bind events to buttons & other controls. */
    void BindEvents();

    /**
     * @brief set the size of the grid cells
     * 
     * @param size the size to set
    */
    void setCellsSize(int size);

    /**
     * @brief visualise nex cell in the traversal order.
    */
    void visualiseNextCell(wxTimerEvent &event);

    /**
    * @brief sets the last search results, sets traversal order with removed start & goal points, & goal node.
    * @param searchResults the searchResults to read from
    */
    void setLastSearch(pathAlgs::Grid::SearchResults &searchResults);

    /**
    * @brief Clears the last run traversal order visualisation.
    */
    void clearLastTraversalVisualisation();

    /**
    * @brief Set the cell to the current node type.
    * @param row
    * @param col
    */
    void setCellToCurrentNode(int row,
                              int col);

    /** @brief Stop the timer before closing the window. */
    void onClose(wxCloseEvent &event);

    /**
    * @brief Searches the path with the selected algorithm.
    * @return the search results
    */
    pathAlgs::Grid::SearchResults findPath();

public:

    /**
     * @brief Constructor.
     * 
     * @param parent - parent window
     * @param title - window title
    */
    GridFrame(wxMDIParentFrame *parent,
              const wxString &title);

    /** @brief Destructor. */
    ~GridFrame();

    /** @brief Clears the entire grid. */
    void clearGrid();

    /** @brief Process on cell selected. */
    void OnCellSelected(wxGridEvent &event);

    /**
     * @brief Unselects all cells. Used to prevent multi-cell selection.
     * @param event 
    */
    void UnselectAllCells(wxGridRangeSelectEvent &event);

    /**
     * @brief Process slider value change.
     * @param event 
    */
    void OnSliderChange(wxCommandEvent &event);

    /** @brief Visualises the chosen algorithm. */
    void visualiseAlgorithm();

    /**
     * @brief view getter
     * @return the view
    */
    GridFrameView& getView();
    
    /**
     * @brief currentAlgorithm getter
     * @return the currentAlgorithm
    */
    int getCurrentAlgorithm() const;

    /**
     * @brief currrentAlgorithm setter
     * @param algorithmIndex the algorithmIndex to set
    */
    void setCurrentAlgorithm(int algorithmIndex,
                             const wxString &algorithmName);

};

#endif // !GRID_FRAME_H