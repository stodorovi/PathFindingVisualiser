#include "DijkstraAlgorithm.h"

#include <algorithm>
#include <stdexcept>

namespace pathAlgs {

    const GridNode findPathDijkstra(GridNode &node,
                                    Grid grid,
                                    Point startingPoint,
                                    Point endPoint) {

        GridNode returnNode;

        std::vector<std::unique_ptr<GridNode>> gridNodes;
        grid_util::initialiseGridNodes(gridNodes,
                                       grid);


        if (!gridNodes.size()) {

            return returnNode;

        }

        bool positionsValidationResult = grid_util::validateStartAndEndPositions(startingPoint,
                                                                                 endPoint,
                                                                                 gridNodes);
       
        if (positionsValidationResult == false) {

            returnNode;

        }
        
        std::deque<Point> visitedPoints;
        std::deque<Point> unvisitedPoints;
        unvisitedPoints.push_back(startingPoint);

        do {

            Point currentNodePoint = unvisitedPoints.back();
            size_t currentNodeIndex = grid_util::findGridNodeIndexByPoint(currentNodePoint,
                                                                          gridNodes);
            GridNode *currentNode = gridNodes[currentNodeIndex].get();

            std::vector<Point> surroundingPoints = grid_util::getSurroundingPoints(grid,
                                                                                   unvisitedPoints.back());

            grid_util::calculateDistanceFromSurroundingPoints(*currentNode,
                                                              surroundingPoints,
                                                              visitedPoints,
                                                              unvisitedPoints,
                                                              gridNodes);

        } while (unvisitedPoints.size());

        GridNode &goalNode = *gridNodes[grid_util::findGridNodeIndexByPoint(endPoint, gridNodes)];
        returnNode = goalNode;

        /*
        //napraviti deleter
        for (auto &node : gridNodes) {
            node->setPrecedingNode(nullptr);
        }
        */
        node = returnNode;

        return GridNode();

    }



}