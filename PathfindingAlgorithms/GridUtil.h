#ifndef GRID_UTIL_H
#define GRID_UTIL_H

#include "GridNode.h"
#include "Point.h"

#include <memory>
#include <vector>
#include <queue>

namespace pathAlgs {

    namespace grid_util {

        size_t numberOfPointsInGrid(const GridMap &grid);

        std::vector<Point> getSurroundingPoints(const GridMap &grid,
                                                Point point);

        size_t numberOfTraversableGridPoints(const GridMap &grid);

        void calculateDistanceFromSurroundingPoints(GridNode &node,
                                                   std::vector<Point> &surroundingPoints,
                                                   std::deque<Point> &visitedPoints,
                                                   std::deque<Point> &unvisitedPoints,
                                                   std::vector<std::unique_ptr<GridNode>> &gridNodes);

        /**
         * @brief Initialises the gridNodesVector based on the grid,
         * erases the old one.
         * 
         * @param gridNodesVector the GridNodes vector to be initialised
         * @param grid
        */
        void initialiseGridNodes(std::vector<std::unique_ptr<GridNode>> &gridNodesVector,
                                 const GridMap &grid);

        /**
         * @brief Finds the index of the node in the list by its point.
         * 
         * @param - point the point of the node to find
         * @param - nodes vector of nodes to search through
         * 
         * @return index of the node in the vector, returns -1 if not found.
        */
        size_t findGridNodeIndexByPoint(Point point,
                                        const std::vector<std::unique_ptr<GridNode>> nodes);

        bool validateStartAndEndPositions(Point startPoint,
                                          Point endPoint,
                                          std::vector<std::unique_ptr<GridNode>> gridNodeGrid);

    }

}

#endif // !GRID_UTIL_H
