#include "SingleCellNodeTypeSetCellProcessor.h"
#include "GridFrameView.h"

SingleCellNodeTypeSetCellProcessor::SingleCellNodeTypeSetCellProcessor(GridFrameView * const gridFrameView,
                                                                       int row,
                                                                       int col) 
    : NodeTypeSetCellSelectableProcessor::super{gridFrameView,
                                                row,
                                                col},
      m_nodeTypeSetCellFunctionMap {

          {PlaceableNodeType::START,
           std::bind(&SingleCellNodeTypeSetCellProcessor::setCellStart,
           this)},

          {PlaceableNodeType::END,
           std::bind(&SingleCellNodeTypeSetCellProcessor::setCellEnd,
           this)} }
{
}


void SingleCellNodeTypeSetCellProcessor::setCell() {

    NodeTypeSetCellSelectableProcessor::super::setCell();

    auto& thisNodeSetCell = m_nodeTypeSetCellFunctionMap.at(m_gridFrameView->getCurrentNodeType());

    thisNodeSetCell();
    
}

void SingleCellNodeTypeSetCellProcessor::setCellStart() {

    bool notFirstTimeNodePlacement = m_gridFrameView->getPreviousStartPoint()
        != GridFrameViewConstants::INVALID_CELL_POSITION;

    bool nodePointSameAsLast = m_gridFrameView->getPreviousStartPoint()
        != wxPoint{m_col,
                   m_row};

    if (notFirstTimeNodePlacement
        && nodePointSameAsLast) {

        wxGrid *grid = m_gridFrameView->getGrid();

        wxPoint previousStart = m_gridFrameView->getPreviousStartPoint();

        if (grid->GetCellBackgroundColour(previousStart.y,
                                          previousStart.x)
            == GridFrameViewConstants::START_NODE_CELL_COLOUR) {

            grid->SetCellBackgroundColour(previousStart.y,
                                          previousStart.x,
                                          GridFrameViewConstants::DEFAULT_CELL_COLOUR);

        }

    }

    m_gridFrameView->setPreviousStartPoint(wxPoint{m_col,
                                                   m_row});

}

void SingleCellNodeTypeSetCellProcessor::setCellEnd() {

    bool notFirstTimeNodePlacement = m_gridFrameView->getPreviousEndPoint()
        != GridFrameViewConstants::INVALID_CELL_POSITION;

    bool nodePointSameAsLast = m_gridFrameView->getPreviousEndPoint()
        != wxPoint{m_col,
                   m_row};

    if (notFirstTimeNodePlacement
        && nodePointSameAsLast) {

        wxGrid *grid = m_gridFrameView->getGrid();

        wxPoint previousEnd = m_gridFrameView->getPreviousEndPoint();

        if (grid->GetCellBackgroundColour(previousEnd.y,
                                          previousEnd.x)
            == GridFrameViewConstants::END_NODE_CELL_COLOUR) {

            grid->SetCellBackgroundColour(previousEnd.y,
                                          previousEnd.x,
                                          GridFrameViewConstants::DEFAULT_CELL_COLOUR);

        }


    }

    m_gridFrameView->setPreviousEndPoint(wxPoint{m_col,
                                                  m_row});

}