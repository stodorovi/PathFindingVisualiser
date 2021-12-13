#ifndef SINGLE_CELL_NODE_TYPE_SET_CELL_PROCESSOR
#define SINGLE_CELL_NODE_TYPE_SET_CELL_PROCESSOR

#include <functional>
#include <map>

#include "NodeTypeSetCellSelectableProcessor.h"

/** @brief Abstract single cell setting processor. */
class SingleCellNodeTypeSetCellProcessor : public NodeTypeSetCellSelectableProcessor {

protected:

    /** Abbreviation for the base class SingleCellNodeTypeSetCellProcessor. */
    using super = SingleCellNodeTypeSetCellProcessor;

    const std::map<PlaceableNodeType,
                   std::function<void()>> m_nodeTypeSetCellFunctionMap;

    /** @brief Start type node cell placement. */
    void setCellStart();

    /** @brief End type node cell placement. */
    void setCellEnd();

protected:

    /** @brief Cell setting method for single cell node types. */
    virtual void setCell() override;

public:

    /**
    * @brief Constructor
    *
    * @param gridFrameView - gridFrameView to set the sell for
    * @param row - cell row position
    * @param col - cell column position
    */
    SingleCellNodeTypeSetCellProcessor(GridFrameView * const gridFrameView,
                                       int row,
                                       int col);


};

#endif // !SINGLE_CELL_NODE_TYPE_SET_CELL_PROCESSOR
