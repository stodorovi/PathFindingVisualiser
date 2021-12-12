#ifndef BLOCK_NODE_TYPE_SET_CELL_PROCESSOR
#define BLOCK_NODE_TYPE_SET_CELL_PROCESSOR

#include "NodeTypeSetCellSelectableProcessor.h"

/** @brief Processor for setting the BLOCK type node in a cell. */
class BlockNodeTypeSetCellProcessor : public NodeTypeSetCellSelectableProcessor {

public:

    BlockNodeTypeSetCellProcessor(GridFrameView * const gridFrameView,
                                  int row,
                                  int col);

    virtual bool matches() override;

};

#endif // !BLOCK_NODE_TYPE_SET_CELL_PROCESSOR
