#ifndef GRID_FRAME_H
#define GRID_FRAME_H

#include "wx/mdi.h"
#include "wx/msgdlg.h"
#include "wx/toolbar.h"

#include "GridFrameConstants.h"
#include "GridFrameView.h"
#include "GridFrameViewConstants.h"
#include "PlaceableNodeType.h"

class GridFrame : public wxMDIChildFrame {

private:

    GridFrameView m_view;

public:

    GridFrame(wxMDIParentFrame *parent,
              const wxString &title);

    ~GridFrame();

    void clearGrid();

    void BindEvents();

    void OnCellSelected(wxGridEvent &event);

    void UnselectAllCells(wxGridRangeSelectEvent &event);

    void OnSliderChange(wxCommandEvent &event);

    GridFrameView& getView();

};

#endif // !GRID_FRAME_H