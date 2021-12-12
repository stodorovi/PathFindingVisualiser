#ifndef NODE_TYPE_SET_CELL_SELECTABLE_PROCESSOR_H
#define NODE_TYPE_SET_CELL_SELECTABLE_PROCESSOR_H

#include "PlaceableNodeType.h"

/** forward declaration - circular dependancy */
class GridFrameView;

class NodeTypeSetCellSelectableProcessor {

protected:

    /** @brief Abbreviation for the base class NodeTypeSetCellSelectableProcessor. */
    using super = NodeTypeSetCellSelectableProcessor;

    GridFrameView * const m_gridFrameView;

    int m_row;
    int m_col;

    virtual void setCell();

public:

    NodeTypeSetCellSelectableProcessor(GridFrameView * const gridFrameView,
                                       int row,
                                       int col);

    void process();

    virtual bool matches() = 0;

};

#endif // !NODE_TYPE_SET_CELL_SELECTABLE_PROCESSOR_H
