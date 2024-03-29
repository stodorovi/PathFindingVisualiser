#include "pch.h"

#include "..\PathfindingAlgorithms\Grid.h"

class AlgorithmsTest : public testing::Test {

protected:

    pathAlgs::Grid grid;

    AlgorithmsTest() {};

    void SetUp() {

        pathAlgs::TraversabilityMap map = {

            { 1, 0, 1 },
            { 1, 1, 1 },
            { 1, 0, 1 }

        };

        grid.setGrid(map);

    }

};

TEST_F(AlgorithmsTest, Dijkstra) {

    // Path found
    pathAlgs::Point startPoint{0, 0};
    pathAlgs::Point endPoint{2, 0};

    pathAlgs::Grid::SearchResults searchResults = grid.findPathDijkstra(startPoint,
                                                                        endPoint);

    ASSERT_TRUE(searchResults.isSearchValid);
    ASSERT_TRUE(searchResults.foundGoal);
    ASSERT_EQ(endPoint,
              searchResults.goalNode->getPoint());

    // Goal out of bounds
    pathAlgs::TraversabilityMap newMap{

        {1, 1, 1},
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}

    };

    grid.setGrid(newMap);

    endPoint = {10, 2};

    pathAlgs::Grid::SearchResults goalNotFound = grid.findPathDijkstra(startPoint,
                                                                       endPoint);
    ASSERT_FALSE(goalNotFound.isSearchValid);

    // Goal not reachable
    newMap = {

        {1, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 1, 0}

    };

    grid.setGrid(newMap);

    endPoint = {3, 2};

    pathAlgs::Grid::SearchResults goalNotReachable = grid.findPathDijkstra(startPoint,
                                                                           endPoint);

    ASSERT_TRUE(goalNotReachable.isSearchValid);
    ASSERT_FALSE(goalNotReachable.foundGoal);

}

TEST_F(AlgorithmsTest, A_star) {

    pathAlgs::TraversabilityMap map {

        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 0, 0, 1, 1},
        {1, 1, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1},

    };

    pathAlgs::Point startPoint{ 1, 2 };
    pathAlgs::Point endPoint{ 6, 0 };

    grid.setGrid(map);

    pathAlgs::Grid::SearchResults searchResults = grid.findPathAStar(startPoint,
                                                                     endPoint);

    ASSERT_TRUE(searchResults.isSearchValid);
    ASSERT_TRUE(searchResults.foundGoal);

    pathAlgs::Grid::SearchResults dijkstraSearchResults = grid.findPathDijkstra(startPoint,
                                                                                endPoint);

    ASSERT_TRUE(searchResults.goalNode->getDepth() > dijkstraSearchResults.goalNode->getDepth());

}