from collections import deque as q
from itertools import combinations
import numpy as np
import math

class node:
	def __init__(self,index=0,color="white",pred=None,dist=math.inf):
		self.index = index
		self.color = color
		self.pred = pred
		self.dist = dist


def bfs(connect_mat,node_matrix,source=0):
	queue = q()

	node_matrix[source].color = "gray"
	node_matrix[source].dist = 0
	node_matrix[source].pred = None

	queue.append(node_matrix[source])
	while queue:
		vertex = queue.popleft()
		for i in range(8):
			if(connect_mat[vertex.index][i] == 1):
				if(node_matrix[i].color == "white"):
					node_matrix[i].color = "gray"
					node_matrix[i].pred = vertex.index
					node_matrix[i].dist = vertex.dist + 1
					
					queue.append(node_matrix[i])
		vertex.color = "black"

	return node_matrix

def detect_bipartite(node_matrix,connect_mat):
    nodes_by_level = {}
    for node in node_matrix:
        level = node.dist
        if level not in nodes_by_level:
            nodes_by_level[level] = []
        nodes_by_level[level].append(node.index)

    bval=check_odd_cycle(nodes_by_level,connect_mat)
    if(bval):
        print("Not Bipartite")
    else:
        print("Bipartite")

def check_odd_cycle(nodes_by_level,connect_mat):
    for i in nodes_by_level.keys():
        if i==0 or len(nodes_by_level[i])==1:
            continue
        else:
            combination_list=list(combinations(nodes_by_level[i],2))
            for j in combination_list:
                if connect_mat[list(j)[0]][list(j)[1]]==1:
                    return True
                
connect_mat = np.asanyarray([[1,1,0,0,1,1,0,0],
                             [1,1,0,0,1,1,1,0],
                             [0,0,1,0,0,1,1,1],
                             [0,0,0,1,0,0,1,1],
                             [1,1,0,0,1,0,0,0],
                             [1,1,1,0,0,1,0,0],
                             [0,1,1,1,0,0,1,0],
                             [0,0,1,1,0,0,0,1]])

print(connect_mat)

node_matrix = []
for i in range(8):
	n = node()
	n.index = i
	n.color = "white"
	n.pred = None
	n.dist = math.inf
	node_matrix.append(n)

for i in range(len(node_matrix)):
	print(node_matrix[i].index, node_matrix[i].color, node_matrix[i].pred, node_matrix[i].dist)

node_matrix = bfs(connect_mat, node_matrix, source=0)

for i in range(len(node_matrix)):
	print(node_matrix[i].index, node_matrix[i].color, node_matrix[i].pred, node_matrix[i].dist)

detect_bipartite(node_matrix,connect_mat)
