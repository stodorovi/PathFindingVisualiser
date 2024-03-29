#ifndef POINT_H
#define POINT_H

namespace pathAlgs {

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

        bool operator>(const Point& other) const {

            return x > other.x
                && y > other.y;

        }

        bool operator<(const Point& other) const {

            return x < other.x
                && y < other.y;

        }

        Point(const Point &other)
            : Point(other.x,
                    other.y)
        {}

        inline int distanceFrom(const Point& other) const {

            int xDistance = std::abs(this->x - other.x);
            int yDistance = std::abs(this->y - other.y);

            return xDistance > yDistance ? xDistance
                                         : yDistance;

        }

    };

}

#endif // !POINT_H