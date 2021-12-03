#include "pch.h"

#include "..\PathfindingAlgorithms\Grid.h"

class GridTests : public testing::Test {

protected:

    GridTests() {}

    pathAlgs::Grid grid;

    void SetUp() override {

        grid.setGrid({ { 1, 1, 1 },
                       { 0, 1, 0 },
                       { 1, 1, 0 } });

    }

};
TEST_F(GridTests, SizeOfGrid) {

    size_t sizeOfGrid = grid.sizeOfGrid();

    EXPECT_EQ(9, sizeOfGrid);

    grid.setGrid({{0, 1, 1}});

    EXPECT_NE(sizeOfGrid, grid.sizeOfGrid());

}