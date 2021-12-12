#include "SingleCellNodeTypeSetCellProcessor.h"
#include "GridFrameView.h"

EndNodeTypeSetCellProcessor::EndNodeTypeSetCellProcessor(GridFrameView * const gridFrameView,
                                                         int row,
                                                         int col) 
    : super{gridFrameView,
            row,
            col} {
}

bool EndNodeTypeSetCellProcessor::matches() {

    return m_gridFrameView->getCurrentNodeType() == PlaceableNodeType::END;

}
