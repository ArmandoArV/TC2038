from Graph import Graph
from read_file import read_file

def main():
    start, matrix = read_file("input2.txt")
    graph = Graph(len(matrix), matrix)
    solution = graph.solution(start)

    abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

    print("Forma de cablear las colonias con fibra:", end=" (")

    for node in solution:
        print(abc[node], end=", ")

    print(")")


if __name__ == "__main__":
    main()
