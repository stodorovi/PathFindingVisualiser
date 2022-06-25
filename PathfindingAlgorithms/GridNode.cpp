#include "GridNode.h"
#include "Grid.h"

namespace {
    inline void recalculateF(pathAlgs::GridNode& n) {

        n.setF(n.getG() + n.getH());

    }

    inline float hypotenuse(const pathAlgs::Point p1,
                            const pathAlgs::Point p2) {

        float a = std::abs(p1.x - p2.x);
        float b = std::abs(p1.y - p2.y);

        return std::sqrt(std::pow(a, 2) + std::pow(b, 2));

    }
}

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
        : m_parentNode{nullptr},
          m_point{point},
          m_distance{distanceFromPrecedingNode},
          m_g{0},
          m_h{0},
          m_f{0} {

        if (precedingNode) {

            m_parentNode = std::make_shared<GridNode>(precedingNode->getPrecedingNode().get());
            
        }

    }

    void GridNode::operator=(const GridNode &node) {

        m_point = node.getPoint();
        m_distance = node.getDistance();

        if (node.getPrecedingNode()) {

            setPrecedingNodeCopy(node.getPrecedingNode());

        }

    }

    std::shared_ptr<GridNode> GridNode::getPrecedingNode() const {

        if (!m_parentNode) {

            return nullptr;

        }

        return m_parentNode;

    }

    GridNode *GridNode::getPrecedingNodeRaw() const {

        return m_parentNode.get();

    }

    void GridNode::setPrecedingNode(std::shared_ptr<GridNode> node) {

        if (node == nullptr) {

            m_parentNode = nullptr;

            return;

        }

        if (!m_parentNode) {

            m_parentNode = node;

        }

    }

    void GridNode::setPrecedingNodeCopy(std::shared_ptr<GridNode> node) {

        if (node == nullptr) {

            m_parentNode = nullptr;

            return;

        }

        if (!m_parentNode) {
            
            m_parentNode = std::make_shared<GridNode>();
            *m_parentNode = *node;

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

    size_t GridNode::getDepth() const {

        size_t depth = 0;

        GridNode *nodePtr = m_parentNode.get();
        while (nodePtr != nullptr) {

            depth++;
            nodePtr = nodePtr->getPrecedingNodeRaw();

        }

        return depth;

    }

    float GridNode::getG() const {
        return m_g;
    }
    void GridNode::setG(float g) {

        m_g = g < 0 ? 0 : g;
        recalculateF(*this);

    }

    float GridNode::getH() const {
        return m_h;
    }
    void GridNode::setH(float h) {

        m_h = h < 0 ? 0 : h;
        recalculateF(*this);

    }

    float GridNode::getF() const {
        return m_f;
    }
    void GridNode::setF(float f) {
        m_f = f < 0 ? 0 : f;
    }

    void GridNode::calculateAstarValues(const Point &startPoint,
                                        const Point &endPoint,
                                        const TraversabilityMap &t) {

        m_g = t[m_point.y][m_point.x] ? hypotenuse(m_point, startPoint) : INT_MAX;
        m_h = t[m_point.y][m_point.x] ? hypotenuse(m_point, endPoint)   : INT_MAX;
        m_f = m_g + m_h;

    }

    bool GridNode::operator==(GridNode& other) {
        
        return this->m_distance == other.getDistance()
            && this->m_parentNode == other.getPrecedingNode()
            && this->m_point == other.getPoint();

    }

}