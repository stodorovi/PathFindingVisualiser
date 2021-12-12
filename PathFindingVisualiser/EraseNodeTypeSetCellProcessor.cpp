#include "EraseNodeTypeSetCellProcessor.h"
#include "GridFrameView.h"

EraseNodeTypeSetCellProcessor::EraseNodeTypeSetCellProcessor(GridFrameView * const gridFrameView,
                                                             int row,
                                                             int col) 
    : super(gridFrameView,
            row,
            col) {
}

bool EraseNodeTypeSetCellProcessor::matches() {

    return m_gridFrameView->getCurrentNodeType() == PlaceableNodeType::ERASE;

}
