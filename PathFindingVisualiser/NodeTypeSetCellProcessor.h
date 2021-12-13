#ifndef NODE_TYPE_SET_CELL_PROCESSOR
#define NODE_TYPE_SET_CELL_PROCESSOR

#include <memory>
#include <vector>

#include "BlockNodeTypeSetCellProcessor.h"
#include "EndNodeTypeSetCellProcessor.h"
#include "EraseNodeTypeSetCellProcessor.h"
#include "StartNodeTypeSetCellProcessor.h"

/** Forward declaration - circular dependancy */
class GridFrameView;

/** @brief Processor that selects the matching sub-processor to process the setting of the cell type on the grid. */
class NodeTypeSetCellProcessor {

private:

    /** @brief Vector of sub-processors */
    std::vector<std::unique_ptr<NodeTypeSetCellSelectableProcessor>> m_processors;

public:

    /**
     * @brief Constructor
     * 
     * @param gridFrameView - gridFrameView to set the sell for
     * @param row - cell row position
     * @param col - cell column position
    */
    NodeTypeSetCellProcessor(GridFrameView * const gridFrameView,
                             int row,
                             int col);

    /** @brief Select the matching processor. */
    void process();
            
};

#endif // !NODE_TYPE_SET_CELL_PROCESSOR
