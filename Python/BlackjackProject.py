#!/usr/bin/env python
# coding: utf-8

# In[ ]:


from IPython.display import clear_output
import random

suits = ['Diamonds', 'Hearts', 'Clubs', 'Spades']
ranks = ['Two','Three','Four','Five','Six','Seven','Eight','Nine','Ten','Jack'
        ,'Queen','King','Ace']
values = {'Two':2, 'Three':3, 'Four':4, 'Five':5, 'Six':6, 'Seven':7, 'Eight':8
          , 'Nine':9, 'Ten':10, 'Jack':10, 'Queen':10, 'King':10, 'Ace':11}


class Card:
    
    def __init__(self,suit,rank):
        self.suit = suit
        self.rank = rank
        
    def __str__(self):
        return f"{self.rank} of {self.suit}"

              
class Deck:
    
    def __init__(self):
        self.deck = []
        for suit in suits:
            for rank in ranks:
                self.deck.append(Card(suit,rank))
                
    def __str__(self):
        print(len(self.deck))
        deck_update = ''
        for card in self.deck:
            deck_update += '\n' + card.__str__() 
        return 'Deck contains: ' + deck_update
        
    def shuffle(self):
        random.shuffle(self.deck)
            
    def deal(self):
        single_card = self.deck.pop()
        return single_card
            
class Hand:
    
    def __init__(self):
        self.cards = []
        self.value = 0
        self.aces = 0
        
    def add_card(self,card):
        self.cards.append(card)
        self.value += values[card.rank]
        if card.rank == 'Ace':
            self.aces += 1
        
        
    def ace_adjust(self):
        while self.value > 21 and self.aces:
            self.value -= 10
            self.aces -= 1
            
class Chips:
    
    def __init__(self):
        self.bank = 500
        self.bet = 0
        
    def win_bet(self):
        self.bank += self.bet
        
    def lose_bet(self):
        self.bank -= self.bet

def choose_bet(chips):
    
    while True:
        try:
            chips.bet = int(input('Place your bet: '))
        except ValueError:
            print('Please input a valid number of chips!')
        else:
            if chips.bet > chips.bank:
                print('Sorry your bet cannot exceed: ', chips.bank)
            else:
                break
                
def hit(deck,hand):
    hand.add_card(deck.deal())
    hand.ace_adjust()
    
def hit_or_stand(deck,hand):
    global playing
    
    while True:
        x = input('Would you like to hit or stand? Please enter "h" or "s": ')
        
        if x[0].lower() == 'h':
            hit(deck,hand)
        elif x[0].lower() == 's':
            print('Player is standing. Dealer is playing')
            playing = False
        else:
            print('Please enter a valid input!')
            continue
        break

# Displays player's initial cards and one of the dealer's
def show_some(player,dealer):
    clear_output()
    print("\nDealer's Hand: ")
    print(" <card hidden>")
    print("",dealer.cards[1])
    print(" Dealer's Hand Value: ", values[dealer.cards[1].rank])
    print("-"*20)
    print("\nPlayer's Hand: ", *player.cards, sep='\n ')
    print(" Player's Hand Value: ", player.value)
    print("-"*20)

# Displays full hands of dealer and player
def show_all(player,dealer):
    clear_output()
    print("\nDealer's Hand: ", *dealer.cards, sep='\n ')
    print("\nDealer's Hand Value: ", dealer.value)
    print("-"*20)
    print("\nPlayer's Hand: ", *player.cards, sep='\n ')
    print("\nPlayer's Hand Value: ", player.value)
    print("-"*20)
            
def player_busts(player,dealer,chips):
    print("Player busts!")
    chips.lose_bet()

def player_wins(player,dealer,chips):
    print("Player wins!")
    chips.win_bet()

def dealer_busts(player,dealer,chips):
    print("Dealer busts!")
    chips.win_bet()
    
def dealer_wins(player,dealer,chips):
    print("Dealer wins!")
    chips.lose_bet()
    
def push(player,dealer):
    print("Dealer and Player tie! It's a push.")

              
        
        
#GAME

while True:
    print('Welcome to Blackjack! Dealer hits until 17 or higher. Enjoy!')
    
    # Initialize deck, shuffle it, and create player/dealer hands
    deck = Deck()
    deck.shuffle()
    
    player_hand = Hand()
    player_hand.add_card(deck.deal())
    player_hand.add_card(deck.deal())
    
    dealer_hand = Hand()
    dealer_hand.add_card(deck.deal())
    dealer_hand.add_card(deck.deal())
    
    # Set up player's chips, adjust for previous winnings & take bet
    player_chips = Chips()
    print('Your starting bank is: ' + str(player_chips.bank) + ' chips')
    choose_bet(player_chips)

    # Display first round of cards
    show_some(player_hand, dealer_hand)
    
    # Set boolean to control flow of loop
    playing = True
    while playing:
        hit_or_stand(deck, player_hand)
        show_some(player_hand, dealer_hand)
        if player_hand.value > 21:
            player_busts(player_hand, dealer_hand, player_chips)
            break
    if player_hand.value <= 21:
        while dealer_hand.value < 17:
            hit(deck, dealer_hand)
        
        show_all(player_hand, dealer_hand)
        
        if dealer_hand.value > 21:
            dealer_busts(player_hand, dealer_hand, player_chips)
        elif dealer_hand.value > player_hand.value:
            dealer_wins(player_hand, dealer_hand, player_chips)
        elif dealer_hand.value < player_hand.value:
            player_wins(player_hand, dealer_hand, player_chips)
        else:
            push(player_hand, dealer_hand)
            
    print("Player's winnings stand at: ", player_chips.bank)
    
    playing = int(input("Would you like to play another hand? Enter '1' if you would, and '0' if you're done!"))
    if playing:
        clear_output()
        continue
    else:
        clear_output()
        print('Thanks for playing!')
        break 


# In[ ]:





# In[ ]:





# In[ ]:




