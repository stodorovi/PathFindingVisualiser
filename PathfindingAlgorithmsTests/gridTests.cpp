#include "pch.h"

#include "..\PathfindingAlgorithms\GridNode.h"

void AssertEquals(const pathAlgs::GridNode &,
                  const pathAlgs::GridNode &);
TEST(GridNodeTests, SetProcedingNode) {

    pathAlgs::GridNode *gridNodeMain = new pathAlgs::GridNode(nullptr,
                                                              false);
    
    pathAlgs::GridNode *gridNodeTail = new pathAlgs::GridNode(gridNodeMain,
                                                              false);

    ASSERT_EQ(gridNodeTail->getPrecedingNode(),
              gridNodeMain);

    pathAlgs::GridNode *gridNodeNewMain = new pathAlgs::GridNode(nullptr,
                                                                 true);
    gridNodeTail->setPrecedingNode(gridNodeNewMain);

    ASSERT_NE(gridNodeTail->getPrecedingNode(),
              gridNodeMain);

}

TEST(GridNodeTests, CopyProcedingNode) {

    pathAlgs::GridNode *gridNodeMain = new pathAlgs::GridNode(nullptr,
                                                              false);

    pathAlgs::GridNode *gridNodeTail = new pathAlgs::GridNode(gridNodeMain,
                                                              true);

    ASSERT_NE(gridNodeTail->getPrecedingNode(),
              gridNodeMain);

    AssertEquals(*gridNodeMain,
                 *gridNodeTail->getPrecedingNode());

    pathAlgs::GridNode *gridNodeNewMain = new pathAlgs::GridNode(nullptr,
                                                                 false);

    gridNodeTail->copyPrecedingNode(gridNodeNewMain);

    ASSERT_NE(gridNodeTail->getPrecedingNode(),
              gridNodeNewMain);

    AssertEquals(*gridNodeNewMain,
                 *gridNodeTail->getPrecedingNode());

}
TEST(GridNodeTests, GridNodeListAssignmentSameMemories) {

    std::vector<pathAlgs::GridNode *> gridNodeVector = {

        new pathAlgs::GridNode()

    };

    gridNodeVector.push_back(new pathAlgs::GridNode(gridNodeVector.back(),
                                                    false,
                                                    {4,4},
                                                    10));
    gridNodeVector.push_back(new pathAlgs::GridNode(gridNodeVector.back(),
                                                    false,
                                                    {3,3},
                                                    7));
    gridNodeVector.push_back(new pathAlgs::GridNode(gridNodeVector.back(),
                                                    false,
                                                    {2,2},
                                                    8));
    gridNodeVector.push_back(new pathAlgs::GridNode(gridNodeVector.back(),
                                                    false,
                                                    {1,1},
                                                    1));


    pathAlgs::GridNode *node = gridNodeVector.back();

    for (int i = 0; i < gridNodeVector.size(); ++i) {

        ASSERT_EQ(node,
                  gridNodeVector[gridNodeVector.size() - 1 - i]);

        node = node->getPrecedingNode();

    }

}

TEST(GridNodeTests, GridNodeListCopyNotSameMemories) {
    
    std::vector<pathAlgs::GridNode *> gridNodeVector = {

        new pathAlgs::GridNode()

    };

    gridNodeVector.push_back(new pathAlgs::GridNode(gridNodeVector.back(),
                                                    false,
                                                    {4,4},
                                                    10));
    gridNodeVector.push_back(new pathAlgs::GridNode(gridNodeVector.back(),
                                                    false,
                                                    {3,3},
                                                    7));
    gridNodeVector.push_back(new pathAlgs::GridNode(gridNodeVector.back(),
                                                    false,
                                                    {2,2},
                                                    8));
    gridNodeVector.push_back(new pathAlgs::GridNode(gridNodeVector.back(),
                                                    false,
                                                    {1,1},
                                                    1));

    pathAlgs::GridNode *node = new pathAlgs::GridNode(std::move(*gridNodeVector.back()));

    for (int i = 0; i < gridNodeVector.size(); ++i) {

        ASSERT_NE(node,
                  gridNodeVector[gridNodeVector.size() - 1 - i]);

        node = node->getPrecedingNode();

    }

}

TEST(GridNodeTests, GridNodeListsSameValues) {

    std::vector<pathAlgs::GridNode *> gridNodeVector = {

        new pathAlgs::GridNode()

    };

    gridNodeVector.push_back(new pathAlgs::GridNode(gridNodeVector.back(),
                                                    false,
                                                    {4,4},
                                                    10));
    gridNodeVector.push_back(new pathAlgs::GridNode(gridNodeVector.back(),
                                                    false,
                                                    {3,3},
                                                     7));
    gridNodeVector.push_back(new pathAlgs::GridNode(gridNodeVector.back(),
                                                    false,
                                                    {2,2},
                                                    8));
    gridNodeVector.push_back(new pathAlgs::GridNode(gridNodeVector.back(),
                                                    false,
                                                    {1,1},
                                                    1));


    pathAlgs::GridNode *node = gridNodeVector.back();

    // same values on asignment
    for (int i = 0; i < gridNodeVector.size(); ++i) {

        AssertEquals(*node, *gridNodeVector[gridNodeVector.size() - 1 - i]);

        node = node->getPrecedingNode();

    }
    
    // same values on copy
    node = new pathAlgs::GridNode(*gridNodeVector.back());

    ASSERT_NE(node,
              gridNodeVector.back());

    for (int i = 0; i < gridNodeVector.size(); ++i) {

        AssertEquals(*node, *gridNodeVector[gridNodeVector.size() - 1 - i]);

        node = node->getPrecedingNode();

    }

}

/**
 * @brief Asserts that the values of the node and the values of the preceding nodes are the same
*/
static void AssertEquals(const pathAlgs::GridNode &actual,
                         const pathAlgs::GridNode &expected) {

    bool anyNull = &actual == nullptr
                || &expected == nullptr;

    bool notEqual = &expected
                 != &actual;

    ASSERT_FALSE(anyNull
              && notEqual);

    bool bothNullptr = &expected == nullptr
                    && &actual == nullptr;
    if (bothNullptr) return;

    AssertEquals(*actual.getPrecedingNode(),
                 *expected.getPrecedingNode());

    ASSERT_EQ(actual.getPoint(),
              expected.getPoint());
    ASSERT_EQ(actual.getDistance(),
              expected.getDistance());

}