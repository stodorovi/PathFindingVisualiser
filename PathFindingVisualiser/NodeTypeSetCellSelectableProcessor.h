#ifndef NODE_TYPE_SET_CELL_SELECTABLE_PROCESSOR_H
#define NODE_TYPE_SET_CELL_SELECTABLE_PROCESSOR_H

#include "PlaceableNodeType.h"

/** forward declaration - circular dependancy */
class GridFrameView;

/** @brief Abstract selectable processor. Should call super if overriding setCell method. */
class NodeTypeSetCellSelectableProcessor {

private:

    /** @brief Checks if the processor matches the one that is triggered. */
    virtual bool matches() = 0;


protected:

    /** @brief Abbreviation for the base class NodeTypeSetCellSelectableProcessor. */
    using super = NodeTypeSetCellSelectableProcessor;

    GridFrameView * const m_gridFrameView;

    int m_row;
    int m_col;

    /** @brief Set the cell. Call super if overriding. */
    virtual void setCell();

public:

    /**
    * @brief Constructor
    *
    * @param gridFrameView - gridFrameView to set the sell for
    * @param row - cell row position
    * @param col - cell column position
    */
    NodeTypeSetCellSelectableProcessor(GridFrameView * const gridFrameView,
                                       int row,
                                       int col);

    /** @brief Process the setting of the selected cell. */
    void process();

};

#endif // !NODE_TYPE_SET_CELL_SELECTABLE_PROCESSOR_H
