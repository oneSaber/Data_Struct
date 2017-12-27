import collections
side = collections.namedtuple('side','v d')

map  = {
    1:[side(2,2),side(4,1)],
    2:[side(4,3),side(5,10)],
    3:[side(1,4),side(6,5)],
    4:[side(3,2),side(5,2),side(6,8),side(7,4)],
    5:[side(7,6)],
    6:[],
    7:[side(6,1)],
}
Infinity = 9999

T = {}
for key in map.keys():
    neww = {
        'known': False,
        'd': Infinity,
        'p': None
    }
    newV = {key: neww}
    T.update(newV)

def Unweight():
    for i in range(len(map.keys())):
        for v in map.keys():
            if not T[v]['known'] and T[v]['d'] == i:
                T[v]['known'] = True
                for w in map[v]:
                    if T[w]['d'] == Infinity:
                        T[w]['d'] = i +1
                        T[w]['p'] = v

def Unweighted(start):
     Q = []
     Q.append(start)
     while len(Q)>0:
         v = Q.pop()
         T[v]['known'] = True
         for w in map[v]:
             if T[w]['d'] == Infinity:
                 T[w]['d']= T[v]['d']+1
                 T[w]['p'] = v
                 Q.append(w)

start  = int(input('start with:'))
T[start]['d'] = 0
T[start]['p'] = 0
def unknownsmallest():
    v = -1
    min = Infinity+1
    for key in T.keys():
        if T[key]['known']==False:
            if min>T[key]['d']:
                min = T[key]['d']
                v = key
    return v
def Dijkstra(start):
    while True:
        V = unknownsmallest()
        if V==-1:
            break
        T[V]['known'] = True
        for w in map[V]:
            if not T[w.v]['known']:
                if T[V]['d'] + w.d<T[w.v]['d']:
                    T[w.v]['d'] = T[V]['d']+ w.d
                    T[w.v]['p'] = V
def WeightedNegataive(start):
    Q = []
    Q.append(start)
    while len(Q)>0:
        v = Q.pop()
        for w in map[v]:
            if T[v]['d']+w.d<T[w.v]['d']:
                T[w.v]['d'] = T[v]['d']+w.d
                T[w.v]['p'] = v
                if w.v not in Q:
                    Q.append(w.v)
Visit = {}
def Dfs(V):
    Visit[V] = True
    print(V)
    for W in map[V]:
        if Visit[W.v] == False:
            Dfs(W.v)
def DeepTrave(start):

    for i in map.keys():
        Visit.update({i:False})
    V = start
    Dfs(V)

Dijkstra(start)
end = int(input('end with:'))
for key in T.keys():
    print("{} {} {} ".format(T[key]['known'], T[key]['d'], T[key]['p']))
path = []
p = end
while p != start:
    path.append(p)
    p = T[p]['p']
path.append(p)
print(path[::-1])


