#ifndef ERASE_NODE_TYPE_SET_CELL_PROCESSOR
#define ERASE_NODE_TYPE_SET_CELL_PROCESSOR

#include "NodeTypeSetCellSelectableProcessor.h"

class EraseNodeTypeSetCellProcessor : public NodeTypeSetCellSelectableProcessor {

public:

    EraseNodeTypeSetCellProcessor(GridFrameView * const gridFrameView,
                                  int row,
                                  int col);

    virtual bool matches() override;

};

#endif // !ERASE_NODE_TYPE_SET_CELL_PROCESSOR
