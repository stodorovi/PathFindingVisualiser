#include "GridNode.h"

namespace pathAlgs {

    GridNode::GridNode()
        : GridNode(nullptr)
    {}

    GridNode::GridNode(const GridNode& node)
        : GridNode(nullptr) {

        if (&node != nullptr) {

            *this = node;

        }

    }

    GridNode::GridNode(GridNode *precedingNode,
                       Point point,
                       int distanceFromPrecedingNode)
        : m_precedingNode{nullptr},
          m_point{point},
          m_distance{distanceFromPrecedingNode} {

        if (precedingNode) {

            m_precedingNode = std::make_unique<GridNode>(precedingNode->getPrecedingNode().get());
            
        }

    }

    void GridNode::operator=(const GridNode &node) {

        m_point = node.getPoint();
        m_distance = node.getDistance();
        setPrecedingNode(node.getPrecedingNode());

    }

    std::unique_ptr<GridNode> GridNode::getPrecedingNode() const {

        if (!m_precedingNode) {

            return nullptr;

        }

        return std::make_unique<GridNode>(*m_precedingNode);

    }

    GridNode *GridNode::getPrecedingNodeRaw() const {

        return m_precedingNode.get();

    }

    void GridNode::setPrecedingNode(const std::unique_ptr<GridNode> &node) {

        if (node == nullptr) {

            m_precedingNode.reset();

            return;

        }

        if (!m_precedingNode) {

            m_precedingNode.reset(new GridNode());
            *m_precedingNode = *node;

        }

        *m_precedingNode = *node;

    }

    Point GridNode::getPoint() const {

        return m_point;

    }

    void GridNode::setPoint(Point point) {

        m_point = point;

    }

    int GridNode::getDistance() const {

        return m_distance;

    }

    void GridNode::setDistance(int distance) {

        m_distance = distance;

    }

    int GridNode::getDistanceFromSelf() const {

        return 0;

    }

    size_t GridNode::getDepth() const {

        size_t depth = 0;

        GridNode *nodePtr = m_precedingNode.get();
        while (nodePtr != nullptr) {

            depth++;
            nodePtr = nodePtr->getPrecedingNodeRaw();

        }

        return depth;

    }

}