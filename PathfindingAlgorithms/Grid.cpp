#include "Grid.h"
#include <algorithm>
#include <map>
#include <optional>

namespace {

    std::vector<pathAlgs::Point> getSurroundingPoints(const pathAlgs::GridNodePtr n,
                                                      const pathAlgs::TraversabilityMap &t) {

        pathAlgs::Point point = n->getPoint();

        std::vector<pathAlgs::Point> surroundingPoints;

        bool firstColumn = point.x == 0;
        bool lastColumn = point.x == t[0].size() - 1;
        bool firstRow = point.y == 0;
        bool lastRow = point.y == t.size() - 1;

        if (t.size() == 0) {

            return surroundingPoints;

        }

        bool leftPointTraversable = !firstColumn && t[point.y][point.x - 1];
        bool rightPointTraversable = !lastColumn && t[point.y][point.x + 1];
        bool topPointTraversable = !firstRow && t[point.y - 1][point.x];
        bool bottomPointTraversable = !lastRow && t[point.y + 1][point.x];

        bool topLeftTraversable = !(firstColumn || firstRow) && t[point.y - 1][point.x - 1];
        bool topRightTraversable = !(lastColumn || firstRow) && t[point.y - 1][point.x + 1];
        bool bottomLeftTraversable = !(firstColumn || lastRow) && t[point.y + 1][point.x - 1];
        bool bottomRightTraversable = !(lastColumn || lastRow) && t[point.y + 1][point.x + 1];

        if (!rightPointTraversable
            && !leftPointTraversable
            && !topPointTraversable
            && !bottomPointTraversable
            && !topLeftTraversable
            && !topRightTraversable
            && !bottomLeftTraversable
            && !bottomRightTraversable) {

            return surroundingPoints;

        }

        if (rightPointTraversable) {

            surroundingPoints.push_back(pathAlgs::Point(point.x + 1,
                                                        point.y));

        }

        if (leftPointTraversable) {

            surroundingPoints.push_back(pathAlgs::Point(point.x - 1,
                                                        point.y));

        }

        if (topPointTraversable) {

            surroundingPoints.push_back(pathAlgs::Point(point.x,
                                                        point.y - 1));

        }

        if (bottomPointTraversable) {

            surroundingPoints.push_back(pathAlgs::Point(point.x,
                                                        point.y + 1));

        }

        if (topLeftTraversable) {

            surroundingPoints.push_back(pathAlgs::Point(point.x - 1,
                                                        point.y - 1));

        }

        if (topRightTraversable) {

            surroundingPoints.push_back(pathAlgs::Point(point.x + 1,
                                                        point.y - 1));

        }

        if (bottomLeftTraversable) {

            surroundingPoints.push_back(pathAlgs::Point(point.x - 1,
                                                        point.y + 1));

        }

        if (bottomRightTraversable) {

            surroundingPoints.push_back(pathAlgs::Point(point.x + 1,
                                                        point.y + 1));

        }

        return surroundingPoints;

    }

    inline std::optional<std::vector<pathAlgs::GridNodePtr>::const_iterator> findInGridNodeVectorByPoint(const pathAlgs::GridNodeVector& g,
                                                                                                         pathAlgs::Point p) {

        if (p.y >= g.size()) {

            return {};

        }

        if (p.x >= g[p.y].size()) {

            return {};

        }

        return g[p.y].begin() + p.x;

    }

    void calculateDistancesFromSurroundingPoints(const pathAlgs::GridNodePtr node,
                                                 std::vector<pathAlgs::Point>& surroundingPoints,
                                                 std::deque<pathAlgs::Point>& visitedPoints,
                                                 std::deque<pathAlgs::Point>& unvisitedPoints,
                                                 const pathAlgs::GridNodeVector &grid) {

        pathAlgs::Point nodePoint = node->getPoint();

        if (surroundingPoints.size() == 0) {

            if (std::find(visitedPoints.begin(),
                          visitedPoints.end(),
                          nodePoint) == visitedPoints.end()) {

                visitedPoints.push_back(nodePoint);

            }

            unvisitedPoints.pop_front();

            return;

        }

        for (pathAlgs::Point &point : surroundingPoints) {

            // skip the already visited, or to be visited nodes. Stops infinite loops.
            if (std::find(visitedPoints.begin(),
                          visitedPoints.end(),
                          point) != visitedPoints.end()
                || std::find(unvisitedPoints.begin(),
                             unvisitedPoints.end(),
                             point) != unvisitedPoints.end()) {

                continue;

            }

            auto surroundingNodeIt = findInGridNodeVectorByPoint(grid,
                                                                 point);
            if (!surroundingNodeIt.has_value())
                continue;

            auto surroundingNode = *surroundingNodeIt.value();

            if ((node->getDistance() + 1) < surroundingNode->getDistance()) {

                surroundingNode->setDistance(node->getDistance() + 1);
                surroundingNode->setPrecedingNode(node);

            }

            unvisitedPoints.push_back(point);

        }

        if (std::find(visitedPoints.begin(),
            visitedPoints.end(),
            nodePoint) == visitedPoints.end()) {

            visitedPoints.push_back(nodePoint);

        }

    }

