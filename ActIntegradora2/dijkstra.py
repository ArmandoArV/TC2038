import heapq


def dijkstra(self, source):
    dist = [float("inf")] * self.V
    seen = set()
    heap = []

    print("Source:", source)  # Debug print

    dist[source] = 0

    heapq.heappush(heap, (source, dist[source]))

    while heap:
        node, weight = heapq.heappop(heap)
        seen.add(node)

        for conn, w in self.adjList[node]:
            if conn not in seen:
                d = weight + w
                if d < dist[conn]:
                    dist[conn] = d
                    heapq.heappush(heap, (conn, d))

    print("Dist:", dist)  # Debug print
    return dist
