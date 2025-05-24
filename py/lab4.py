print('\nЛАБОРАТОРНАЯ #4\n')
print('Задание 1')
def k():
    t = float(input('Введите температуру: '))
    if t >= 20:
        r = 'Кондиционер выключен'
    else:
        r = 'Кондиционер включен'
    print(r)
k()



print('\nЗадание 2')
def s():
    m = int(input('Введите номер месяца: '))
    if m in [12, 1, 2]:
        r = 'Зима'
    elif m in [3, 4, 5]:
        r = 'Весна'
    elif m in [6, 7, 8]:
        r = 'Лето'
    elif m in [9, 10, 11]:
        r = 'Осень'
    else:
        r = 'Неправильный номер'
    print(r)
s()



print('\nЗадание 3')
def d():
    try:
        a = float(input('Введите возраст собаки: '))
        if a < 1:
            r = 'Возраст >= 1'
        elif a > 22:
            r = 'Возраст <= 22'
        else:
            if a <= 2:
                h = a * 10.5
            else:
                h = 2 * 10.5 + (a - 2) * 4
            r = f'Возраст в человеческих годах: {h}'
    except ValueError:
        r = 'Не число'
    print(r)
d()



print('\nЗадание 4')
def b():
    try:
        n = int(input('Введите число: '))
        c1 = n % 10 % 2 == 0
        c2 = sum(int(d) for d in str(n)) % 3 == 0
        if c1 and c2:
            r = 'Это число делится на 6'
        else:
            r = 'Это число не делится на 6'
    except ValueError:
        r = 'Это не число'
    print(r)
b()


print('\nЗадание 5')
import re
def p():
    p = input('Введите пароль: ')
    e = []
    if len(p) < 8:
        e.append('Длина должна быть >= 8 символов')
    if not re.search(r'[A-Z]', p):
        e.append('Должны быть заглавные буквы')
    if not re.search(r'[a-z]', p):
        e.append('Должны быть строчные буквы')
    if not re.search(r'\d', p):
        e.append('Должны быть цифры')
    if not re.search(r'[!@#$%^&*(),.?":{}|<>]', p):
        e.append('Должны быть специальные знаки')
    if e:
        r = 'Пароль не надёжен:\n' + '\n'.join(e)
    else:
        r = 'Пароль надёжен'
    print(r)
p()