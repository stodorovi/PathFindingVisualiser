#include "pch.h"

#include "..\PathfindingAlgorithms\GridNode.h"

using namespace pathAlgs;

void AssertEquals(GridNode &expected, GridNode &actual);
void AssertNotEquals(GridNode &expected, GridNode &actual);

TEST(GridNodeTests, EqualValues) {

    std::unique_ptr<pathAlgs::GridNode> gridNodeMain = std::make_unique<pathAlgs::GridNode>(nullptr);
    std::unique_ptr<pathAlgs::GridNode> gridNode1 = std::make_unique<pathAlgs::GridNode>(gridNodeMain.get());
    std::unique_ptr<pathAlgs::GridNode> gridNode2 = std::make_unique<pathAlgs::GridNode>(gridNode1.get());
    std::unique_ptr<pathAlgs::GridNode> gridNodeTail = std::make_unique<pathAlgs::GridNode>(gridNode2.get());

    std::unique_ptr<pathAlgs::GridNode> gridNode = std::make_unique<pathAlgs::GridNode>(*gridNodeTail);

    AssertEquals(*gridNode, *gridNodeTail);

    gridNode->setDistance(10);
    AssertNotEquals(*gridNode, *gridNodeTail);

}

TEST(GridNodeTests, EqualDepth) {

     std::unique_ptr<pathAlgs::GridNode> gridNodeMain = std::make_unique<pathAlgs::GridNode>(nullptr);
     std::unique_ptr<pathAlgs::GridNode> gridNode1 = std::make_unique<pathAlgs::GridNode>(gridNodeMain.get());
     std::unique_ptr<pathAlgs::GridNode> gridNode2 = std::make_unique<pathAlgs::GridNode>(gridNode1.get());
     std::unique_ptr<pathAlgs::GridNode> gridNode3 = std::make_unique<pathAlgs::GridNode>(gridNode2.get());
   
     std::unique_ptr<pathAlgs::GridNode> gridNodeTail = std::make_unique<pathAlgs::GridNode>(gridNode3.get());
   
     ASSERT_EQ(4, gridNodeTail->getDepth());

     std::unique_ptr<GridNode> gridNodeShorter = std::make_unique<GridNode>(*gridNodeTail);

     GridNode *node = gridNodeShorter->getPrecedingNodeRaw()->getPrecedingNodeRaw();
     node->setPrecedingNode(nullptr);

     ASSERT_NE(gridNodeTail->getDepth(), gridNodeShorter->getDepth());

}

void AssertEquals(GridNode &expected, GridNode &actual) {

    ASSERT_TRUE(expected.getDepth() == actual.getDepth());

    GridNode *expectedPtr = &expected;
    GridNode *actualPtr = &actual;

    while (expectedPtr != nullptr) {

        ASSERT_EQ(expected.getPoint(), actual.getPoint());
        ASSERT_EQ(expected.getDistance(), actual.getDistance());

        expectedPtr = expectedPtr->getPrecedingNodeRaw();
        actualPtr = actualPtr->getPrecedingNodeRaw();

    }

}

void AssertNotEquals(GridNode &expected, GridNode &actual) {

    ASSERT_TRUE(expected.getDepth() == actual.getDepth());

    GridNode *expectedPtr = &expected;
    GridNode *actualPtr = &actual;

    bool oneValueDifferent = true;

    while (expectedPtr != nullptr) {

        oneValueDifferent |= (expectedPtr->getPoint() == actualPtr->getPoint())
                          || (expectedPtr->getDistance() == actualPtr->getDistance());


        expectedPtr = expectedPtr->getPrecedingNodeRaw();
        actualPtr = actualPtr->getPrecedingNodeRaw();

    }

    ASSERT_TRUE(oneValueDifferent);

}