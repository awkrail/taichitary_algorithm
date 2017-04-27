def prim(n, M):
    color = [0 for _ in range(n)]
    d = [5000 for _ in range(n)]
    p = [-1 for _ in range(n)]

    d[0] = 0

    while True:
        mincost = 100000
        u = -1

        for i, dt in enumerate(d):
            if dt < mincost and color[i] != 1:
                mincost = dt
                u = i

        # 更新がなかった場合
        if mincost == 100000:
            break

        color[u] = 1

        for v in range(n):
            # 辺があり, かつまだ訪れてないところ
            if M[u][v] != 5000 and color[v] != 1:
                if M[u][v] < d[v]:
                    d[v] = M[u][v]
                    p[v] = u

    all_sum = 0

    for i, p_dt in enumerate(p):
        if p_dt != -1:
            all_sum += M[i][p_dt]

    return all_sum


def main():
    n = int(input())
    M = []

    for _ in range(n):
        dt = input().split(' ')
        M.append([5000 if int(d) == -1 else int(d) for d in dt])

    answer = prim(n, M)

    print(answer)

if __name__ == '__main__':
    main()