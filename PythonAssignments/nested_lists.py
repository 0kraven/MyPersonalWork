map = [['⬜️', '⬜️', '⬜️'],
       ['⬜️', '⬜️', '⬜️'],
       ['⬜️', '⬜️', '⬜️']]

for row in map:
    print(''.join(row))

position = input("Enter column and row (e.g., 31 for column 3, row 1): ")

column = int(position[0]) - 1  
row = int(position[1]) - 1   

map[row][column] = 'X'

for row in map:
    print(''.join(row))
