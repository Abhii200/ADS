def is_safe(node, graph, color, c):
    for neighbor in graph[node]:
        if color[neighbor] == c:
            return False
    return True

def solve(node, graph, m, color, n):
    if node == n:
        return True

    for c in range(1, m + 1):
        if is_safe(node, graph, color, c):
            color[node] = c
            if solve(node + 1, graph, m, color, n):
                return True
            color[node] = 0  # Backtrack

    return False

def graph_coloring(graph, m):
    n = len(graph)
    color = [0] * n

    if solve(0, graph, m, color, n):
        return color
    else:
        return "No solution exists"

# Example usage:
# Graph as adjacency list (0-based indexing)
graph = [
    [1, 2, 3],  # Node 0 is connected to 1, 2, 3
    [0, 2],     # Node 1
    [0, 1, 3],  # Node 2
    [0, 2]      # Node 3
]

m = 3  # Number of colors
result = graph_coloring(graph, m)
print("Coloring of nodes:", result)