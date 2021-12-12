#include "NodeTypeSetCellSelectableProcessor.h"
#include "GridFrameView.h"

NodeTypeSetCellSelectableProcessor::NodeTypeSetCellSelectableProcessor(GridFrameView * const gridFrameView,
                                                                       int row,
                                                                       int col)
    : m_gridFrameView{gridFrameView},
      m_row{row},
      m_col{col} {
}

void NodeTypeSetCellSelectableProcessor::process() {

    if (matches()) {

        setCell();

        m_gridFrameView->getGrid()->Refresh();

    }

}

void NodeTypeSetCellSelectableProcessor::setCell() {

    wxGrid * grid = m_gridFrameView->getGrid();

    grid->SetCellBackgroundColour(m_row,
                                  m_col,
                                  m_gridFrameView->getCurrentNodeColour());

}
