#ifndef NODE_TYPE_SET_CELL_PROCESSOR
#define NODE_TYPE_SET_CELL_PROCESSOR

#include <memory>
#include <vector>

#include "StartNodeTypeSetCellProcessor.h"
#include "EndNodeTypeSetCellProcessor.h"
#include "BlockNodeTypeSetCellProcessor.h"
#include "EraseNodeTypeSetCellProcessor.h"

/** Forward declaration - circular dependancy */
class GridFrameView;

class NodeTypeSetCellProcessor {

private:

    std::vector<std::unique_ptr<NodeTypeSetCellSelectableProcessor>> m_processors;

public:

    NodeTypeSetCellProcessor(GridFrameView * const gridFrameView,
                             int row,
                             int col);

    void process();
            
};

#endif // !NODE_TYPE_SET_CELL_PROCESSOR
