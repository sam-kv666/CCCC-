print('\nЛАБОРАТОРНАЯ #3\n')
print('Задание #1')
name = input('Введите Ваше имя: ')
age = input('Введите Ваш возраст: ')
for i in range(10):
    print(f'Меня зовут {name} и мне {age} лет')



print('\nЗадание #2')
num = int(input('Введите число от 1 до 9: '))
print(f'Таблица умножнения для {num}:')
for i in range(1, 11):
    print(f'{num} * {i} = {num * i}')



print('\nЗадание #3')
print('Каждое третье число в диапазоне от 0 до 100:')
for i in range(0, 101, 3):
    print(i, end = " ")
print('')



print('\nЗадание #4')
def f(n):
    r = 1
    for i in range(1, n + 1):
        r *= i
    print(r)
f(int(input("Введите число для вычисления его факториала: ")))



print('\nЗадание #5')
print('Числа от 20 до 0:')
i = 20
while i >= 0:
    print(i, end = " ")
    i -= 1
print('')



print('\nЗадание #6')
def f(n):
    a, b = 0, 1
    while a <= n:
        print(a, end=" ")
        a, b = b, a + b
f(int(input("Введите число для предела последовательности Фибоначчи: ")))
print('')



print("\nЗадание 7")
def f(s):
    r = ""
    for i in range(len(s)):
        r += s[i] + str(i + 1)
    print(r)
f(input("Введите строку: "))



print("\nЗадание 8")
while True:
    a = input("Введите два числа через пробел (stop для выхода): ")
    if a.lower() == "stop":
        break
    try:
        num1, num2 = map(int, a.split())
        print(f"Сумма равна: {num1 + num2}")
    except ValueError:
        print("Пожалуйста, введите два корректных числа.")