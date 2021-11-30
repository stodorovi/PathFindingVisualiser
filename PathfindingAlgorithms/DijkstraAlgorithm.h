#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Types.h"
#include "GridNode.h"

#include <list>

namespace pathAlgs {

    int findPathDijkstra(Grid grid,
                         Point startingPoint,
                         Point endPoint);

}

#endif // !DIJKSTRA_H
