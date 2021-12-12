#ifndef START_NODE_TYPE_SET_CELL_PROCESSOR
#define START_NODE_TYPE_SET_CELL_PROCESSOR

#include "SingleCellNodeTypeSetCellProcessor.h"

class StartNodeTypeSetCellProcessor : public SingleCellNodeTypeSetCellProcessor {

public:

    StartNodeTypeSetCellProcessor(GridFrameView * const gridFrameView,
                                  int row,
                                  int col);

    virtual bool matches();

};

#endif // !START_NODE_TYPE_SET_CELL_PROCESSOR
