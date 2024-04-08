class Node:
    def __init__(self, index):
        self.index = index
        self.adjacency_list = []
        self.visited = False
        self.start_time = None
        self.end_time = None

    def add_edge(self, node):
        self.adjacency_list.append(node)


def dfs(node):
    global time
    node.visited = True
    node.start_time = time
    time += 1

    print("Visiting node:",node.index)
    
    for neighbor in node.adjacency_list:
        if not neighbor.visited:
            dfs(neighbor)

    node.end_time = time
    time += 1


nodes = [Node(i) for i in range(7)]
transposed_nodes= [Node(i) for i in range(7)]

nodes[0].add_edge(nodes[2])
nodes[1].add_edge(nodes[2])
nodes[2].add_edge(nodes[3])
nodes[2].add_edge(nodes[5])
nodes[3].add_edge(nodes[4])
nodes[5].add_edge(nodes[6])

transposed_nodes[2].add_edge(transposed_nodes[0])
transposed_nodes[2].add_edge(transposed_nodes[1])
transposed_nodes[3].add_edge(transposed_nodes[2])
transposed_nodes[5].add_edge(transposed_nodes[2])
transposed_nodes[4].add_edge(transposed_nodes[3])
transposed_nodes[6].add_edge(transposed_nodes[5])

# for node in nodes:
#     node.visited = False

# time = 1
# dfs(nodes[0])

# unvisited_node = None
# for node in nodes:
#     if not node.visited:
#         unvisited_node = node
#         break

# if unvisited_node:
#     dfs(unvisited_node)

# node_timing={}
# for node in nodes:
#     print(node.index,": Start time =",node.start_time,"End time =",node.end_time)
#     node_timing[node.index]=node.end_time

# print(sorted(node_timing, key=lambda k: node_timing[k])[::-1])


for node in transposed_nodes:
    node.visited = False

time = 1
dfs(transposed_nodes[6])

unvisited_node = None
for node in transposed_nodes:
    print("hi")
    if not node.visited:
        unvisited_node = node
        break

if unvisited_node:
    dfs(unvisited_node)

node_timing={}
for node in transposed_nodes:
    print(node.index,": Start time =",node.start_time,"End time =",node.end_time)
    node_timing[node.index]=node.end_time

#print(sorted(node_timing, key=lambda k: node_timing[k])[::-1])
