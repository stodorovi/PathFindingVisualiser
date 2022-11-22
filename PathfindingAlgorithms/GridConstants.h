#ifndef GRID_CONSTANTS_H
#define GRID_CONSTANTS_H

#include <memory>

namespace pathAlgs {

    class GridNode;

    using ClearanceMap = std::vector<std::vector<size_t>>;
    using TraversabilityMap = std::vector<std::vector<bool>>;
    using GridNodePtr       = std::shared_ptr<GridNode>;
    using GridNodeVector    = std::vector<std::vector<GridNodePtr>>;

    static constexpr const char *INVALID_GRID_SIZE_ERROR_MSG     = "The grid size is invalid.\n\n"
                                                                   "Make sure the grid size is bigger than zero.";

    static constexpr const char *INVALID_NODE_POSITION_ERROR_MSG = "The starting and/or ending node position is invalid.\n\n"
                                                                   "Make sure the nodes are inside the valid grid position.";

    static constexpr const char *GOAL_UNREACHABLE_ERROR_MSG      = "The path not found!\n\n"
                                                                   "The path to the goal node is unreachable,\n"
                                                                   " it is obstructed and the goal can not be reached.";

}

#endif // !GRID_CONSTANTS_H
