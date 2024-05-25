import random

names = input("Enter the names of persons: ")
names_list = names.split(",")
name = random.choice(names_list)
print(f"{name} is going to buy the meal today!")
