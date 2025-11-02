def print_solution(colors):
    print("Solution Exists: Frequencies (colors) assigned are:")
    for i in range(len(colors)):
        print(f" Cell {i} -> Frequency {colors[i]}")

def is_safe(v, graph, colors, c):
    V = len(graph)
    for i in range(V):
        if graph[v][i] == 1 and colors[i] == c:
            return False
    return True

def solve_coloring_recursive(graph, m, colors, v):
    V = len(graph)
    if v == V:
        return True
    for c in range(1, m + 1):
        if is_safe(v, graph, colors, c):
            colors[v] = c
            if solve_coloring_recursive(graph, m, colors, v + 1):
                return True
            colors[v] = 0
    return False

def find_coloring_solution(graph, m, graph_name):
    print(f"### {graph_name} Solution ###")
    V = len(graph)
    colors = [0] * V
    if solve_coloring_recursive(graph, m, colors, 0) == False:
        print(f"No solution exists with {m} frequencies (colors).")
    else:
        print_solution(colors)
graph_1_matrix = [
    [0, 1, 1, 1, 1, 0],
    [1, 0, 0, 1, 0, 0],
    [1, 0, 0, 0, 1, 0],
    [1, 1, 0, 0, 0, 1],
    [1, 0, 1, 0, 0, 1],
    [0, 0, 0, 1, 1, 0]
]
m_1 = 3
find_coloring_solution(graph_1_matrix, m_1, "Graph 1")
print("\n------------------------------\n")
graph_2_matrix = [
    [0, 1, 1, 1, 1],
    [1, 0, 1, 1, 1],
    [1, 1, 0, 1, 1],
    [1, 1, 1, 0, 1],
    [1, 1, 1, 1, 0]
]
m_2_fail = 4
find_coloring_solution(graph_2_matrix, m_2_fail, "Graph 2 (Attempt 1: 4 Colors)")
print("")
m_2_success = 5
find_coloring_solution(graph_2_matrix, m_2_success, "Graph 2 (Attempt 2: 5 Colors)")
