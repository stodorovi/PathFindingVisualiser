#ifndef GRIDNODE_H
#define GRIDNODE_H

#include "Types.h"

namespace pathAlgs {

    /**
    Grid node used for calculating distance.
    */
    class GridNode {

    private:

        /**
         * @brief the node preceding this one.
         */
        GridNode *m_precedingNode;

        /** 
        * @brief This nodes point on the grid.
        */
        Point m_point;

        /**
         * @brief Distance from the starting node.
        */
        int m_distance;

    public:

        /**
         * @brief Empty constructor.
        */
        GridNode();

        /**
         * @brief Constructor
         * 
         * @param precedingNode - the node that is closest to this one.
         * @param point - the point of this node in the grid.
         * @param distanceFromPrecedingNode - distance from the preceding node.
        */
        GridNode(GridNode *precedingNode,
                 bool copyContent,
                 Point point = {-INT_MAX,
                                -INT_MAX},
                 int distanceFromPrecedingNode = INT_MAX);

        /**
         * @brief Copy constructor.
         * Copies every node down the line into a new object.
         * 
         * @param node - the node to copy contents from.
        */
        GridNode(const GridNode &node);

        /**
         * @brief Move constructor.
         * Moves existing node to self.
         * 
         * @param node - the node to move to self.
        */
        GridNode(GridNode &&node) noexcept;

        /**
         * @brief Copy assignment operator.
         * Copies every preceding node
         * 
         * @param node - the node to copy contents from.
        */
        void operator=(const GridNode &node);

        /**
         * @brief Move asignment operator.
         */
        GridNode& operator=(GridNode &&node) noexcept;

        ~GridNode();

        /**
         * @brief precedingNode getter
         * @return the procedingNode
        */
        GridNode* getPrecedingNode() const;

        /**
         * @brief precedingNode setter - sets the existing pointer.
         * @param the node to set.
        */
        void setPrecedingNode(GridNode *node);

        /**
         * @brief Copies the given node and its preceding nodes and their contents.
         * @param the node to copy.
        */
        void copyPrecedingNode(const GridNode *node);

        /**
         * @brief point getter.
         * @return the point.
        */
        Point getPoint() const;

        /**
         * @brief point setter.
         * @param the point to set.
        */
        void setPoint(Point point);

        /**
         * @brief distance getter.
         * @return the distance to get.
        */
        int getDistance() const;

        /**
         * @brief distance setter.
         * @param the distance to set.
        */
        void setDistance(int distance);

        /**
         * @brief The distance from self. Always 0.
         * @return the distance from self.
        */
        int getDistanceFromSelf() const;

    };

}

#endif // !GRIDNODE_H
