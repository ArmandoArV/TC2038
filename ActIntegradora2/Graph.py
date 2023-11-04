from collections import defaultdict
from dijkstra import dijkstra
from solution import solution


class Graph:
    def __init__(self, vertex, matrix):
        self.path = []
        self.V = vertex
        self.adjList = defaultdict(list)

        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                if matrix[i][j] != 0:
                    self.adjList[i].append([j, matrix[i][j]])

    solution = solution
    dijkstra = dijkstra
