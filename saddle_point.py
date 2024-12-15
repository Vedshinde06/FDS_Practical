def find_saddle_point(matrix):
    saddle_points = []

    for i in range(len(matrix)):
        row_min = min(matrix[i])
        col_idx = matrix[i].index(row_min)

        # Check if the row minimum is also the column maximum
        col_values = [matrix[row][col_idx] for row in range(len(matrix))]
        if row_min == max(col_values):
            saddle_points.append((i, col_idx, row_min))

    return saddle_points

# Accepting matrix from user
def input_matrix():
    rows = int(input("Enter the number of rows in the matrix: "))
    cols = int(input("Enter the number of columns in the matrix: "))

    print("Enter the elements row by row:")
    matrix = []
    for i in range(rows):
        row = list(map(int, input(f"Row {i + 1}: ").split()))
        if len(row) != cols:
            print(f"Error: Row {i + 1} must have {cols} elements.")
            return None
        matrix.append(row)

    return matrix

def main():
    matrix = input_matrix()
    if matrix is None:
        return

    print("\nMatrix:")
    for row in matrix:
        print(" ".join(map(str, row)))

    saddle_points = find_saddle_point(matrix)

    if saddle_points:
        print("\nSaddle Points:")
        for point in saddle_points:
            print(f"Value: {point[2]} at Row: {point[0] + 1}, Column: {point[1] + 1}")
    else:
        print("\nNo Saddle Point exists in the matrix.")

if __name__ == "__main__":
    main()
