#include "StartNodeTypeSetCellProcessor.h"
#include "GridFrameView.h"

StartNodeTypeSetCellProcessor::StartNodeTypeSetCellProcessor(GridFrameView *gridFrameView,
                                                             int row,
                                                             int col)
    : super{gridFrameView,
            row,
            col} {
}

bool StartNodeTypeSetCellProcessor::matches() {

    return m_gridFrameView->getCurrentNodeType() == PlaceableNodeType::START;

}
