print('\nЛАБОРАТОРНАЯ #5\n')
print('Задание 1')
def r(list):
    return [30 if x == 3 else x for x in list]
list1 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
print(r(list1))



print('\nЗадание 2')
def k(list):
    return [x ** 2 for x in list]
list1 = [1, 2, 3, 4, 5]
print(k(list1))



print('\nЗадание 3')
def d(list):
    return max(list) / len(list) if list else None
list1 = [5, 1, 3, 8, 7]
print(d(list1))



print('\nЗадание 4')
def k(t):
    return tuple(sorted(t)) if all(isinstance(x, (int, float)) for x in t) else t
t1 = (10, 2, 5, 8, 3)
t2 = (10, 2, 'a', 8, 3)
print(k(t1))
print(k(t2))



print('\nЗадание 5')
def mm(d):
    min_item = min(d, key=d.get)
    max_item = max(d, key=d.get)
    return min_item, max_item
d = {'яблоко': 10, 'банан': 20, 'молоко': 15, 'хлеб': 5}
print('Минимальная цена:', mm(d)[0], '|' , 'Максимальная цена:', mm(d)[1])



print('\nЗадание 6')
def l(list):
    return {x: x for x in list}
list1 = ['яблоко', 'банан', 'молоко']
print(l(list1))



print('\nЗадание 7')
def t(d):
    rus = input('Введите русское слово для перевода: ')
    for eng, ru in d.items():
        if ru == rus:
            return f'Перевод: {eng}'
    return 'Нет перевода'
d = {'apple': 'яблоко', 'banana': 'банан', 'milk': 'молоко'}
print(t(d))



print('\nЗадание 8')
import random
def k():
    vibor = ['Камень', 'Ножницы', 'Бумага', 'Ящерица', 'Спок']
    pravila = {
        'Ножницы': ['Бумага', 'Ящерица'],
        'Бумага': ['Камень', 'Спок'],
        'Камень': ['Ножницы', 'Ящерица'],
        'Ящерица': ['Спок', 'Бумага'],
        'Спок': ['Ножницы', 'Камень']
    }
    player = input('Введите ваш выбор (Камень/Ножницы/Бумага/Ящерица/Спок): ')

    if player not in vibor:
        return 'Такого варианта нет'
    
    comp = random.choice(vibor)

    if player == comp:
        r = 'Ничья'
    elif comp in pravila[player]:
        r = 'Игрок выиграл'
    else:
        r = 'Компьютер выиграл'
    
    return f'Игрок: {player}, Компьютер: {comp}. {r}'
print(k())