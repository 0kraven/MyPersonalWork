import random
import os
def choose_random_word(word_list):
    return random.choice(word_list)

def display_word(word, guessed_letters):
    display = ''.join([letter if letter in guessed_letters else '_' for letter in word])
    print('Current word: ', display)

def get_user_guess():
    return input('Guess a letter: ').lower()

def play_hangman():
    words = ['python', 'hangman', 'challenge', 'programming', 'random']
    word_to_guess = choose_random_word(words)
    guessed_letters = []
    attempts = 6
    correct_guesses = 0

    print('Welcome to Hangman!')
    display_word(word_to_guess, guessed_letters)
    while attempts > 0 and len(word_to_guess) > correct_guesses:

        
        guess = get_user_guess()
        
        if guess in guessed_letters:
            print('You already guessed that letter.')
        elif guess in word_to_guess:
            guessed_letters.append(guess)
            correct_guesses += 1
            if len(word_to_guess) <= correct_guesses:
                print("Congratulations you won!")
                display_word(word_to_guess, guessed_letters)
                break
            print(f'Good guess! "{guess}" is in the word.')
            display_word(word_to_guess, guessed_letters)
        else:
            attempts -= 1
            print(f'Wrong guess! "{guess}" is not in the word. You have {attempts} attempts left.')
            display_word(word_to_guess, guessed_letters)
            if attempts == 0:
                print(f"Oops! No attempts are left :(\nThe correct word was {word_to_guess}")



play_hangman()
