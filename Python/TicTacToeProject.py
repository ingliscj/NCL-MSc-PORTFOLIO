#!/usr/bin/env python
# coding: utf-8

# In[ ]:


from IPython.display import clear_output
import random 

print('Welcome to Tic-Tac-Toe!')

board_floor = '----------'
test_board = ['X','O','X','O','X','O','X','O','X']
board = [' ']*9

# function that neatly displays dynamic game board
def display_board(board):
    clear_output()
    for i in board[6:8]:
        print(*i, end=" | ")
    print(board[8] + '\n' + board_floor)
    for i in board[3:5]:
        print(*i, end=" | ")
    print(board[5] + '\n' + board_floor)
    for i in board[0:2]:
        print(*i, end=" | ")
    print(board[2])

# function to recieve and store player's marker
def player_input():
    player1 = input('Player 1, do you want to be X or O: ')
    if player1 != 'X' and player1 != 'O':
        player1 = input('Please enter either X or O: ')
    if player1 == 'X':
        player2 = 'O'
        print('Player 2, you are O')
    else:
        player2 = 'X'
        print('Player 2, you are X')
    marker = (player1, player2)
    return marker
    
def place_marker(board, marker, position):
    board[position-1] = marker
    display_board(board)
    

def win_check(board, mark):
    if board[6] == board[7] == board[8] == mark:
        print('You won!')
        return True
    elif board[3] == board[4] == board[5] == mark:
        print('You won!')
        return True
    elif board[0] == board[1] == board[2] == mark:
        print('You won!')
        return True
    elif board[6] == board[4] == board[2] == mark:
        print('You won!')
        return True
    elif board[8] == board[4] == board[0] == mark:
        print('You won!')
        return True
    elif board[6] == board[3] == board[0] == mark:
        print('You won!')
        return True
    elif board[7] == board[4] == board[1] == mark:
        print('You won!')
        return True
    elif board[8] == board[5] == board[2] == mark:
        print('You won!')
        return True
    else:
        pass
    
# function that utilizes random module to decide who goes first
def choose_first():
    global a
    a = random.randint(0,1)
    if a == 0:
        return 'Player 1 goes first'
    else:
        a = 1
        return 'Player 2 goes first'

# function to ensure that player's choice position is not occupied    
def space_check(board, position):
    if board[position-1] == ' ':
        return True
    else:
        return False
    
# function to ensure that there are still spaces left on game board
def full_board_check(board):
    if ' ' in board:
        return False
    else:
        return True
        
        
def player_choice(board):
    choice = int(input('Player '+ str(int(a+1)) + ', please choose your position (1-9): '))
    return choice
    
def replay():
    answer = str(input('Would you like to play again? (Y/N): '))
    if answer == 'Y' or answer == 'Yes' or answer == 'y' or answer == 'yes':
        return True
    else:
        pass
    

# game loop starts here
while True:
    board = [' ']*9
    player_marker = player_input()
    choose_first()
    game_on = True
    pass
    
    while game_on:
        x = player_choice(board)
        if space_check(board, x):
            place_marker(board, player_marker[a], x)
        else:
            print('Please choose an unoccupied space...')
            continue
        if win_check(board, player_marker[a]):
            break
        if full_board_check(board):
            print('Game is a tie')
            game_on = False
        else:
            a = abs(a-1)
    
    if not replay():
        print('Thanks for playing!')
        break
    
   
    
    
    


# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:




