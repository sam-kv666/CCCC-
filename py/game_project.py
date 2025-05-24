import random
import time
import os
from colorama import Fore, Style, init

class Character:
    def __init__(self, name):
        self.name = name
        self.health = random.randint(18, 22)
        self.attack = random.randint(7, 11)
        self.defense = random.randint(4, 6)
        self.inventory = {
            "дерево": 0,
            "камень": 0,
            "железо": 0,
            "алмазы": 0,
            "зелье лечения": 0,
            "деревянная кирка": 0,
            "железный меч": 0,
            "железная броня": 0,
            "алмазный меч": 0,
            "алмазная броня": 0,
            "верстак": 0
        }
        self.level = 1
        self.exp = 0

    def level_up(self):
        self.level += 1
        print("\n" * 50 + f"{self.name} повысил уровень! Новый уровень: {self.level}")

class Mob:
    def __init__(self, name, health, attack, defense):
        self.name = name
        self.health = health
        self.attack = attack
        self.defense = defense

    def take_damage(self, damage):
        self.health -= damage

class Zombie(Mob):
    def __init__(self):
        super().__init__("Зомби", random.randint(20, 30), random.randint(5, 8), random.randint(3, 5))

class Skeleton(Mob):
    def __init__(self):
        super().__init__("Скелет", random.randint(25, 40), random.randint(6, 12), random.randint(4, 6))

class Creeper(Mob):
    def __init__(self):
        super().__init__("Крипер", 0, 0, 0)

    def explode(self, player):
        damage = random.randint(10, 20)
        damage -= player.defense
        if damage < 1:
            damage = 1
        player.health -= damage
        print(f"{self.name} выскочил и взорвался! Он нанёс {damage} урона!")
        return True

def fight(player, mob):
    print("\n" * 50 + f"Вы столкнулись с {mob.name}!")
    if isinstance(mob, Creeper):
        if mob.explode(player):
            if player.health <= 0:
                print("Вы проиграли...\n")
                return
    while player.health > 0 and mob.health > 0:
        print(f"Ваше здоровье: {player.health}. Здоровье {mob.name}: {mob.health}\n")
        print("1. Атаковать")
        print("2. Использовать хилку")
        print("3. Уклониться и ударить")
        choice = input("> ")
        while choice not in ["1", "2", "3"]:
            print("\nНеверный выбор. Попробуйте снова.\n")
            print("1. Атаковать")
            print("2. Использовать хилку")
            print("3. Уклониться и ударить")
            choice = input("> ")
        if choice == "1":
            damage = max(player.attack - mob.defense, 0)
            mob.take_damage(damage)
            print(f"\nВы нанесли {damage} урона {mob.name}!")
        elif choice == "2":
            if "зелье лечения" in player.inventory and player.inventory["зелье лечения"] > 0:
                player.health += 20
                player.inventory["зелье лечения"] -= 1
                print("\nВаше здоровье увеличено на 20!")
            elif "золотое яблоко" in player.inventory and player.inventory["золотое яблоко"] > 0:
                player.health += 30
                player.inventory["золотое яблоко"] -= 1
                print("\nВаше здоровье увеличено на 30!")
            else:
                print("\nУ вас нет хила!")
        elif choice == "3":
            if random.random() < 0.5:
                print("\nВы уклонились и нанесли удар!")
                damage = max(player.attack - mob.defense, 1)
                mob.take_damage(damage)
                print(f"Вы нанесли {damage} урона {mob.name}!")
                continue
            else:
                print("\nУклониться не получилось!")
        if mob.health > 0:
            damage = max(mob.attack - player.defense, 1)
            player.health -= damage
            print(f"{mob.name} атаковал Вас и нанёс {damage} урона!")
    if player.health > 0:
        print(f"Вы победили {mob.name}!")
        player.exp += 10
        if player.exp >= player.level * 10:
            player.level_up()
    else:
        print("Вы проиграли...\n")

