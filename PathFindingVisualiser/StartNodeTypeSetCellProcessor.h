#ifndef START_NODE_TYPE_SET_CELL_PROCESSOR
#define START_NODE_TYPE_SET_CELL_PROCESSOR

#include "SingleCellNodeTypeSetCellProcessor.h"

/** @brief Processor for setting the START type node in a cell. */
class StartNodeTypeSetCellProcessor : public SingleCellNodeTypeSetCellProcessor {

public:

    /**
     * @brief Constructor
     *
     * @param gridFrameView - gridFrameView to set the sell for
     * @param row - cell row position
     * @param col - cell column position
    */
    StartNodeTypeSetCellProcessor(GridFrameView * const gridFrameView,
                                  int row,
                                  int col);

    /** @brief Checks if the processor matches the one that is triggered. */
    virtual bool matches();

};

#endif // !START_NODE_TYPE_SET_CELL_PROCESSOR
