def matrix_chain_order(p):
    n = len(p) - 1

    # dp[i][j] = minimum multiplication cost
    dp = [[0] * n for _ in range(n)]

    for length in range(2, n + 1):
        for i in range(n - length + 1):
            j = i + length - 1
            dp[i][j] = float('inf')

            for k in range(i, j):
                cost = (dp[i][k] +
                        dp[k + 1][j] +
                        p[i] * p[k + 1] * p[j + 1])

                dp[i][j] = min(dp[i][j], cost)

    return dp[0][n - 1]


# Example:
# A1 = 10x20, A2 = 20x30, A3 = 30x40
p = [10, 20, 30, 40]

result = matrix_chain_order(p)

print("Minimum number of multiplications:", result)