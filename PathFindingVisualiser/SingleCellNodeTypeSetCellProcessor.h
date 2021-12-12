#ifndef SINGLE_CELL_NODE_TYPE_SET_CELL_PROCESSOR
#define SINGLE_CELL_NODE_TYPE_SET_CELL_PROCESSOR

#include "NodeTypeSetCellSelectableProcessor.h"

#include <map>
#include <functional>

class SingleCellNodeTypeSetCellProcessor : public NodeTypeSetCellSelectableProcessor {

protected:

    /** Abbreviation for the base class SingleCellNodeTypeSetCellProcessor. */
    using super = SingleCellNodeTypeSetCellProcessor;

    std::map<PlaceableNodeType,
             std::function<void()>> m_nodeTypeSetCellFunctionMap;

    void setCellStart();

    void setCellEnd();

protected:

    virtual void setCell() override;

public:

    SingleCellNodeTypeSetCellProcessor(GridFrameView * const gridFrameView,
                                       int row,
                                       int col);


};

#endif // !SINGLE_CELL_NODE_TYPE_SET_CELL_PROCESSOR
