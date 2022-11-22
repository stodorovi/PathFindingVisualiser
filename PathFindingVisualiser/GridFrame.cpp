#include "GridFrame.h"

GridFrame::GridFrame(wxMDIParentFrame *parent,
                     const wxString &title)
    : wxMDIChildFrame(parent,
                      GridFrameConstants::GRID_FRAME_ID,
                      title),
      m_view{this},
      m_currentAlgoritm{-1},
      m_isCurrentlyVisualising{false},
      m_visualisationCellColouringTimer{new wxTimer(this)}
 {

    m_visualisationCellColouringTimer = new wxTimer(this);

    setCellsSize(GridFrameViewConstants::GRID_CELL_MIN_SIZE);

    BindEvents();

}

GridFrame::~GridFrame() {
}

void GridFrame::clearGrid() {

    if (m_isCurrentlyVisualising) return;

    int clearGridDialogRetValue = m_view.showClearGridConfirmationDialog();

    if (clearGridDialogRetValue == wxID_NO) {

        return;

    }

    m_view.clearGrid();

    m_view.showGridClearedSuccessMessage();

    m_view.setPreviousStartPoint(GridFrameViewConstants::INVALID_CELL_POSITION);
    m_view.setPreviousEndPoint(GridFrameViewConstants::INVALID_CELL_POSITION);

}

pathAlgs::TraversabilityMap GridFrame::getTraversabilityMap() {

    pathAlgs::TraversabilityMap gridMap;

    m_startPoint = GridFrameConstants::INVALID_CELL_POSITION;
    m_endPoint   = GridFrameConstants::INVALID_CELL_POSITION;

    for (int row = 0; row < GridFrameViewConstants::GRID_ROWS; ++row) {

        std::vector<bool> rowMap;

        for (int col = 0; col < GridFrameViewConstants::GRID_COLS; ++col) {

            wxGrid *grid = m_view.getGrid();

            wxColour cellColour = grid->GetCellBackgroundColour(row, col);

            if (cellColour == GridFrameViewConstants::START_NODE_CELL_COLOUR) {

                m_startPoint = {col,
                                row};

                rowMap.push_back(true);

            } else if (cellColour == GridFrameViewConstants::END_NODE_CELL_COLOUR) {

                m_endPoint = {col,
                              row};

                rowMap.push_back(true);

            } else {

                rowMap.push_back(cellColour != GridFrameViewConstants::BLOCK_NODE_CELL_COLOUR);

            }

        }
        
        gridMap.push_back(rowMap);
        rowMap.clear();

    }

    return gridMap;

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

    this->Bind(wxEVT_TIMER,
               &GridFrame::visualiseNextCell,
               this);

    this->Bind(wxEVT_CLOSE_WINDOW,
               &GridFrame::onClose,
               this);

}

void GridFrame::setCellsSize(int size) {

    wxGrid *grid = m_view.getGrid();

    for (int row = 0; row < GridFrameViewConstants::GRID_COLS; ++row) {

        if (row < GridFrameViewConstants::GRID_ROWS) {

            grid->SetRowSize(row,
                             size);

        }

        grid->SetColSize(row,
                         size);

    }

    grid->Refresh();

}

