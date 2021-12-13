#ifndef END_NODE_TYPE_SET_CELL_PROCESSOR
#define END_NODE_TYPE_SET_CELL_PROCESSOR

#include "SingleCellNodeTypeSetCellProcessor.h"

/** @brief Processor for setting the END type node in a cell. */
class EndNodeTypeSetCellProcessor : public SingleCellNodeTypeSetCellProcessor {

public:

    /**
    * @brief Constructor
    *
    * @param gridFrameView - gridFrameView to set the sell for
    * @param row - cell row position
    * @param col - cell column position
    */
    EndNodeTypeSetCellProcessor(GridFrameView * const gridFrameView,
                                int row,
                                int col);

    /** @brief Checks if the processor matches the one that is triggered. */
    virtual bool matches() override;

};

#endif // !END_NODE_TYPE_SET_CELL_PROCESSOR
