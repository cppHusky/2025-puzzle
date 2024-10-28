#!/bin/python3
def read_matrix(file_path):
    matrix = []
    with open(file_path, 'r') as f:
        for line in f:
            matrix.append([int(x) for x in line.strip()])
    return matrix

def bitwise_or_matrix(mat1, mat2, mat3):
    rows = len(mat1)
    cols = len(mat1[0])
    result = [[0] * cols for _ in range(rows)]
    
    for i in range(rows):
        for j in range(cols):
            result[i][j] = mat1[i][j] | mat2[i][j] | mat3[i][j]
    
    return result

def print_matrix(matrix):
    for row in matrix:
        print("".join(map(str, row)))

# Read matrices from files
map0 = read_matrix('./map0.txt')
map1 = read_matrix('./map1.txt')
map2 = read_matrix('./map2.txt')

# Perform bitwise OR on the matrices
result_matrix = bitwise_or_matrix(map0, map1, map2)

# Print the result
print_matrix(result_matrix)
