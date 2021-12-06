#ifndef GRID_FRAME_H
#define GRID_FRAME_H

#include "wx/sizer.h"
#include "wx/grid.h"
#include "wx/mdi.h"
#include "wx/slider.h"
#include "wx/stattext.h"

#include "PathfindingAppConstants.h"

class GridFrame : public wxMDIChildFrame {

private:

    wxPanel *m_mainPanel;

    wxGrid *m_grid;

    wxBoxSizer *m_mainSizer;

    wxStatusBar *m_statusBar;

    wxSlider *m_zoomSlider;

    wxStaticText *m_zoomText;

    wxBoxSizer *m_footerSizer;

    wxBoxSizer *m_statusBarSizer;

    void initGrid();

    void SetupCellsSize(int size);

    void initStatusBar();

public:

    GridFrame(wxMDIParentFrame *parent,
              const wxString &title);

    ~GridFrame();


    void BindEvents();

    void OnCellSelected(wxGridEvent &event);

    void UnselectAllCells(wxGridRangeSelectEvent &event);

    void OnSliderChange(wxCommandEvent &event);

};

#endif // !GRID_FRAME_H