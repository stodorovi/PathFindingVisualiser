#ifndef END_NODE_TYPE_SET_CELL_PROCESSOR
#define END_NODE_TYPE_SET_CELL_PROCESSOR

#include "SingleCellNodeTypeSetCellProcessor.h"

class EndNodeTypeSetCellProcessor : public SingleCellNodeTypeSetCellProcessor {

public:

    EndNodeTypeSetCellProcessor(GridFrameView * const gridFrameView,
                                int row,
                                int col);

    virtual bool matches() override;

};

#endif // !END_NODE_TYPE_SET_CELL_PROCESSOR
