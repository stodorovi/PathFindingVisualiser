#ifndef GRID_FRAME_VIEW
#define GRID_FRAME_VIEW

#include <map>

#include "wx/sizer.h"
#include "wx/grid.h"
#include "wx/slider.h"
#include "wx/stattext.h"
#include "wx/statusbr.h"

#include "GridFrameViewConstants.h"
#include "NodeTypeSetCellProcessor.h"
#include "PlaceableNodeType.h"

/** forward declaration - circular dependancy */
class GridFrame;

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

    void initGrid();

    void initStatusBar();

public:

    GridFrameView(GridFrame *gridFrame);

    void setCurrentNodeType(PlaceableNodeType nodeType);

    void setCell(int row,
                 int col);

    void SetCellsSize(int size);

    wxGrid* getGrid() const;

    wxSlider *getSlider() const;

    PlaceableNodeType& getCurrentNodeType();

    wxColour getCurrentNodeColour() const;

    wxPoint getPreviousStartPoint() const;
    void setPreviousStartPoint(wxPoint point);

    wxPoint getPreviousEndPoint() const;
    void setPreviousEndPoint(wxPoint point);

};

#endif // GRID_FRAME_VIEW
