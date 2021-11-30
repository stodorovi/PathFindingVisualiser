// TESTOutput.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <assert.h>
#include"..\PathfindingAlgorithms\DijkstraAlgorithm.h"

int main()
{
    std::vector<pathAlgs::GridNode *> gridNodeVector = {

    new pathAlgs::GridNode()

    };

    gridNodeVector.push_back(new pathAlgs::GridNode(gridNodeVector.back(), false, {4,4}, 10));
    gridNodeVector.push_back(new pathAlgs::GridNode(gridNodeVector.back(), false, {3,3}, 7));
    gridNodeVector.push_back(new pathAlgs::GridNode(gridNodeVector.back(), false, {2,2}, 8));
    gridNodeVector.push_back(new pathAlgs::GridNode(gridNodeVector.back(), false, {1,1}, 1));

    pathAlgs::GridNode gridRV(std::move(*gridNodeVector.back()));
    pathAlgs::GridNode *node = new pathAlgs::GridNode(gridRV);

    for (int i = 0; i < gridNodeVector.size(); ++i) {

        assert(node != gridNodeVector[gridNodeVector.size() - 1 - i]);

        node = node->getPrecedingNode();

    }

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
