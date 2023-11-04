def read_file(filename):
    with open(filename, "r") as file:
        start = int(file.readline())
        matrix = []
        for line in file:
            matrix.append([int(x) for x in line.split(",")])
        return start, matrix
