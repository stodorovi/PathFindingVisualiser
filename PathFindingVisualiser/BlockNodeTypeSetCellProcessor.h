#ifndef BLOCK_NODE_TYPE_SET_CELL_PROCESSOR
#define BLOCK_NODE_TYPE_SET_CELL_PROCESSOR

#include "NodeTypeSetCellSelectableProcessor.h"

/** @brief Processor for setting the BLOCK type node in a cell. */
class BlockNodeTypeSetCellProcessor : public NodeTypeSetCellSelectableProcessor {

public:

    /**
     * @brief Constructor
     *
     * @param gridFrameView - gridFrameView to set the sell for
     * @param row - cell row position
     * @param col - cell column position
    */
    BlockNodeTypeSetCellProcessor(GridFrameView * const gridFrameView,
                                  int row,
                                  int col);

    /** @brief Checks if the processor matches the one that is triggered. */
    virtual bool matches() override;

};

#endif // !BLOCK_NODE_TYPE_SET_CELL_PROCESSOR
