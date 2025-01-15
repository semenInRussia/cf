def calculate_distances(mode, n, graph):
    mst_min = float("inf")
    mst_max = float("-inf")
    min_people = [0] * n

    for start in range(n):
        visited = [0] * n
        visited[start] = 1

        def dfs_explorer(curr_node, parent):
            nonlocal mst_min, mst_max
            if visited[curr_node]:
                return
            visited[curr_node] = 1
            mst_min += sum([x.count(curr_node) for x in graph])
            mst_max += sum([x.count(curr_node) for x in graph])
            for neighbor in graph[curr_node]:
                if neighbor == parent:
                    continue
                dfs_explorer(neighbor, curr_node)

        dfs_explorer(start, -1)

        visited = [0] * n
        visited[start] = 1
        prev_node = -1

        for node in range(n):
            if visited[node] == 1:
                prev_node = node
                break

        dfs_explorer(prev_node, -1)

    ans1 = mst_min
    ans2 = sum(min_people)

    return ans1, ans2


mode = int(input())
n = int(input())
graph = [[] for _ in range(n)]
for _ in range(n - 1):
    a, b = map(int, input().split())
    graph[a - 1].append(b - 1)
    graph[b - 1].append(a - 1)

res = calculate_distances(mode, n, graph)

print(" ".join(map(str, res)))
