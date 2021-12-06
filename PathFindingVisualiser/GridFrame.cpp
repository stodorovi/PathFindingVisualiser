#include "GridFrame.h"

GridFrame::GridFrame(wxMDIParentFrame *parent,
                     const wxString &title)
    : wxMDIChildFrame(parent,
                      GRID_FRAME_ID,
                      title) {

    m_mainPanel = new wxPanel(this);
    m_mainSizer = new wxBoxSizer(wxHORIZONTAL);

    initGrid();

    m_mainPanel->SetSizer(m_mainSizer);

    initStatusBar();

    BindEvents();

}

GridFrame::~GridFrame() {
}

void GridFrame::initGrid() {

    m_grid = new wxGrid(m_mainPanel,
                        GRID_ID);

    m_grid->CreateGrid(GRID_ROWS,
                       GRID_COLS);

    m_grid->SetGridLineColour(GRID_LINE_COLOUR);

    m_grid->HideRowLabels();
    m_grid->HideColLabels();

    m_grid->SetColMinimalAcceptableWidth(GRID_CELL_MIN_SIZE);
    m_grid->SetRowMinimalAcceptableHeight(GRID_CELL_MIN_SIZE);

    m_grid->EnableEditing(false);

    m_grid->EnableDragRowSize(false);
    m_grid->EnableDragColSize(false);

    m_grid->DisableCellEditControl();

    SetupCellsSize(GRID_CELL_MIN_SIZE);

    m_mainSizer->Add(m_grid,
                     1,
                      wxEXPAND | wxALL);

}

void GridFrame::SetupCellsSize(int size) {

    for (int row = 0; row < GRID_COLS; ++row) {

        if (row < GRID_ROWS) {

            m_grid->SetRowSize(row,
                               size);

        }

        m_grid->SetColSize(row,
                           size);

    }

    m_grid->Refresh();

}

void GridFrame::initStatusBar() {

    m_statusBar = CreateStatusBar();

    m_footerSizer = new wxBoxSizer(wxVERTICAL);

    m_zoomSlider = new wxSlider(m_statusBar,
                                SLIDER_ID,
                                SLIDER_MIN_VALUE,
                                SLIDER_MIN_VALUE,
                                SLIDER_MAX_VALUE);

    m_statusBarSizer = new wxBoxSizer(wxHORIZONTAL);

    m_zoomText = new wxStaticText(m_statusBar,
                                  -1,
                                  ZOOM_TEXT);
    m_statusBarSizer->Add(m_zoomText,
                          0,
                          wxALIGN_CENTER_VERTICAL);
    m_statusBarSizer->Add(m_zoomSlider,
                          0);
    m_statusBarSizer->Layout();

    m_footerSizer->Add(m_statusBarSizer,
                       0,
                       wxALIGN_RIGHT);
    m_statusBar->SetSizer(m_footerSizer);
    m_statusBar->SendSizeEvent();
    m_footerSizer->Layout();

}

void GridFrame::BindEvents() {

    m_grid->Bind(wxEVT_GRID_CELL_LEFT_CLICK,
                 &GridFrame::OnCellSelected,
                 this);

    m_grid->Bind(wxEVT_GRID_RANGE_SELECT,
                 &GridFrame::UnselectAllCells,
                 this);

    m_zoomSlider->Bind(wxEVT_SLIDER,
                       &GridFrame::OnSliderChange,
                       this);

}

void GridFrame::OnCellSelected(wxGridEvent &event) {

}

void GridFrame::UnselectAllCells(wxGridRangeSelectEvent &event) {

    if (event.Selecting()) {

        m_grid->ClearSelection();

        event.Skip();

    }

}

void GridFrame::OnSliderChange(wxCommandEvent &event) {

    int sliderValue = static_cast<wxSlider *>(event.GetEventObject())->GetValue();

    int cellSize = GRID_CELL_MIN_SIZE;

    if (sliderValue != 0) {

        cellSize = cellSize
                 + static_cast<int>((sliderValue / 100.0)
                                  * cellSize);

    }

    SetupCellsSize(cellSize);

}
