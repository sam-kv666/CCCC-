import datetime

class Tracker:
    def __init__(self):
        self.transactions = []
        self.categories = ['Еда', 'Транспорт', 'Развлечения']

    def add_income(self, amount, category, date, description):
        if category not in self.categories:
            print(f"Категория '{category}' не существует, добавляем её.")
            self.categories.append(category)
        transaction = {
            'amount': amount,
            'category': category,
            'date': datetime.datetime.strptime(date, '%Y-%m-%d'),
            'description': description,
            'type': 'доход'
        }
        self.transactions.append(transaction)

    def add_expense(self, amount, category, date, description):
        if category not in self.categories:
            print(f"\nКатегория '{category}' не существует, добавляем её.\n")
            self.categories.append(category)
        transaction = {
            'amount': amount,
            'category': category,
            'date': datetime.datetime.strptime(date, '%Y-%m-%d'),
            'description': description,
            'type': 'расход'
        }
        self.transactions.append(transaction)

    def show_balance(self):
        total_income = 0
        total_expense = 0
        for t in self.transactions:
            if t['type'] == 'доход':
                total_income += t['amount']
            elif t['type'] == 'расход':
                total_expense += t['amount']
        balance = total_income - total_expense
        print(f"Баланс: {balance} (Доходы: {total_income}, Расходы: {total_expense})")

    def show_transactions(self, start_date=None, end_date=None, category=None):
        for t in self.transactions:
            if start_date and t['date'] < start_date:
                continue
            if end_date and t['date'] > end_date:
                continue
            if category and t['category'] != category:
                continue
            print(f"{t['date'].strftime('%Y-%m-%d')} - {t['type']} - {t['category']} - {t['amount']} - {t['description']}")

    def analyze_expenses(self):
        expense_by_category = {}
        for t in self.transactions:
            if t['type'] == 'расход':
                if t['category'] in expense_by_category:
                    expense_by_category[t['category']] += t['amount']
                else:
                    expense_by_category[t['category']] = t['amount']
        for category, total in expense_by_category.items():
            print(f"{category}: {total}")

    def income_expense_ratio(self):
        total_income = 0
        total_expense = 0
        for t in self.transactions:
            if t['type'] == 'доход':
                total_income += t['amount']
            elif t['type'] == 'расход':
                total_expense += t['amount']
        if total_expense == 0:
            print("Нет расходов для анализа.")
        else:
            ratio = total_income / total_expense
            print(f"Соотношение доходов к расходам: {ratio:.2f}")

def main():
    tracker = Tracker()

    while True:
        print("\nМеню:")
        print("1. Добавить доход")
        print("2. Добавить расход")
        print("3. Показать баланс")
        print("4. Просмотр записей")
        print("5. Анализ расходов")
        print("6. Соотношение доходов и расходов")
        print("7. Выход\n")

        choice = input("Выберите действие: ")

        if choice == '1':
            amount = float(input("Введите сумму дохода: "))
            category = input("Введите категорию (по умолчанию 'Прочее', на выбор: 'Еда', 'Транспорт', 'Развлечения'): ") or 'Прочее'
            date = input("Введите дату (формат гггг-мм-дд): ")
            description = input("Введите описание: ")
            tracker.add_income(amount, category, date, description)

        elif choice == '2':
            amount = float(input("Введите сумму расхода: "))
            category = input("Введите категорию (по умолчанию 'Прочее', на выбор: 'Еда', 'Транспорт', 'Развлечения'): ") or 'Прочее'
            date = input("Введите дату (формат гггг-мм-дд): ")
            description = input("Введите описание: ")
            tracker.add_expense(amount, category, date, description)

        elif choice == '3':
            tracker.show_balance()

        elif choice == '4':
            start_date = input("Введите начальную дату (формат гггг-мм-дд, или нажмите 'Enter' для всех): ")
            if start_date:
                start_date = datetime.datetime.strptime(start_date, '%Y-%m-%d')
            end_date = input("Введите конечную дату (формат гггг-мм-дд, или нажмите 'Enter' для всех): ")
            if end_date:
                end_date = datetime.datetime.strptime(end_date, '%Y-%m-%d')
            category = input("Введите категорию для фильтрации (или нажмите 'Enter' для всех): ")
            print('\n')
            tracker.show_transactions(start_date, end_date, category)

        elif choice == '5':
            tracker.analyze_expenses()

        elif choice == '6':
            tracker.income_expense_ratio()

        elif choice == '7':
            print("Выход из программы.")
            break

        else:
            print("Неверный выбор. Попробуйте снова.")

if __name__ == "__main__":
    main()