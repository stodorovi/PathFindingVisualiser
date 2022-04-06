#include "GridFrame.h"
#include "GridFrameView.h"

#include <thread>
#include <chrono>

GridFrameView::GridFrameView(GridFrame *gridFrame)
    : m_gridFrame{gridFrame},
      m_previousStartPoint{GridFrameViewConstants::INVALID_CELL_POSITION},
      m_previousEndPoint{GridFrameViewConstants::INVALID_CELL_POSITION} {

    m_mainPanel = new wxPanel(m_gridFrame);
    m_mainSizer = new wxBoxSizer(wxHORIZONTAL);

    initGrid();

    m_mainPanel->SetSizer(m_mainSizer);

    initStatusBar();

}

void GridFrameView::initGrid() {

    m_grid = new wxGrid(m_mainPanel,
                        GridFrameViewConstants::GRID_ID);

    m_grid->CreateGrid(GridFrameViewConstants::GRID_ROWS,
                       GridFrameViewConstants::GRID_COLS);

    m_grid->SetGridLineColour(GridFrameViewConstants::GRID_LINE_COLOUR);

    m_grid->HideRowLabels();
    m_grid->HideColLabels();

    m_grid->SetColMinimalAcceptableWidth(GridFrameViewConstants::GRID_CELL_MIN_SIZE);
    m_grid->SetRowMinimalAcceptableHeight(GridFrameViewConstants::GRID_CELL_MIN_SIZE);

    m_grid->EnableEditing(false);

    m_grid->EnableDragRowSize(false);
    m_grid->EnableDragColSize(false);

    m_grid->DisableCellEditControl();

    m_mainSizer->Add(m_grid,
                     1,
                     wxEXPAND | wxALL);

}

void GridFrameView::initStatusBar() {


    m_statusBar = m_gridFrame->CreateStatusBar();

    m_footerSizer = new wxBoxSizer(wxVERTICAL);

    m_zoomSlider = new wxSlider(m_statusBar,
                                GridFrameViewConstants::SLIDER_ID,
                                GridFrameViewConstants::SLIDER_MIN_VALUE,
                                GridFrameViewConstants::SLIDER_MIN_VALUE,
                                GridFrameViewConstants::SLIDER_MAX_VALUE);

    m_statusBarSizer = new wxBoxSizer(wxHORIZONTAL);

    m_zoomText = new wxStaticText(m_statusBar,
                                  -1,
                                  GridFrameViewConstants::ZOOM_TEXT);
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

void GridFrameView::clearGrid() {

    for (int col = 0; col < GridFrameViewConstants::GRID_COLS; ++col) {

        for (int row = 0; row < GridFrameViewConstants::GRID_ROWS; ++row) {

            m_grid->SetCellBackgroundColour(row,
                                            col,
                                            GridFrameViewConstants::DEFAULT_CELL_COLOUR);

        }

    }

    m_grid->Refresh();

}

int GridFrameView::showClearGridConfirmationDialog() {

    wxMessageDialog *confirmCleanGridDialog = new wxMessageDialog(m_gridFrame,
                                                                  GridFrameViewConstants::CLEAR_GRID_MSG,
                                                                  GridFrameViewConstants::CLEAR_GRID_TITLE,
                                                                  wxYES_NO | wxNO_DEFAULT | wxICON_WARNING);

    return confirmCleanGridDialog->ShowModal();;

}

void GridFrameView::showGridClearedSuccessMessage() {

    wxMessageBox(GridFrameViewConstants::ON_GRID_CLEARED_MSG,
                 GridFrameViewConstants::ON_GRID_CLEARED_TITLE,
                 wxOK | wxICON_INFORMATION);

}

void GridFrameView::setCurrentNodeType(PlaceableNodeType nodeType) {

    m_currentNodeType = nodeType;

    const std::map<PlaceableNodeType, uint32_t> nodeTypeColourMap {

        {PlaceableNodeType::START,
         GridFrameViewConstants::START_NODE_CELL_COLOUR},

        {PlaceableNodeType::END,
         GridFrameViewConstants::END_NODE_CELL_COLOUR},

        {PlaceableNodeType::BLOCK,
         GridFrameViewConstants::BLOCK_NODE_CELL_COLOUR},

        {PlaceableNodeType::ERASE,
         GridFrameViewConstants::DEFAULT_CELL_COLOUR},

        {PlaceableNodeType::NONE,
         GridFrameViewConstants::DEFAULT_CELL_COLOUR},

    };

    m_currentNodeColour = nodeTypeColourMap.at(m_currentNodeType);

}

wxGrid *GridFrameView::getGrid() const {

    return m_grid;

}

wxSlider *GridFrameView::getSlider() const {

    return m_zoomSlider;

}

PlaceableNodeType &GridFrameView::getCurrentNodeType() {

    return m_currentNodeType;

}

wxColour GridFrameView::getCurrentNodeColour() const {
    
    return m_currentNodeColour;

}

wxPoint GridFrameView::getPreviousStartPoint() const {

    return m_previousStartPoint;

}
void GridFrameView::setPreviousStartPoint(wxPoint point) {

    m_previousStartPoint = point;

}

wxPoint GridFrameView::getPreviousEndPoint() const {

    return m_previousEndPoint;

}

void GridFrameView::setPreviousEndPoint(wxPoint point) {

    m_previousEndPoint = point;

}

bool operator==(wxPoint first, pathAlgs::Point second) {

    return first.x == second.x
        && first.y == second.y;

}

bool operator==(pathAlgs::Point first, wxPoint second) {

    return second == first;

}