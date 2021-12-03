#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <list>
#include <map>
#include <deque>

#include "GridNode.h"
#include "GridUtil.h"
#include "Point.h"

namespace pathAlgs {

    const GridNode findPathDijkstra(GridNode &node,
                                    Grid grid,
                                    Point startingPoint,
                                    Point endPoint);

}

#endif // !DIJKSTRA_H
