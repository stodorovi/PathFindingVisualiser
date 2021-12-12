#include "BlockNodeTypeSetCellProcessor.h"
#include "GridFrameView.h"

BlockNodeTypeSetCellProcessor::BlockNodeTypeSetCellProcessor(GridFrameView * const gridFrameView,
                                                             int row,
                                                             int col)
    : super{gridFrameView,
            row,
            col} {
}

bool BlockNodeTypeSetCellProcessor::matches() {

    return m_gridFrameView->getCurrentNodeType() == PlaceableNodeType::BLOCK;

}
