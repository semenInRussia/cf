from collections import defaultdict


def is_good_graph(n, m, k, edges, color_changes):
    graph = defaultdict(list)
    color_count = defaultdict(int)

    for v, u, c in edges:
        graph[v].append((u, c))
        graph[u].append((v, c))
        color_count[c] += 1

    def is_connected(graph, colors):
        visited = set()

        def dfs(node):
            visited.add(node)
            for neighbor, color in graph[node]:
                if neighbor not in visited and colors[color] > 0:
                    dfs(neighbor)

        start_node = next(iter(graph.keys()))
        dfs(start_node)

        return len(visited) == n

    colors = dict.fromkeys(range(1, k + 1), 0)

    result = []

    for e, w in color_changes:
        v, u, c = edges[e - 1]
        color_count[c] -= 1
        color_count[w] += 1
        colors[c] -= 1
        colors[w] += 1

        if color_count[c] == 0:
            del colors[c]

        if is_connected(graph, colors):
            result.append("Yes")
        else:
            result.append("No")

    return result


n, m, k = map(int, input().split())
edges = [list(map(int, input().split())) for _ in range(m)]
q = int(input())
color_changes = [list(map(int, input().split())) for _ in range(q)]

result = is_good_graph(n, m, k, edges, color_changes)
for res in result:
    print(res)
