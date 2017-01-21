import os

class Card:
    cardName = ""
    cardPin = ""
    Bank = ""
    ower = ""
    moneyOnCard = 0
    
    def RegisterCard(self, cardName, bank, ownerx):
        self.cardName = cardName
        self.Bank = bank
        self.owner = ownerx
        self.cardPin = input("Insert password : ")

    

