#ifndef POINT_H
#define POINT_H

namespace pathAlgs {

    /** Point in two dimensional grid. */
    class Point {

    public:

        int x;
        int y;

        Point()
            : x{-1},
              y{-1}
        {}

        Point(int x,
              int y)
            : x{x},
              y{y}
        {}

        bool operator==(const Point &other) const {

            return x == other.x
                && y == other.y;

        }

        bool operator!=(const Point &other) const {

            return !(*this == other);

        }

        Point(const Point &other)
            : Point(other.x,
                    other.y)
        {}

        /**
        *
        * @brief Distance from another point. Takes in consideration 8-way movement.
        * 
        */
        int distanceFrom(const Point& other) const {

            int xDistance = std::abs(this->x - other.x);
            int yDistance = std::abs(this->y - other.y);

            int xDistanceGreater = static_cast<int>(xDistance > yDistance);

            return (xDistanceGreater * xDistance)
                 + (xDistanceGreater * yDistance);

        }

    };

}

#endif // !POINT_H