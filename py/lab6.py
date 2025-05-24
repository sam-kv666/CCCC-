print('\nЛАБОРАТОРНАЯ #6\n')
print('Задание 1')
def f(n, u1, u2):
    t = {'h': 60, 'm': 1, 's': 1/60}
    return n * t[u1] / t[u2]

n = float(input("Введите число: "))
u1 = input("Введите исходную единицу измерения (h, m, s): ")
u2 = input("Введите новую единицу измерения (h, m, s): ")
print(f(n, u1, u2))



print('\nЗадание 2')
def c(a, n):
    if a < 30000:
        return "Минимальный вклад равен 30 000 рублей"
    percent = min(0.3 * (a // 10000), 5)

    profit = 0
    if n <= 3:
        profit = a * (1 + (percent + 3) / 100) ** n
    elif 3 < n <= 6:
        profit = (a * (1 + (percent + 3) / 100) ** 3) * (1 + (percent + 5) / 100) ** (n - 3)
    else:
        profit = (
            (a * (1 + (percent + 3) / 100) ** 3)
            * (1 + (percent + 5) / 100) ** 3
            * (1 + (percent + 2) / 100) ** (n - 6)
        )
    return round(profit - a, 2)

if __name__ == "__main__":
    try:
        a = float(input("Введите сумму вклада: "))
        n = float(input("Введите на сколько лет будет вклад: "))
        result = c(a, n)
        print(result)
    except ValueError:
        print("Error!")



print('\nЗадание 3')
def p(a, b):
    if a <= 0 or b <= 0 or a >= b:
        return "Error!"
    r = []
    for x in range(a, b + 1):
        if x > 1 and all(x % i != 0 for i in range(2, int(x ** 0.5) + 1)):
            r.append(x)
    return " ".join(map(str, r))

a = int(input("Введите начало диапазона: "))
b = int(input("Введите конец диапазона: "))
print(p(a, b))



print('\nЗадание 4')
def m():
    n = int(input("Введите размер матрицы: "))
    if n < 2:
        return "Error!"
    m1 = [list(map(int, input(f"Введите строку #{i + 1} первой матрицы: ").split())) for i in range(n)]
    m2 = [list(map(int, input(f"Введите строку #{i + 1} второй матрицы: ").split())) for i in range(n)]
    res = [[m1[i][j] + m2[i][j] for j in range(n)] for i in range(n)]
    return "\n".join(" ".join(map(str, row)) for row in res)
print(m())



print('\nЗадание 5')
def f(s):
    s = ''.join(c for c in s.lower() if c.isalnum())
    if s == s[::-1]:
        return "Да"
    else:
        return "Нет"

s = input("Введите строку: ")
print(f(s))