void GridFrame::OnCellSelected(wxGridEvent &event) {

    if (m_isCurrentlyVisualising) return;

    const int col = event.GetCol();
    const int row = event.GetRow();

    setCellToCurrentNode(row,
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

    setCellsSize(cellSize);

}

void GridFrame::visualiseAlgorithm() {

    if (m_isCurrentlyVisualising) return;

    clearLastTraversalVisualisation();

    m_grid.setGrid(getTraversabilityMap());

    pathAlgs::Grid::SearchResults searchResults = findPath();

    std::vector<wxString> errorMessageList;

    wxString currentAlgorithmError = m_currentAlgoritm == -1 ? MainFrameViewConstants::ALGORITHM_NOT_CHOSEN_ERROR
                                                             : "";
    
    errorMessageList.emplace_back(currentAlgorithmError);
    errorMessageList.emplace_back(searchResults.errorMsg);

    for (const wxString &message : errorMessageList) {

        if (message != "") {

            if (MainFrame *mainFrame = dynamic_cast<MainFrame *>(GetParent())) {

                mainFrame->showError(message);

            }

            return;

        }

    }

    m_isCurrentlyVisualising = true;

    m_visualisationCellColouringTimer->Start(m_visualisationSpeed);

    setLastSearch(searchResults);

    m_view.getGrid()->ClearGrid();

}

void GridFrame::visualiseNextCell(wxTimerEvent &event) {

    if (m_traversalOrder.size() < 1
        && m_shortestPathCurrentNode->getPrecedingNodeRaw()->getPoint() == m_startPoint) {

        m_visualisationCellColouringTimer->Stop();

        m_isCurrentlyVisualising = false;

        return;
    }

    wxGrid *grid = m_view.getGrid();

    wxColour cellColour;

    if (m_traversalOrder.size() > 0) {


        float cellsLeft = m_traversalOrder.size();

        pathAlgs::Point point = m_traversalOrder.front();
        m_traversalOrder.pop_front();

        uint8_t green = ((m_traversalOrderCount - cellsLeft) / m_traversalOrderCount) * 255;
        uint8_t blue = (cellsLeft / m_traversalOrderCount) * 255;

        cellColour.Set(0,
                       green,
                       blue,
                       255);

        grid->SetCellBackgroundColour(point.y,
                                      point.x,
                                      cellColour);
    
    } else {

        m_shortestPathCurrentNode = m_shortestPathCurrentNode->getPrecedingNodeRaw();

        uint8_t green = (m_goalNodeDepth - 1 - m_shortestPathCurrentNode->getDepth()) / m_goalNodeDepth * 255;
        cellColour.Set(255,
                       green,
                       0,
                       255);

        pathAlgs::Point point = m_shortestPathCurrentNode->getPoint();
        grid->SetCellBackgroundColour(point.y,
                                      point.x,
                                      cellColour);

    }

    grid->Refresh();

}

GridFrameView &GridFrame::getView() {

    return m_view;

}

int GridFrame::getCurrentAlgorithm() const {

    return m_currentAlgoritm;

}

void GridFrame::setCurrentAlgorithm(int algorithmIndex,
                                    const wxString &algorithmName) {

    if (m_isCurrentlyVisualising) return;

    m_currentAlgoritm = algorithmIndex;
    this->SetTitle(algorithmName);

}

void GridFrame::setLastSearch(pathAlgs::Grid::SearchResults &searchResults) {

    m_traversalOrder = searchResults.traversalOrder;

    m_lastGoalNode = std::move(searchResults.goalNode);
    m_shortestPathCurrentNode = m_lastGoalNode.get();

    m_goalNodeDepth = m_lastGoalNode->getDepth();

    // so that the start & end cell don't get wiped
    m_traversalOrder.pop_front();
    m_traversalOrder.pop_back();

    m_lastTraversalOrder = m_traversalOrder;

    m_traversalOrderCount = m_lastTraversalOrder.size();

}

void GridFrame::clearLastTraversalVisualisation() {

    for (const pathAlgs::Point &point : m_lastTraversalOrder) {

        m_view.getGrid()->SetCellBackgroundColour(point.y,
                                                  point.x,
                                                  *wxWHITE);

    }

    m_lastTraversalOrder.clear();

}

void GridFrame::setCellToCurrentNode(int row,
                                     int col) {

    clearLastTraversalVisualisation();

    NodeTypeSetCellProcessor nodeTypeSetCellProcessor(&m_view,
                                                      row,
                                                      col);

    nodeTypeSetCellProcessor.process();

}

void GridFrame::onClose(wxCloseEvent &event) {

    m_visualisationCellColouringTimer->Stop();

    event.Skip();

}

pathAlgs::Grid::SearchResults GridFrame::findPath() {

    MainFrame* mainFrame = static_cast<MainFrame*>(GetParent());
    wxString algorithm   = mainFrame->getView().getAlgorithmComboBox()->GetValue();

    if (algorithm == MainFrameViewConstants::ALGORITHM_DIJKSTRA) {

        return m_grid.findPathDijkstra(m_startPoint,
                                       m_endPoint);

    }
    else if (algorithm == MainFrameViewConstants::ALGORITHM_A_STAR) {

        return  m_grid.findPathAStar(m_startPoint,
                                     m_endPoint);

    }
    else if (algorithm == MainFrameViewConstants::ALGORITHM_HPA_STAR) {

        return m_grid.findPathHPAStar(m_startPoint,
                                      m_endPoint);

    }
    else {

        return pathAlgs::Grid::SearchResults();

    }

}
