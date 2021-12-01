#ifndef ALIASES_H
#define ALIASES_H

#include<vector>
#include<list>

namespace pathAlgs {

    /**
     * @brief Grid representing walkable / unwalkable nodes. @n
     * - 1 / true represents a walkable node.
     * - 0 / false represents unwalkable node.
    */
    using Grid = std::vector<std::vector<bool>>;

    /** Point in two dimensional grid. */
    struct Point {

        int x;
        int y;

        Point() : x{0}, y{0}
        {}

        Point(int x, int y) : x{x}, y{y}
        {}

        bool operator==(Point other) const {

            return x == other.x
                && y == other.y;

        }

    };

}

#endif // !ALIASES_H