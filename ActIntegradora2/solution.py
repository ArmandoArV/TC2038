def solution(self, start):
    self.path.append(start)

    for _ in range(self.V - 1):
        dist = self.dijkstra(self.path[-1])  # Debug print
        print("Dist:", dist)

        smallest = float("inf")
        next_node = None

        for j in range(self.V):
            if dist[j] < smallest and j not in self.path:
                smallest = dist[j]
                next_node = j

        print("Next node:", next_node)

        if next_node is not None:
            self.path.append(next_node)
        else:
            break

    return self.path
