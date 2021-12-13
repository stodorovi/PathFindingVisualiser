#ifndef GRID_FRAME_H
#define GRID_FRAME_H

#include "wx/mdi.h"
#include "wx/msgdlg.h"
#include "wx/toolbar.h"

#include "GridFrameConstants.h"
#include "GridFrameView.h"
#include "GridFrameViewConstants.h"
#include "PlaceableNodeType.h"


/** @brief Grid presenter. Defines the logic behind controls */
class GridFrame : public wxMDIChildFrame {

private:

    GridFrameView m_view;

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

    /** @brief Bind events to buttons & other controls. */
    void BindEvents();

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

    /**
     * @brief view getter
     * @return the view
    */
    GridFrameView& getView();

};

#endif // !GRID_FRAME_H