#ifndef GRID_H
#define GRID_H

#include <deque>
#include <string>
#include <vector>

#include "GridConstants.h"
#include "GridNode.h"
#include "Point.h"

namespace pathAlgs {

    using GridMap = std::vector<std::vector<bool>>;

    class Grid {

    private:
        
        /**
         * @brief Map of traversable / untraversable points.
         * Used for creating the main grid.
        */
        GridMap m_gridMap;

        /** @brief Grid used for pathfinding. */
        std::vector<std::unique_ptr<GridNode>> m_grid;

        /** @brief Initialises the grid based on the set GridMap. */
        void initGrid();

        /**
         * @brief Validates that the start & the end points are on the grid.
         * 
         * @param startPoint
         * @param endPoint
         * 
         * @return 1 if valid, 0 if not.
        */
        bool validateStartAndEndPoint(Point startPoint,
                                      Point endPoint) const;

        /**
         * @brief Calculates the shortest distance from the start node
         * to the surrounding nodes of the passed node.
         * 
         * @param node
         * @param surroundingPoints
         * @param visitedPoints 
         * @param unvisitedPoints 
        */
        void calculateDistancesFromSurroundingPoints(const GridNode &node,
                                                     std::vector<Point> &surroundingPoints,
                                                     std::deque<Point> &visitedPoints,
                                                     std::deque<Point> &unvisitedPoints) const;

        /**
         * @brief Gets the traversable surrounding points.
         * 
         * @param point
         * 
         * @return std::vector<Point>
        */
        std::vector<Point> getSurroundingPoints(const Point &point) const;
    
    public:

        /** @brief Struct containing pathfinging search results. */
        struct SearchResults {

            const std::deque<Point> traversalOrder;

            const std::unique_ptr<GridNode> goalNode;

            const bool foundGoal;

            const bool isSearchValid;

            std::string errorMsg;

            /**
             * @brief Copy constructor.
             * 
             * @param st SearchResult to copy from.
            */
            SearchResults(const SearchResults &st)
                : SearchResults(st.traversalOrder,
                                st.goalNode.get(),
                                st.foundGoal,
                                st.isSearchValid,
                                st.errorMsg)
            {}

            /**
             * @brief Constructor.
             * 
             * @param traversalOrder 
             * @param goalNode 
             * @param foundGoal 
             * @param isSearchValid 
            */
            SearchResults(const std::deque<Point> traversalOrder,
                          const GridNode * const goalNode,
                          bool foundGoal,
                          bool isSearchValid,
                          std::string errorMsg = "")
                : traversalOrder{traversalOrder},
                  goalNode{std::make_unique<GridNode>(*goalNode)},
                  foundGoal{foundGoal},
                  isSearchValid{isSearchValid},
                  errorMsg{errorMsg}
            {}

        };

        Grid();

        /**
         * @brief Constructor with grid map.
         * Initialises the internal grid based on the map.
         * 
         * @param gridMap The map of traversable & untraversable points.
        */
        Grid(const GridMap &gridMap);

        /**
         * @brief Grid size.
         * 
         * @return size_t
        */
        size_t sizeOfGrid() const;

        /**
         * @brief Find a node in the internal grid by its point.
         * 
         * @param point
         * 
         * @return Index of the node in the grid,
         * -1 if not found.
        */
        size_t findGridNodeIndexByPoint(Point point) const;

        /**
         * @brief Grid setter.
         * 
         * @param gridMap The map of traversable & untraversable points
         * to use to set the new grid.
        */
        void setGrid(const GridMap &gridMap);

        /**
         * @brief Find a path int the grid between the start & the end points.
         * Uses Dijkstra's algorithm.
         * 
         * @param startPoint 
         * @param endPoint 
         * 
         * @return SearchResults
        */
        SearchResults findPathDijkstra(Point startPoint,
                                       Point endPoint) const;

    };

}

#endif // !GRID_H
