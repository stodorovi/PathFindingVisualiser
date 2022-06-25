#ifndef GRID_H
#define GRID_H

#include <cmath>
#include <deque>
#include <string>
#include <vector>

#include "GridConstants.h"
#include "GridNode.h"
#include "Point.h"

namespace pathAlgs {

    class Grid {

    private:
        
        TraversabilityMap m_traversabilityMap;

        GridNodeVector m_grid;

        void initGrid();
    
    public:

        struct SearchResults {

            const std::deque<Point> traversalOrder;
            const GridNodePtr goalNode;
            const bool foundGoal = false;
            const bool isSearchValid = false;
            std::string errorMsg;

            SearchResults() {}

            SearchResults(const SearchResults &st)
                : SearchResults(st.traversalOrder,
                                st.goalNode,
                                st.foundGoal,
                                st.isSearchValid,
                                st.errorMsg)
            {}

            SearchResults(const std::deque<Point> traversalOrder,
                          const GridNodePtr goalNode,
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

        Grid(const TraversabilityMap & traversabilityMap);

        size_t sizeOfGrid() const;
        void setGrid(const TraversabilityMap &traversabilityMap);

        SearchResults findPathDijkstra(const Point &startPoint,
                                       const Point &endPoint) const;

        SearchResults findPathAStar(const Point &startPoint,
                                    const Point &endPoint) const;

    };

}

#endif // !GRID_H