def explore(player):
    print("\n" * 50 + "Вы решили исследовать местность.")
    event = random.choice(["моб", "сундук", "ничего"])
    if event == "моб":
        mob_choice = random.choice([Zombie(), Skeleton(), Creeper()])
        if isinstance(mob_choice, Creeper):
            print("\nВы нарвались на Крипера!")
        fight(player, mob_choice)
    elif event == "сундук":
        item = random.choices(
            ["зелье лечения", "золотое яблоко"],
            weights=[80, 20],
            k=1
        )[0]
        player.inventory[item] = player.inventory.get(item, 0) + 1
        print(f"Вы нашли сундук, в котором было {item}!")
    else:
        print("Вы ничего не нашли.")

def gather_wood(player):
    print("\n" * 50 + "Вы решили собирать дерево.")
    collected_wood = random.randint(3, 6)
    player.inventory["дерево"] += collected_wood
    print(f"Вы собрали {collected_wood} блока(ов) дерева.")

def mine_resources(player):
    if "деревянная кирка" in player.inventory and player.inventory["деревянная кирка"] > 0:
        print("\n" * 50 + "Вы отправились в шахту.")
        collected_stone = random.randint(3, 7)
        player.inventory["камень"] += collected_stone
        print(f"Вы добыли {collected_stone} блока(ов) камня.")
        if random.random() < 0.8:
            collected_iron = random.randint(2, 4)
            player.inventory["железо"] += collected_iron
            print(f"Вы добыли {collected_iron} блока железной руды.")
        if random.random() < 0.2:
            collected_diamonds = random.randint(1, 2)
            player.inventory["алмазы"] += collected_diamonds
            print(f"Вы добыли {collected_diamonds} алмаз(а)!")
    else:
        print("\n" * 50 + "У вас нет деревянной кирки для добычи ресурсов!")

def create_workbench(player):
    required_wood = 4
    available_wood = player.inventory.get("дерево", 0)
    if available_wood >= required_wood:
        print("\n" * 50 + "Вы скрафтили верстак.")
        player.inventory["верстак"] = player.inventory.get("верстак", 0) + 1
        player.inventory["дерево"] -= required_wood
    else:
        missing_wood = required_wood - available_wood
        print("\n" * 50 + f"Недостаточно {missing_wood} дерева для крафта верстака.")

def craft_tools(player):
    if "верстак" in player.inventory and player.inventory["верстак"] > 0:
        required_wood = 3
        available_wood = player.inventory.get("дерево", 0)
        if available_wood >= required_wood:
            print("\n" * 50 + "Вы скрафтили деревянную кирку.")
            player.inventory["деревянная кирка"] = player.inventory.get("деревянная кирка", 0) + 1
            player.inventory["дерево"] -= required_wood
        else:
            missing_wood = required_wood - available_wood
            print("\n" * 50 + f"Недостаточно {missing_wood} дерева для крафта.")
    else:
        print("\n" * 50 + "У вас нет верстака для крафта деревянной кирки!")

def forge_weapon(player):
    required_iron = 26
    available_iron = player.inventory.get("железо", 0)
    if available_iron >= required_iron:
        print("\n" * 50 + "Вы скрафтили железный меч и броню.")
        player.inventory["железный меч"] = player.inventory.get("железный меч", 0) + 1
        player.inventory["железная броня"] = player.inventory.get("железная броня", 0) + 1
        player.attack += 5
        player.defense += 3
        player.inventory["железо"] -= required_iron
    else:
        missing_iron = required_iron - available_iron
        print("\n" * 50 + f"Недостаточно {missing_iron} железа для крафта.")

def prepare_for_dragon(player):
    required_diamonds = 26
    available_diamonds = player.inventory.get("алмазы", 0)
    if available_diamonds >= required_diamonds:
        print("\n" * 50 + "Вы создали алмазный меч и броню!")
        player.inventory["алмазный меч"] = player.inventory.get("алмазный меч", 0) + 1
        player.inventory["алмазная броня"] = player.inventory.get("алмазная броня", 0) + 1
        player.attack += 10
        player.defense += 5
        player.inventory["алмазы"] -= required_diamonds
    else:
        missing_diamonds = required_diamonds - available_diamonds
        print("\n" * 50 + f"Недостаточно {missing_diamonds} алмаза(ов) для крафта.")

