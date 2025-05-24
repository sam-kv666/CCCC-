print('\nЛАБОРАТОРНАЯ #7\n')
print('Задание 1')
tasks = [("Проверить почту", 3), ("Написать отчёт", 1), ("Позвонить клиенту", 2)]
s_tasks = sorted(tasks, key=lambda x: x[1])
print(s_tasks)



print('\nЗадание 2')
purchases = [
    {"item": "Laptop", "price": 1000, "quantity": 2},
    {"item": "Mouse", "price": 25, "quantity": 5},
    {"item": "Keyboard", "price": 45, "quantity": 3}
]
totals = list(map(lambda x: x["price"] * x["quantity"], purchases))
max_purchase = max(totals)
print(totals)
print(max_purchase)



print('\nЗадание 3')
clients = [
    {"name": "Alice", "income": 50000},
    {"name": "Bob", "income": 120000},
    {"name": "Charlie", "income": 70000}
]
c_clients = list(map(lambda x: {**x, "category": "High" if x["income"] > 100000 else "Medium" if x["income"] >= 50000 else "Low"}, clients))
for client in c_clients:
    print(client)
 


print('\nЗадание 4')
flights = [
    {"flight": "A1", "departure": 9, "arrival": 12},
    {"flight": "B2", "departure": 14, "arrival": 18},
    {"flight": "C3", "departure": 6, "arrival": 8}
]
t_flights = list(filter(lambda x: x["arrival"] < 12, flights))
print(t_flights)



print('\nЗадание 5')
messages = [
    {"user": "Исследователь А", "message": "Отчёт готов. Ссылка: http://foundation.org"},
    {"user": "Доктор Б", "message": "Документы можно найти здесь: https://classified.com"},
    {"user": "Охранник В", "message": "Нет аномальной активности за смену."},
    {"user": "Агент Г", "message": "Срочно изучите материалы по объекту 173 на http://statue-database.net"},
    {"user": "Д-р Кляйн", "message": "Обновлённый протокол эксперимента доступен: https://safezone.scp"},
    {"user": "Сотрудник Д", "message": "Просьба ознакомиться с https://docs.anomalies-secure.com перед сменой."},
    {"user": "Старший учёный Л", "message": "Все записи переданы. Никаких аномалий на объекте 096."},
    {"user": "Техник З", "message": "Проблема с сервером устранена. Подробнее: http://fix-report.internal"}
]

p_messages = list(map(
    lambda x: {
        "user": x["user"],
        "message": " ".join([word if not word.startswith("http") else "[ДАННЫЕ УДАЛЕНЫ]" for word in x["message"].split()])
    }, messages
))

for msg in p_messages:
    print(msg)