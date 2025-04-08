
board = []

col = [0] * 8
di1 = [0] * 20
di2 = [0] * 20

ans = 0;

def queen(k):
    global ans
    if k == 8:
        # uma solucao
        ans += 1
        return
    for c in range(8):
        if col[c] == 0 and di1[c+k] == 0 and di2[c-k+7] == 0 and board[k][c] != '*':
            col[c] = di1[c+k] = di2[c-k+7] = 1
            queen(k+1)
            col[c] = di1[c+k] = di2[c-k+7] = 0

for c in range(0, 8):
    chars = input()
    columns = list(chars)
    board.append(columns)

queen(0)
print(ans)

