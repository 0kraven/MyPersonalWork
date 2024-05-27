board  = [
    ['1','2','3'],
    ['4','5','6'],
    ['7','8','9']
]
def show_board():
    for i in board:
        print("  ".join(i))
def intro():
    print("T I C    T A C   T O E")
    player1 = input("Enter name of player 1: ")
    player2 = input("Enter name of player 2: ")
    print("-----------------------------------")
    show_board()
    print("-----------------------------------")
    return player1,player2

def player_one(player_1):
    player1_turn = True
    while player1_turn:
        move_of_player1 = input(f"{player_1} Enter your move: ")
        for row in range(len(board)):
            for column in range(len(board)):
                if board[row][column] == move_of_player1 and board[row][column] != 'O':
                    board[row][column] = 'X'
                    if (board[0][0] == board[0][1] == board[0][2] == 'X') or (board[1][0] == board[1][1] == board[1][2] == 'X') or (board[2][0] == board[2][1] == board[2][2] == 'X') or (board[0][0] == board[1][0] == board[2][0] == 'X') or (board[0][1] == board[1][1] == board[2][1] == 'X') or (board[0][2] == board[1][2] == board[2][2] == 'X') or (board[0][0] == board[1][1] == board[2][2] == 'X') or (board[0][2] == board[1][1] == board[2][0] == 'X'):
                        return False
                    player1_turn = False
                    show_board()
                    return True
        print("------- Invalid input -------")


def player_two(player_2):
    player2_turn = True
    while player2_turn:
        move_of_player2 = input(f"{player_2} Enter your move: ")
        for row in range(len(board)):
            for column in range(len(board)):
                if board[row][column] == move_of_player2 and board[row][column] != 'X':
                    board[row][column] = 'O'
                    if (board[0][0] == board[0][1] == board[0][2] == 'O') or (board[1][0] == board[1][1] == board[1][2] == 'O') or (board[2][0] == board[2][1] == board[2][2] == 'O') or (board[0][0] == board[1][0] == board[2][0] == 'O') or (board[0][1] == board[1][1] == board[2][1] == 'O') or (board[0][2] == board[1][2] == board[2][2] == 'O') or (board[0][0] == board[1][1] == board[2][2] == 'O') or (board[0][2] == board[1][1] == board[2][0] == 'O'):
                        return False
                    player2_turn = False
                    show_board()
                    return True
        print("------- Invalid input -------")


def check_for_draw():
    initial_board  = [
    ['1','2','3'],
    ['4','5','6'],
    ['7','8','9']
]
    for row in range(0,3):
        for column in range(0,3):
            if board[row][column] == initial_board[row][column]:
                return False
            elif row == 2 and column == 2:
                return True
def play():
    player1,player2 = intro()
    game_over  = True
    while game_over:


        if player_one(player1):
            if check_for_draw():
                print("Game is a draw")
                break
            pass
        else:
            show_board()
            print(f"{player1} has won the game")
            break


        if  player_two(player2):
            if check_for_draw():
                print("Game is a draw")
                break
            pass
        else:
            show_board()
            print(f"{player2} has won the game")
            break
        




play()
input("Stop xD: ")


