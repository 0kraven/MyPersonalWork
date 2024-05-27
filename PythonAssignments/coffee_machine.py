coffee_details = {
    "espresso": {
        "water": 50,
        "coffee": 18,
        "milk": 0,
        "cost": 1.5
    },
    "latte": {
        "water": 200,
        "coffee": 24,
        "milk": 150,
        "cost": 2.5
    },
    "cappuccino": {
        "water": 250,
        "coffee": 24,
        "milk": 100,
        "cost": 3.0
    }
}

resources = {"water": 300, "milk": 200, "coffee": 100, "money": 0}

def check_resources(drink):
    for item, amount in drink.items():
        if item != "cost" and resources[item] < amount:
            print(f"Sorry, there is not enough {item}.")
            return False
    return True

def process_payment(cost):

    print("Please insert coins: ")
    quarters = int(input("How many quarters?: ")) * 0.25
    dimes = int(input("How many dimes?: ")) * 0.1
    nickles = int(input("How many nickles?: ")) * 0.05
    pennies = int(input("How many pennies?: ")) * 0.01
    total = quarters + dimes + nickles + pennies
    if total >= cost:
        change = round(total - cost, 2)
        print(f"Here is ${change} in change.")
        resources["money"] += cost
        return True
    else:
        print("Sorry, that's not enough money")
        return False
def make_coffee(drink):
    for item, amount in drink.items():
        if item != "cost":
            resources[item] -= amount
    print(f"Here is your {choice}. Enjoy!")
def show_report():
    print(f"Water: {resources['water']}ml")
    print(f"Milk: {resources['milk']}ml")
    print(f"Coffee: {resources['coffee']}g")
    print(f"Money: ${resources['money']}")
is_on = True
while is_on:
    choice = input("What would you like? (espresso/latte/cappuccino): ").lower()
    if choice == "off":
        is_on = False
    elif choice == "report":
        show_report()
    else:
        drink = coffee_details[choice]
        if check_resources(drink):
            if process_payment(drink["cost"]):
                make_coffee(drink)
