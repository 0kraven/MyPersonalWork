import random

rock = '''
    _______
---'   ____)
      (_____)
      (_____)
      (____)
---.__(___)
'''

paper = '''
    _______
---'   ____)______
          _________)
          ________)
         ________)
---.___________)
'''

scissor = '''
    _______
---'   ____)______
          ________)
       ____________)
      (____)
---.__(___)
'''

ascii_art = [rock, paper, scissor]

user_choice = int(input("What do you choose? Type 0 for Rock, 1 for Paper or 2 for Scissors."))
comp_choice = random.randint(0,2)
print(f"You:\n{ascii_art[user_choice]}")
print(f"Computer:\n{ascii_art[comp_choice]}")
if user_choice == comp_choice:
    print("You win")
else:
    print("You lose")
