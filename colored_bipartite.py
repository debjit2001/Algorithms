'''from collections import deque



def bfs(adjacency_matrix,index):
    
    vertex_count=len(adjacency_matrix)
    visited=[False]*vertex_count
    queue=deque([index])
    visited[index]=True
    tree_builder_hashmap={}
    neighbour_nodes=[]
    node_level={}
    current_level=0
    node_level[current_level]=[index];
    current_level+=1
    
    while queue:
        vertex=queue.popleft()
        print("Vertex:",vertex)
        neighbour_nodes=[]
        for neighbour in range(vertex_count):
            if adjacency_matrix[vertex][neighbour]==1 and not visited[neighbour]:
                queue.append(neighbour)
                neighbour_nodes.append(neighbour)
                visited[neighbour]=True
        node_level[current_level]=neighbour_nodes 
        tree_builder_hashmap[vertex]=neighbour_nodes
        current_level+=1
    
    print(tree_builder_hashmap)
    print(node_level)
    
    
def create_graph(vertices,edges):
    print("Creating graph with",vertices,"vertices and",edges,"edges.")
    adjacency_matrix=[[0]*vertices for _ in range(vertices)]
    
    print("Enter the edge connection:")
    for _ in range(edges):
        x,y=map(int,input().split())
        adjacency_matrix[x][y]=1
        adjacency_matrix[y][x]=1

    print(adjacency_matrix)
    
    print("Enter the start index for the bfs traversal:")
    index=int(input())

    """num_vertices = len(adjacency_matrix)
    visited = [False] * num_vertices

    for vertex in range(num_vertices):
        if not visited[vertex]:
            print("BFS Traversal starting from vertex", vertex)
            bfs(adj_matrix, vertex)
            print()"""
    
    bfs(adjacency_matrix,index)


print("Enter the value of vertices and edges of the graph")
v,e=map(int,input().split())
create_graph(v,e)'''

from collections import deque as q
import numpy as np
import math

class node:
    def __init__(self, index):
        self.index = index
        self.color = None
        self.pred = None
        self.dist = math.inf


def bfs(connect_mat, node_matrix, source=0):
    queue = q()

    node_matrix[source].color = "red"
    node_matrix[source].dist = 0
    node_matrix[source].pred = None

    queue.append(node_matrix[source])
    while queue:
        vertex = queue.popleft()
        for i in range(8):
            if connect_mat[vertex.index][i] == 1:
                if node_matrix[i].color is None:
                    if vertex.color == "red":
                        node_matrix[i].color = "blue"
                    else:
                        node_matrix[i].color="red"
                    node_matrix[i].pred = vertex.index
                    node_matrix[i].dist = vertex.dist + 1
                    queue.append(node_matrix[i])
                    if node_matrix[i].color == vertex.color:
                        print("Not Bipartite")
    return node_matrix

def detect_bipartite(node_matrix, connect_mat):
    print("hi")
    
connect_mat = np.asarray([[1, 0, 0, 0, 1, 1, 0, 0],
                          [0, 1, 0, 0, 1, 1, 1, 0],
                          [0, 0, 1, 0, 0, 1, 1, 1],
                          [0, 0, 0, 1, 0, 0, 1, 1],
                          [1, 1, 0, 0, 1, 0, 0, 0],
                          [1, 1, 1, 0, 0, 1, 1, 0],
                          [0, 1, 1, 1, 0, 1, 1, 0],
                          [0, 0, 1, 1, 0, 0, 0, 1]])

print(connect_mat)

node_matrix = []
for i in range(8):
    n = node(i)
    node_matrix.append(n)

for i in range(len(node_matrix)):
    print(node_matrix[i].index, node_matrix[i].color, node_matrix[i].pred, node_matrix[i].dist)

node_matrix = bfs(connect_mat, node_matrix, source=0)

for i in range(len(node_matrix)):
    print(node_matrix[i].index, node_matrix[i].color, node_matrix[i].pred, node_matrix[i].dist)