    inline bool validateStartAndEndPoint(pathAlgs::Point start,
                                         pathAlgs::Point end,
                                         const pathAlgs::GridNodeVector& g) {

        return findInGridNodeVectorByPoint(g,
                                           start).has_value()
            && findInGridNodeVectorByPoint(g,
                                           end).has_value();

    }

    std::optional<pathAlgs::Grid::SearchResults> checkValidityBeforeSearch(const pathAlgs::GridNodeVector& v,
                                                                           pathAlgs::Point startPoint,
                                                                           pathAlgs::Point endPoint,
                                                                           std::string& errorMsg) {

        if (v.size() == 0
            || validateStartAndEndPoint(startPoint,
                                        endPoint,
                                        v) == false) {

            errorMsg = v.size() == 0 ? pathAlgs::INVALID_GRID_SIZE_ERROR_MSG
                                     : pathAlgs::INVALID_NODE_POSITION_ERROR_MSG;

            return pathAlgs::Grid::SearchResults({},
                                                 nullptr,
                                                 false,
                                                 false,
                                                 errorMsg);

        }

        return {};

    }

    inline void resetGoalNode(const pathAlgs::Point endPoint, const pathAlgs::GridNodeVector& g) {

        const pathAlgs::GridNodePtr endNode = *findInGridNodeVectorByPoint(g,
                                                                           endPoint).value();

        endNode->setPrecedingNode(nullptr);

    }

}

namespace pathAlgs {

    Grid::Grid() {}

    Grid::Grid(const TraversabilityMap & traversabilityMap)
        : m_traversabilityMap{traversabilityMap} {

        initGrid();

    }

    void Grid::initGrid() {

        m_grid.clear();
        m_grid.reserve(sizeOfGrid());

        for (size_t row = 0; row < m_traversabilityMap.size(); ++row) {
            m_grid.push_back(std::vector<GridNodePtr>());

            for (size_t column = 0; column < m_traversabilityMap[row].size(); ++column) {

                m_grid[row].push_back(std::make_unique<GridNode>(nullptr,
                                                                 Point{static_cast<int>(column),
                                                                       static_cast<int>(row)}));

            }

        }

    }

    size_t Grid::sizeOfGrid() const {

        size_t rows = m_traversabilityMap.size();
        size_t columns = m_traversabilityMap[0].size();

        return (m_traversabilityMap.size() == 0) ? 0 : (rows * columns);

    }

    void Grid::setGrid(const TraversabilityMap &traversabilityMap) {
    
        m_traversabilityMap = traversabilityMap;

        initGrid();
    
    }

    Grid::SearchResults Grid::findPathDijkstra(const Point &startPoint,
                                               const Point &endPoint) const {

        std::string errorMsg;
        auto validity = checkValidityBeforeSearch(m_grid,
                                                  startPoint,
                                                  endPoint,
                                                  errorMsg);

        if (validity.has_value()) {
            return validity.value();
        }

        if (m_grid.size() == 0
         || validateStartAndEndPoint(startPoint,
                                     endPoint,
                                     m_grid) == false) {

            errorMsg = m_grid.size() == 0 ? INVALID_GRID_SIZE_ERROR_MSG
                                          : INVALID_NODE_POSITION_ERROR_MSG;

            return  SearchResults({},
                                  nullptr,
                                  false,
                                  false,
                                  errorMsg);

        }
        resetGoalNode(endPoint,
                      m_grid);


        std::deque<Point> visitedPoints;

        std::deque<Point> unvisitedPoints;
        unvisitedPoints.push_back(startPoint);

        do {

            Point currentNodePoint = unvisitedPoints.front();
            GridNodePtr currentNode = *findInGridNodeVectorByPoint(m_grid,
                                                                   currentNodePoint).value();

            if (currentNode->getPoint() == endPoint) break;
            
            if (currentNode->getPoint() == startPoint) {

                currentNode->setDistance(currentNode->getDistanceFromSelf());

            }

            std::vector<Point> surroundingPoints =  getSurroundingPoints(currentNode,
                                                                         m_traversabilityMap);

            if (surroundingPoints.size()) {

                calculateDistancesFromSurroundingPoints(currentNode,
                                                        surroundingPoints,
                                                        visitedPoints,
                                                        unvisitedPoints,
                                                        m_grid);

            }

            unvisitedPoints.pop_front();

        } while (unvisitedPoints.size());


        const GridNodePtr endNode = *findInGridNodeVectorByPoint(m_grid,
                                                                 endPoint).value();
        if (!endNode->getPrecedingNode()) {

            return SearchResults({},
                nullptr,
                false,
                true,
                GOAL_UNREACHABLE_ERROR_MSG);

        }

        return SearchResults(visitedPoints,
                             endNode,
                             static_cast<bool>(endNode),
                             true,
                             errorMsg);

    }

