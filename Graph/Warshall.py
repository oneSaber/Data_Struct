Mr = [[0,0,0,1],[1,0,1,0],[1,0,0,1],[0,0,1,0]]
def Warhsall():
    W = Mr
    k = 0
    n = len(Mr)
    while k< n:
        for i in range(n):
            if Mr[i][k]==1:
                for j in range(n):
                    W[i][j] = W[i][j] or W[k][j]
        k = k+1
    print(W)
Warhsall()