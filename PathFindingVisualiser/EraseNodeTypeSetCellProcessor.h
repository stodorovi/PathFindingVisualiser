#ifndef ERASE_NODE_TYPE_SET_CELL_PROCESSOR
#define ERASE_NODE_TYPE_SET_CELL_PROCESSOR

#include "NodeTypeSetCellSelectableProcessor.h"

/** @brief Processor for ERASING the node in a cell. */
class EraseNodeTypeSetCellProcessor : public NodeTypeSetCellSelectableProcessor {

public:

    /**
    * @brief Constructor
    *
    * @param gridFrameView - gridFrameView to set the sell for
    * @param row - cell row position
    * @param col - cell column position
    */
    EraseNodeTypeSetCellProcessor(GridFrameView * const gridFrameView,
                                  int row,
                                  int col);

    /** @brief Checks if the processor matches the one that is triggered. */
    virtual bool matches() override;

};

#endif // !ERASE_NODE_TYPE_SET_CELL_PROCESSOR
