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

    };

}

#endif // !POINT_H