    Grid::SearchResults Grid::findPathAStar(const Point &startPoint,
                                            const Point &endPoint) const {

        std::string errorMsg;
        auto validity = checkValidityBeforeSearch(m_grid,
                                                  startPoint,
                                                  endPoint,
                                                  errorMsg);

        if (validity.has_value()) {
            return validity.value();
        }
        resetGoalNode(endPoint,
                      m_grid);

        // Node - F value
        using AStarGridNodeMap = std::vector<std::pair<GridNodePtr, float>>;
        AStarGridNodeMap unvistedNodes;
        AStarGridNodeMap vistedNodes;
        std::deque<Point> traversalOrder;

        const auto firstNode = *findInGridNodeVectorByPoint(m_grid,
                                                            startPoint).value();

        firstNode->calculateAstarValues(startPoint,
                                        endPoint,
                                        m_traversabilityMap);
        unvistedNodes.push_back(std::make_pair(firstNode,
                                               firstNode->getF()));
        traversalOrder.push_back(firstNode->getPoint());

        while (!unvistedNodes.empty()) {

            const auto currentNodePointIt = std::min_element(unvistedNodes.begin(),
                                                             unvistedNodes.end(),
                                                             [&](const auto &n1, const auto &n2) {
                                                                 return n1.second < n2.second;
                                                             });
            vistedNodes.push_back(*currentNodePointIt);
            traversalOrder.push_back(currentNodePointIt->first->getPoint());

            unvistedNodes.erase(currentNodePointIt);

            const auto currentGridNode = vistedNodes.back().first;

            /// <summary>
            /// 
            /// </summary>
            /// <param name="startPoint"></param>
            /// <param name="endPoint"></param>
            /// <returns></returns>
            int brejkP = currentGridNode->getPoint().x;
            int brejkK = currentGridNode->getPoint().y;


            const auto surroundingNodes = getSurroundingPoints(currentGridNode,
                                                               m_traversabilityMap);

            for (const auto &nodePoint : surroundingNodes) {
                 const auto surroundingNode = *findInGridNodeVectorByPoint(m_grid,
                                                                           nodePoint).value();

                if (std::find_if(vistedNodes.begin(),
                                 vistedNodes.end(),
                                 [&](const auto& n) {
                                     return n.first == *findInGridNodeVectorByPoint(m_grid,
                                         nodePoint).value();
                                 }) != vistedNodes.end()) {

                    continue;

                }
                if (std::find_if(unvistedNodes.begin(),
                                 unvistedNodes.end(),
                                 [&](const auto& n) {
                                     return n.first == *findInGridNodeVectorByPoint(m_grid,
                                         nodePoint).value();
                                 }) != unvistedNodes.end()) {

                    if (surroundingNode->getPrecedingNode() != nullptr
                         && surroundingNode->getF() > currentGridNode->getF()) {

                        surroundingNode->setPrecedingNode(currentGridNode->getPrecedingNode());
                        continue;

                    }

                }

                surroundingNode->calculateAstarValues(currentGridNode->getPoint(),
                                                      endPoint,
                                                      m_traversabilityMap);

                unvistedNodes.push_back(std::make_pair(surroundingNode,
                                                       surroundingNode->getF()));

                surroundingNode->setPrecedingNode(currentGridNode);

                // found end node
                if (surroundingNode == *findInGridNodeVectorByPoint(m_grid,
                                                                    endPoint).value()) {

                    goto outsideOfWhile;

                }
                 
            }

        } outsideOfWhile: ;

        const GridNodePtr endNode = *findInGridNodeVectorByPoint(m_grid,
                                                                 endPoint).value();
        if (!endNode->getPrecedingNode()) {

            return SearchResults({},
                                 nullptr,
                                 false,
                                 true,
                                 GOAL_UNREACHABLE_ERROR_MSG);

        }

        traversalOrder.pop_front();
        traversalOrder.push_back(endPoint);
        return SearchResults(traversalOrder,
                             endNode,
                             static_cast<bool>(endNode),
                             true,
                             errorMsg);

    }

}