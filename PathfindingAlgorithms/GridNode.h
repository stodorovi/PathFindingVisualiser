#ifndef GRIDNODE_H
#define GRIDNODE_H

#include <memory>
#include <vector>

#include "Point.h"
#include "GridConstants.h"

namespace pathAlgs {

    class GridNode {

    private:

        std::shared_ptr<GridNode> m_parentNode;
        Point m_point;
        int m_distance;

        float m_g;
        float m_h;
        float m_f;

    public:

        GridNode();

        GridNode(GridNode *precedingNode,
                 Point point = Point{-INT_MAX,
                                     -INT_MAX},
                 int distanceFromPrecedingNode = INT_MAX);

        GridNode(const GridNode &node);

        void operator=(const GridNode &node);

        std::shared_ptr<GridNode> getPrecedingNode() const;
        void setPrecedingNode(std::shared_ptr<GridNode> node);

        GridNode* getPrecedingNodeRaw() const;

        void setPrecedingNodeCopy(std::shared_ptr<GridNode> node);

        Point getPoint() const;
        void setPoint(Point point);

        int getDistance() const;
        void setDistance(int distance);

        int getDistanceFromSelf() const;

        size_t getDepth() const;

        float getG() const;
        void setG(float g);

        float getH() const;
        void setH(float h);

        float getF() const;
        void setF(float f);

        void calculateAstarValues(const Point &startPoint,
                                  const Point &endPoint,
                                  const TraversabilityMap &t);

        bool operator==(GridNode& other);

    };

}

#endif // !GRIDNODE_H
