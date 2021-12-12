#include "GridFrame.h"

GridFrame::GridFrame(wxMDIParentFrame *parent,
                     const wxString &title)
    : wxMDIChildFrame(parent,
                      GridFrameConstants::GRID_FRAME_ID,
                      title),
      m_view{this} {

    BindEvents();

}

GridFrame::~GridFrame() {
}

void GridFrame::clearGrid() {

    wxGrid *grid = m_view.getGrid();

    for (int col = 0; col < GridFrameViewConstants::GRID_COLS; ++col) {

        for (int row = 0; row < GridFrameViewConstants::GRID_ROWS; ++row) {

            grid->SetCellBackgroundColour(row,
                                          col,
                                          GridFrameViewConstants::DEFAULT_CELL_COLOUR);

        }

    }

    grid->Refresh();

    wxMessageBox(GridFrameViewConstants::ON_GRID_CLEARED_MSG,
                 GridFrameViewConstants::ON_GRID_CLEARED_TITLE,
                 wxOK | wxICON_INFORMATION);

    m_view.setPreviousStartPoint(GridFrameViewConstants::INVALID_CELL_POSITION);
    m_view.setPreviousEndPoint(GridFrameViewConstants::INVALID_CELL_POSITION);

}

void GridFrame::BindEvents() {

    wxGrid *grid = m_view.getGrid();

    grid->Bind(wxEVT_GRID_CELL_LEFT_CLICK,
               &GridFrame::OnCellSelected,
               this);

    grid->Bind(wxEVT_GRID_RANGE_SELECT,
               &GridFrame::UnselectAllCells,
               this);

    m_view.getSlider()->Bind(wxEVT_SLIDER,
                             &GridFrame::OnSliderChange,
                             this);

}

void GridFrame::OnCellSelected(wxGridEvent &event) {

    const int col = event.GetCol();
    const int row = event.GetRow();

    m_view.setCell(row,
                   col);

    event.Skip();

}

void GridFrame::UnselectAllCells(wxGridRangeSelectEvent &event) {

    if (event.Selecting()) {

        m_view.getGrid()->ClearSelection();

        event.Skip();

    }

}

void GridFrame::OnSliderChange(wxCommandEvent &event) {

    int sliderValue = static_cast<wxSlider *>(event.GetEventObject())->GetValue();

    int cellSize = GridFrameViewConstants::GRID_CELL_MIN_SIZE;

    if (sliderValue != 0) {

        cellSize = cellSize
                 + static_cast<int>((sliderValue / 100.0)
                                   * cellSize);

    }

    m_view.SetCellsSize(cellSize);

}

GridFrameView &GridFrame::getView() {

    return m_view;

}
