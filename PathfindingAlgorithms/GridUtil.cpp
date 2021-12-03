#include "GridUtil.h"

namespace pathAlgs {

    namespace grid_util {

        size_t numberOfPointsInGrid(const GridMap &grid) {

            return (grid.size() == 0) ? 0 : grid.size() * grid[0].size();

        }

        std::vector<Point> getSurroundingPoints(const GridMap &grid,
                                                Point point) {

            std::vector<Point> surroundingPoints;

            bool firstColumn = point.x == 0;
            bool lastColumn = point.x == grid[0].size() - 1;
            bool firstRow = point.y == 0;
            bool lastRow = point.y == grid.size() - 1;

            if (grid.size() == 0) {

                return surroundingPoints;

            }

            bool leftPointTraversable = firstColumn ? false : grid[point.y][point.x - 1];
            bool rightPointTraversable = lastColumn ? false : grid[point.y][point.x + 1];
            bool topPointTraversable = firstRow ? false : grid[point.y - 1][point.x];
            bool bottomPointTraversable = lastRow ? false : grid[point.y + 1][point.x];

            bool topLeftTraversable = (topPointTraversable && leftPointTraversable) ? grid[point.y - 1][point.x - 1] : false;
            bool topRightTraversable = (topPointTraversable && rightPointTraversable) ? grid[point.y - 1][point.x + 1] : false;
            bool bottomLeftTraversable = (bottomPointTraversable && leftPointTraversable) ? grid[point.y + 1][point.x - 1] : false;
            bool bottomRightTraversable = (bottomPointTraversable && leftPointTraversable) ? grid[point.y + 1][point.x + 1] : false;

            if (!rightPointTraversable
                && !leftPointTraversable
                && !topPointTraversable
                && !bottomPointTraversable) {

                return surroundingPoints;

            }

            if (rightPointTraversable) {

                surroundingPoints.push_back(Point(point.x + 1,
                    point.y));

            }

            if (leftPointTraversable) {

                surroundingPoints.push_back(Point(point.x - 1,
                    point.y));

            }

            if (topPointTraversable) {

                surroundingPoints.push_back(Point(point.x,
                    point.y - 1));

            }

            if (bottomPointTraversable) {

                surroundingPoints.push_back(Point(point.x,
                    point.y + 1));

            }

            if (topLeftTraversable) {

                surroundingPoints.push_back(Point(point.x - 1,
                    point.y - 1));

            }

            if (topRightTraversable) {

                surroundingPoints.push_back(Point(point.x + 1,
                    point.y - 1));

            }

            if (bottomLeftTraversable) {

                surroundingPoints.push_back(Point(point.x - 1,
                    point.y + 1));

            }

            if (bottomRightTraversable) {

                surroundingPoints.push_back(Point(point.x + 1,
                    point.y + 1));

            }

            return surroundingPoints;

        }

        size_t numberOfTraversableGridPoints(const GridMap &grid) {

            size_t numberOfTraversablePoints = 0;

            for (auto &row : grid) {

                for (bool traversable : row) {

                    numberOfTraversablePoints += static_cast<size_t>(traversable);

                }

            }

            return numberOfTraversablePoints;

        }

        void initialiseGridNodes(std::vector<std::unique_ptr<GridNode>> &gridNodesVector,
                                 const GridMap &grid) {

            gridNodesVector.clear();
            gridNodesVector.reserve(numberOfPointsInGrid(grid));
            
            for (size_t row = 0; row < grid.size(); ++row) {

                for (size_t column = 0; column < grid[row].size(); ++column) {

                    gridNodesVector.push_back(std::make_unique<GridNode>(nullptr,
                                                                         false,
                                                                         pathAlgs::Point{static_cast<int>(column),
                                                                                         static_cast<int>(row)}));

                }

            }

        }

        size_t findGridNodeIndexByPoint(Point point,
                                        const std::vector<std::unique_ptr<GridNode>> nodes) {

            for (size_t i = 0; i < nodes.size(); ++i) {

                if (nodes[i]->getPoint() == point) {

                    return i;

                }
            }

            return -1;

        }

        bool validateStartAndEndPositions(Point startPoint,
                                          Point endPoint,
                                          std::vector<std::unique_ptr<GridNode>> &gridNodeGrid) {

            return (findGridNodeIndexByPoint(startPoint, gridNodeGrid) != -1)
                && (findGridNodeIndexByPoint(endPoint, gridNodeGrid) != -1);

        }

        void calculateDistanceFromSurroundingPoints(GridNode &node,
                                                    std::vector<Point> &surroundingPoints,
                                                    std::deque<Point> &visitedPoints,
                                                    std::deque<Point> &unvisitedPoints,
                                                    std::vector<std::unique_ptr<GridNode>> &gridNodes) {

            if (surroundingPoints.size() == 0) {
                    
                return;

            }
            
            for (Point point : surroundingPoints) {

                if (std::find(visitedPoints.begin(), visitedPoints.end(), point) != visitedPoints.end()) {

                    continue;

                }

                size_t surroundingNodeIndex = grid_util::findGridNodeIndexByPoint(point,
                                                                                  gridNodes);
                GridNode &surroundingNode = *gridNodes[surroundingNodeIndex];

                if ((node.getDistance() + 1) < surroundingNode.getDistance()) {

                    surroundingNode.setDistance(node.getDistance() + 1);
                    surroundingNode.setPrecedingNode(node);

                }

                unvisitedPoints.push_back(point);

            }

            unvisitedPoints.pop_front();
            visitedPoints.push_back(node.getPoint());

        }

    }

}