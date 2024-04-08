class Graph:
    def __init__(self, vertices):
        self.V=vertices
        self.edge=[]

    def add_edge(self, u,v,w):
        self.edge.append([u,v,w])

def bellmanFord(g,src):
    dist=[]
    predecessor=[]
    dist=[float("Inf")]*g.V
    predecessor=[None]*g.V
    dist[src]=0
    predecessor[src]=None

    for i in range(g.V-1):
        for u,v,w in g.edge:
            if dist[u]!=float("Inf") and dist[u]+w<dist[v]:
                dist[v]=dist[u]+w
                predecessor[v]=u
    
    for u, v, w in g.edge:
            if dist[u] != float("Inf") and dist[u] + w < dist[v]:
                print("Graph contains negative weight cycle")
                return
    
    printDist(dist,g.V,predecessor)

def printDist(dist,val,predecessor):
    print("Vertices    Distance from source   Predecessor")
    for i in range(val):
        print(i,"\t\t",dist[i],"\t\t\t",predecessor[i])

print("Enter the number of vertices you want in the graph:")
v=int(input())

g= Graph(v)
g.add_edge(0,1,6)
g.add_edge(0,2,4)
g.add_edge(0,3,5)
g.add_edge(2,1,-2)
g.add_edge(3,2,-2)
g.add_edge(3,5,-1)
g.add_edge(4,5,3)
g.add_edge(2,4,3)
g.add_edge(1,4,-1)

bellmanFord(g,0)
