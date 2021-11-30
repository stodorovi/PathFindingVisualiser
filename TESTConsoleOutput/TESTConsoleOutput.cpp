// TESTConsoleOutput.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"../PathfindingAlgorithms/DijkstraAlgorithm.h"

int main()
{
    pathAlgs::GridNode *n4 = new pathAlgs::GridNode(nullptr, {4,4}, 4);
    pathAlgs::GridNode *n3 = new pathAlgs::GridNode(n4, {3,3}, 3);
    pathAlgs::GridNode *n2 = new pathAlgs::GridNode(n3, {2,2}, 2);
    pathAlgs::GridNode *n1 = new pathAlgs::GridNode(n2, {1,1}, 1);
    pathAlgs::GridNode n0(n1);

    pathAlgs::GridNode *node =& n0;

    pathAlgs::GridNode node21(*node);
    pathAlgs::GridNode *node2 = &node21;

    while (node != nullptr) {
        std::cout << "MEMORIJA: " << node << "\t IDUCA: " << node->getPrecedingNode() << "\t - DISTANCA: " << node->getDistance() << "\n";
        node = node->getPrecedingNode();
    }

    std::cout << "\nIDUCA\n";

    while (node2 != nullptr) {
        std::cout << "MEMORIJA: " << node2 << "\t IDUCA: " << node2->getPrecedingNode() << "\t - DISTANCA: " << node2->getDistance() << "\n";
        node2 = node2->getPrecedingNode();
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