def show_inventory(player):
    print("\n" * 50 + "Ваш инвентарь:")
    inventory_list = []
    for item, quantity in player.inventory.items():
        if quantity > 0:
            inventory_list.append(f"{item} x{quantity}")
    max_length = 80
    current_line = ""
    for item in inventory_list:
        if len(current_line) + len(item) + 2 > max_length:
            print(current_line)
            current_line = item
        else:
            if current_line:
                current_line += ", " + item
            else:
                current_line = item
    if current_line:
        print(current_line)

def main():
    print("\n" * 50 + "∘₊✧───────────────────────────────────────────────────────────────────────────────✧₊∘")
    print("                  ⎝⎝ Добро пожаловать в ＭＩＮＥＣＲＡＦＴ⎠⎠")
    print("∘₊✧───────────────────────────────────────────────────────────────────────────────✧₊∘")
    print("    ⛏️  Цель игры: добыча ресурсов и крафт вещей для победы над Эндер-драконом!⚔️")
    print("∘₊✧───────────────────────────────────────────────────────────────────────────────✧₊∘")
    name = input("\n        Введите Ваш ник: ")
    player = Character(name)

    print("\n" * 50 + "∘₊✧──────────────────✧₊∘")
    print(f"  Ваш персонаж создан!\n     Имя: {player.name}\n     Здоровье: {player.health}\n     Атака: {player.attack}\n     Защита: {player.defense}")
    print("∘₊✧──────────────────✧₊∘")

    while player.health > 0:
        print("\nЧто делаем?")
        print("1. Идём изучать мир")
        print("2. Добываем дерево")
        print("3. Идём в шахту")
        print("4. Создаём верстак")
        print("5. Крафтим деревянную кирку")
        print("6. Крафтим железный меч и броню")
        print("7. Крафтим алмазный меч и броню")
        print("8. Идём сражаться с Эндер-драконом")
        print("9. Проверим инвентарь")
        print("10. Выйти из игры")
        choice = input("> ")

        while choice not in ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10"]:
            print("\n" * 50 + "Неверный выбор. Попробуйте снова.\n")
            print("1. Идём изучать мир")
            print("2. Добываем дерево")
            print("3. Идём в шахту")
            print("4. Создаём верстак")
            print("5. Крафтим деревянную кирку")
            print("6. Крафтим железный меч и броню")
            print("7. Крафтим алмазный меч и броню")
            print("8. Идём сражаться с Эндер-драконом")
            print("9. Проверим инвентарь")
            print("10. Выйти из игры")
            choice = input("> ")

        if choice == "1":
            explore(player)

        elif choice == "2":
            gather_wood(player)

        elif choice == "3":
            mine_resources(player)

        elif choice == "4":
            create_workbench(player)

        elif choice == "5":
            craft_tools(player)

        elif choice == "6":
            forge_weapon(player)

        elif choice == "7":
            prepare_for_dragon(player)

        elif choice == "8":
            if "алмазный меч" in player.inventory and player.inventory["алмазный меч"] > 0 and "алмазная броня" in player.inventory and player.inventory["алмазная броня"] > 0:
                fight_dragon(player)
                break
            else:
                print("\n" * 50 + "Вы ещё не готовы к битве с Эндер-драконом!")

        elif choice == "9":
            show_inventory(player)

        elif choice == "10":
            print("\n" * 50 + "Выход из игры...")
            break

init()

def dragon_victory_animation():
    os.system("cls" if os.name == "nt" else "clear")
    victory_message = [
        "Спустя столько лет...",
        "Мир спасён от тьмы...",
        "Вы - величайший герой!"
    ]
    for line in victory_message:
        print("\n" * 5)
        print(Fore.YELLOW + line.center(80) + Style.RESET_ALL)
        time.sleep(1)
    for i in range(10):
        os.system("cls" if os.name == "nt" else "clear")
        print("\n" * (5 + (i % 2)))
        print(Fore.GREEN + "🏆 ПОБЕДА НАД ЭНДЕР-ДРАКОНОМ! 🏆".center(80) + Style.RESET_ALL)
        time.sleep(0.1)

def fight_dragon(player):
    print("\n" * 50 + "Вы вошли в портал в Край...")
    dragon = Mob("Эндер-дракон", 150, 20, 10)
    fight(player, dragon)
    if player.health > 0:
        dragon_victory_animation()
    else:
        print("\n" * 50 + "Вы проиграли...\n")

if __name__ == "__main__":
    main()