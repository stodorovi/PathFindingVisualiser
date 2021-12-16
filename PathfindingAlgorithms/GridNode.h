#ifndef GRIDNODE_H
#define GRIDNODE_H

#include <memory>
#include <vector>

#include "Point.h"

namespace pathAlgs {

    /**
    Grid node used for calculating distance.
    */
    class GridNode {

    private:

        /** @brief The node preceding this one. */
        std::shared_ptr<GridNode> m_precedingNode;

        /** @brief This node's point on the grid. */
        Point m_point;

        /** @brief Distance from the starting node. */
        int m_distance;

    public:

        GridNode();

        /**
         * @brief Constructor
         * 
         * @param precedingNode - closest connected node to the start node.
         * @param point - the point of this node in the grid.
         * @param distanceFromPrecedingNode - distance from the preceding node.
        */
        GridNode(GridNode *precedingNode,
                 Point point = Point{-INT_MAX,
                                     -INT_MAX},
                 int distanceFromPrecedingNode = INT_MAX);

        /**
         * @brief Copy constructor.
         * Copies the values of the given node.
         * 
         * @param node - the node to copy contents from.
        */
        GridNode(const GridNode &node);

        /**
         * @brief Copy assignment operator.
         * Copies the values of the given node.
         * 
         * @param node - the node to copy contents from.
        */
        void operator=(const GridNode &node);

        /**
         * @brief the precedingNode getter
         * 
         * @return the procedingNode
        */
        std::shared_ptr<GridNode> getPrecedingNode() const;

        GridNode* getPrecedingNodeRaw() const;

        /**
         * @brief preceeding node setter.
         * 
         * @param the node to set
        */
        void setPrecedingNode(std::shared_ptr<GridNode> node);

        /**
        * @brief preceeding node setter. Copies the given object.
        *
        * @param the node to set
        */
        void setPrecedingNodeCopy(std::shared_ptr<GridNode> node);

        /**
         * @brief point getter.
         * 
         * @return the point.
        */
        Point getPoint() const;

        /**
         * @brief point setter.
         * 
         * @param the point to set.
        */
        void setPoint(Point point);

        /**
         * @brief distance getter.
         * 
         * @return the distance to get.
        */
        int getDistance() const;

        /**
         * @brief distance setter.
         * 
         * @param the distance to set.
        */
        void setDistance(int distance);

        /**
         * @brief The distance from self. Always 0.
         * 
         * @return the distance from self.
        */
        int getDistanceFromSelf() const;

        /**
         * @brief The number of preceding nodes.
         * 
         * @return the depth of the node.
        */
        size_t getDepth() const;

    };

}

#endif // !GRIDNODE_H
