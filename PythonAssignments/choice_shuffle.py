import random

alphabets = [
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
    'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd',
    'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
    't', 'u', 'v', 'w', 'x', 'y', 'z'
]

special_symbols = [
    '!', '"', '#', '$', '%', '&', "'", '(', ')', '*', '+', ',', '-', '.', '/',
    ':', ';', '<', '=', '>', '?', '@', '[', ']', '^', '_', '`', '{', '|', '}',
    '~'
]

numerics = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']

print("Welcome to the PyPassword Generator!")

letters = int(input("How many letters would you like in your password? "))

symbols = int(input("How many symbols would you like? "))

numbers = int(input("How many numbers would you like? "))
password = []

for i in range(letters):
  password += random.choice(alphabets)
for i in range(symbols):
  password += random.choice(special_symbols)
for i in range(numbers):
  password += random.choice(numerics)

random.shuffle(password)
print(''.join(password))
