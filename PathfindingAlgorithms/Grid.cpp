#include "Grid.h"

namespace pathAlgs {

    Grid::Grid() {}

    Grid::Grid(const GridMap &gridMap)
        : m_gridMap{gridMap} {

        initGrid();

    }

    void Grid::initGrid() {

        m_grid.clear();
        m_grid.reserve(sizeOfGrid());

        for (size_t row = 0; row < m_gridMap.size(); ++row) {

            for (size_t column = 0; column < m_gridMap[row].size(); ++column) {

                m_grid.push_back(std::make_unique<GridNode>(nullptr,
                                                            Point{static_cast<int>(column),
                                                                  static_cast<int>(row)}));

            }

        }

    }

    bool Grid::validateStartAndEndPoint(Point start,
                                        Point end) const {

        return (findGridNodeIndexByPoint(start) != -1)
            && (findGridNodeIndexByPoint(end) != -1);

    }

    size_t Grid::sizeOfGrid() const {

        size_t rows = m_gridMap.size();
        size_t columns = m_gridMap[0].size();

        return (m_gridMap.size() == 0) ? 0 : (rows * columns);

    }

    size_t Grid::findGridNodeIndexByPoint(Point point) const {

        for (size_t i = 0; i < m_grid.size(); ++i) {

            if (m_grid[i]->getPoint() == point) {

                return i;

            }
        }

        return -1;

    }

    void Grid::calculateDistancesFromSurroundingPoints(const GridNode &node,
                                                       std::vector<Point> &surroundingPoints,
                                                       std::deque<Point> &visitedPoints,
                                                       std::deque<Point> &unvisitedPoints) const {

        Point nodePoint = node.getPoint();

        if (surroundingPoints.size() == 0) {

            if (std::find(visitedPoints.begin(),
                          visitedPoints.end(),
                          nodePoint) == visitedPoints.end()) {

                visitedPoints.push_back(nodePoint);

            }

            unvisitedPoints.pop_front();

            return;

        }

        for (Point point : surroundingPoints) {

            if (std::find(visitedPoints.begin(),
                          visitedPoints.end(),
                          point) != visitedPoints.end()
                || std::find(unvisitedPoints.begin(),
                             unvisitedPoints.end(),
                             point) != unvisitedPoints.end()) {

                continue;

            }

            size_t surroundingNodeIndex = findGridNodeIndexByPoint(point);
            GridNode &surroundingNode = *m_grid[surroundingNodeIndex];

            if ((node.getDistance() + 1) < surroundingNode.getDistance()) {

                surroundingNode.setDistance(node.getDistance() + 1);
                surroundingNode.setPrecedingNode(std::make_unique<GridNode>(node));

            }

            unvisitedPoints.push_back(point);

        }

        if (std::find(visitedPoints.begin(),
                      visitedPoints.end(),
                      nodePoint) == visitedPoints.end()) {
         
            visitedPoints.push_back(nodePoint);

        }

    }

    std::vector<Point> Grid::getSurroundingPoints(const Point &point) const {

        std::vector<Point> surroundingPoints;

        bool firstColumn = point.x == 0;
        bool lastColumn  = point.x == m_gridMap[0].size() - 1;
        bool firstRow    = point.y == 0;
        bool lastRow     = point.y == m_gridMap.size() - 1;

        if (m_gridMap.size() == 0) {

            return surroundingPoints;

        }

        bool leftPointTraversable   = firstColumn ? false : m_gridMap[point.y]    [point.x - 1];
        bool rightPointTraversable  = lastColumn  ? false : m_gridMap[point.y]    [point.x + 1];
        bool topPointTraversable    = firstRow    ? false : m_gridMap[point.y - 1][point.x];
        bool bottomPointTraversable = lastRow     ? false : m_gridMap[point.y + 1][point.x];

        bool topLeftTraversable     = (firstColumn || firstRow) ? false : m_gridMap[point.y - 1][point.x - 1];
        bool topRightTraversable    = (lastColumn  || firstRow) ? false : m_gridMap[point.y - 1][point.x + 1];
        bool bottomLeftTraversable  = (firstColumn || lastRow)  ? false : m_gridMap[point.y + 1][point.x - 1];
        bool bottomRightTraversable = (lastColumn  || lastRow)  ? false : m_gridMap[point.y + 1][point.x + 1];

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

    void Grid::setGrid(const GridMap &gridMap) {
    
        m_gridMap = gridMap;

        initGrid();
    
    }

    Grid::SearchResults Grid::findPathDijkstra(Point startPoint,
                                               Point endPoint) const {
        
        std::deque<Point> traversalOrder;
        GridNode *goalNode = nullptr;
        bool foundGoal = false;
        bool isValidSearch = false;

        std::string errorMsg;


        if (m_grid.size() == 0
         || validateStartAndEndPoint(startPoint,
                                     endPoint) == false) {

            errorMsg = m_grid.size() == 0 ? gridConstants::INVALID_GRID_SIZE_ERROR_MSG
                                          : gridConstants::INVALID_NODE_POSITION_ERROR_MSG;

            return  SearchResults(traversalOrder,
                                  nullptr,
                                  foundGoal,
                                  isValidSearch,
                                  errorMsg);

        }

        std::deque<Point> visitedPoints;

        std::deque<Point> unvisitedPoints;
        unvisitedPoints.push_back(startPoint);

        do {

            Point currentNodePoint = unvisitedPoints.front();
            size_t currentNodeIndex = findGridNodeIndexByPoint(currentNodePoint);
            
            GridNode &currentNode = *m_grid[currentNodeIndex];

            if (currentNode.getPoint() == endPoint) break;
            
            if (currentNode.getPoint() == startPoint) {

                currentNode.setDistance(currentNode.getDistanceFromSelf());

            }

            std::vector<Point> surroundingPoints =  getSurroundingPoints(currentNode.getPoint());

            if (surroundingPoints.size()) {

                calculateDistancesFromSurroundingPoints(currentNode,
                                                        surroundingPoints,
                                                        visitedPoints,
                                                        unvisitedPoints);

            }

            unvisitedPoints.pop_front();

        } while (unvisitedPoints.size());

        const std::unique_ptr<GridNode> &endNode =  m_grid[findGridNodeIndexByPoint(endPoint)];

        if (endNode->getPrecedingNodeRaw()) {

            goalNode = endNode.get();

        } else {

            return SearchResults(traversalOrder,
                                 goalNode,
                                 false,
                                 true,
                                 gridConstants::GOAL_UNREACHABLE_ERROR_MSG);

        }

        visitedPoints.push_back(goalNode->getPoint());
        traversalOrder = visitedPoints;
        isValidSearch = true;
        foundGoal = static_cast<bool>(goalNode);

        return SearchResults(traversalOrder,
                             goalNode,
                             foundGoal,
                             isValidSearch,
                             errorMsg);

    }

}