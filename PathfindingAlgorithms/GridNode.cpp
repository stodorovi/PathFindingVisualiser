#include "GridNode.h"

namespace pathAlgs {

    GridNode::GridNode() : GridNode(nullptr,
                                    false) {
    }

    GridNode::GridNode(const GridNode& node)
        :GridNode(nullptr,
                  false) {

        *this = node;

    }

    GridNode::GridNode(GridNode &&node) noexcept
        : m_precedingNode{nullptr} {

        *this = std::move(node);

    }

    GridNode::GridNode(GridNode *precedingNode,
                       bool copyContent,
                       Point point,
                       int distanceFromPrecedingNode)
        : m_precedingNode{nullptr},
          m_point{point},
          m_distance{distanceFromPrecedingNode} {

        if (precedingNode) {

            copyContent ? copyPrecedingNode(precedingNode) : setPrecedingNode(precedingNode);

        }

    }

    void GridNode::operator=(const GridNode &node) {
        
        if (m_precedingNode) {

            delete m_precedingNode;

        }

        setPrecedingNode(node.getPrecedingNode());
        m_point = node.getPoint();
        m_distance = node.getDistance();

    }

    GridNode& GridNode::operator=(GridNode &&node) noexcept {

        if (m_precedingNode) {

            delete m_precedingNode;

        }

        copyPrecedingNode(&node);
        m_point = node.getPoint();
        m_distance = node.getDistance();

        delete node.m_precedingNode;

        return *this;

    }

    GridNode::~GridNode() {

        if (m_precedingNode) {

            delete m_precedingNode;
            m_precedingNode = nullptr;

        }

    }

    GridNode* GridNode::getPrecedingNode() const {

        return m_precedingNode;

    }

    void GridNode::setPrecedingNode(GridNode *node) {

        if (m_precedingNode) {

            delete m_precedingNode;

        }

        m_precedingNode = node;

    }

    void GridNode::copyPrecedingNode(const GridNode *node) {

        if (node) {

            if (m_precedingNode) {

                delete m_precedingNode;

            }

            m_precedingNode = new GridNode();
            m_precedingNode->setDistance(node->m_distance);
            m_precedingNode->setPoint(node->m_point);
            
            GridNode *thisNodeInLine = m_precedingNode;
            GridNode *otherNodeInLine = node->getPrecedingNode();

            while (otherNodeInLine && thisNodeInLine) {

                thisNodeInLine->copyPrecedingNode(otherNodeInLine);
                otherNodeInLine = otherNodeInLine->getPrecedingNode();
                thisNodeInLine = thisNodeInLine->getPrecedingNode();

            }

        } else {

            if (m_precedingNode) {

                delete m_precedingNode;

            }

            m_precedingNode = nullptr;

        }

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

}