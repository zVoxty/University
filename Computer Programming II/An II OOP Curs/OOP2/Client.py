from Card import *
import os

class Client:
    username = ""
    password = ""

    clientSession = True

    CardsOnAccount = []

    def RegisterClientAccount(self, username):
        self.username = username #Set username 
        self.password = input("Insert password : ") #Get password for user

    def RegisterAccountCard(self):  #This method is used to create a card for respective client

        newCard = Card() #Here create a instance of card

        print("\n\n\t\t Card registration")

        bank = input("Insert bank name (BCR, BRD)") #There are only two banks avaiable BCR, BRD

        if(bank == "BCR"): #If it's BCR

            CardName = input("Insert card name : ") #Then ask for cardName

            if(CardName == ""): #A cardName cannot be empty
                print("Cannot set empty card name !")
                return ""

            if(len(self.CardsOnAccount) != 0):  #If card already exist you cannot create another one
                for i in range(len(self.CardsOnAccount)):
                    if(self.CardsOnAccount[i].cardName == CardName):
                        print("Card already exist !")
                        return ""

            newCard.RegisterCard(CardName, bank, self.username)  #This method is used to set informations to card

            self.CardsOnAccount.append(newCard) #Then just append the card to the card list

            return bank #And return bank name to handle this operations

        elif(bank == "BRD"):
            CardName = input("Insert card name : ")

            if(CardName == ""):
                print("Cannot set empty card name")
                return ""

            if(len(self.CardsOnAccount) != 0):
                for i in range(len(self.CardsOnAccount)):
                    if(self.CardsOnAccount[i].cardName == CardName):
                        print("Card already exist !")
                        return ""

            newCard.RegisterCard(CardName, bank, self.username)
            self.CardsOnAccount.append(newCard)
            return bank

        else:
            print("This bank doesn't exist !")
        return True

    def CheckCards(self):
        #   Solutia aceasta de checkcards folosind o variabila owner in clasa card am folosit-o deoarece
        #de fiecare daca cand se creaza un card se creaza pentru toate obiectele de tipul Client adica lista CardsOnAccount este pentru toti clientii
        #nu am stiut cum sa rezolv aceasta problema.

        os.system("cls")
        print("\n\n\t\t Cards on account", self.username)
        cardsAcc = 0

        #Loop throught all cards and select only cards for this client
        for i in range(len(self.CardsOnAccount)):
                if(self.CardsOnAccount[i].owner == self.username):
                    cardsAcc += 1

        if(len(self.CardsOnAccount) == 0 or cardsAcc == 0): #If there is no cards 
            print("No cards")
            os.system("pause")
        else: 
            for i in range(len(self.CardsOnAccount)):  #Print cards for respective client
                if(self.CardsOnAccount[i].owner == self.username):
                    print(self.CardsOnAccount[i].cardName, "-","Bank :",self.CardsOnAccount[i].Bank, self.CardsOnAccount[i].moneyOnCard,"$")
            os.system("pause")

    def CloseCard(self): #This method is used to close a card for respective client
        print("\n\n\t\t Close card on account", self.username)
 
        cardName = input("Insert card name : ") #Ask for card name
        for i in range(len(self.CardsOnAccount)): #Loop throught all cards and select respective card
            if(self.CardsOnAccount[i].owner == self.username):  #Check if its owner card
                if(self.CardsOnAccount[i].cardName == cardName): #Check for cardName
                    pin = input("Insert pin : ")  #Request pin
                    if(pin != self.CardsOnAccount[i].cardPin): #Verify the pin
                        print("Pin don't match")
                        os.system("pause")
                        return False

                    print("Card",self.CardsOnAccount[i].cardName, "removed") #If all good then remove the card
                    self.CardsOnAccount.remove(self.CardsOnAccount[i]) #Remove the card
                    return True #Return succesfully
        return False      
        
    def DepositToCard(self):
        print("\n\n\t\t Deposit to card account", self.username)
 
        cardName = input("Insert card name : ") #Ask for cardName
        for i in range(len(self.CardsOnAccount)): #Loop throught all cards and select respective card
            if(self.CardsOnAccount[i].owner == self.username): #Check if its owner card
                if(self.CardsOnAccount[i].cardName == cardName): #Check for cardName
                    pin = input("Insert pin : ") #Request pin
                    if(pin != self.CardsOnAccount[i].cardPin): #Verify the pin
                        print("Pin don't match")
                        os.system("pause")
                        return False

                    moneyToDeposit = int(input("Insert sum of money to deposit : ")) #Ask for sum of money

                    if(moneyToDeposit < 0): #Cannot deposit negative numbers
                        print("Can't deposit negative numbers")
                        return False

                    self.CardsOnAccount[i].moneyOnCard += moneyToDeposit #Add to respective card sum of money

                    print("Money on card",self.CardsOnAccount[i].cardName,"-",self.CardsOnAccount[i].moneyOnCard) #Print money on card

                    os.system("pause")
                    return True
        return False  

    def Withdraw(self):
        print("\n\n\t\t Withdraw from card account", self.username)
 
        cardName = input("Insert card name : ") #Ask for cardName
        for i in range(len(self.CardsOnAccount)): #Loop throught all cards and select respective card
            if(self.CardsOnAccount[i].owner == self.username): #Check if its owner card
                if(self.CardsOnAccount[i].cardName == cardName): #Check for cardName
                    pin = input("Insert pin : ") #Request pin
                    if(pin != self.CardsOnAccount[i].cardPin): #Verify the pin
                        print("Pin don't match")
                        os.system("pause")
                        return False

                    moneyToWithdraw = int(input("Insert sum of money to withdraw : ")) #Ask how much money to withdraw

                    if(moneyToWithdraw < 0): #Cannot withdraw negative numbers
                        print("Can't withdraw negative numbers")
                        return False

                    if(moneyToWithdraw > self.CardsOnAccount[i].moneyOnCard): #Cannot withdraw more than you have
                        print("Can't withdraw more than you have")
                        return False

                    self.CardsOnAccount[i].moneyOnCard -= moneyToWithdraw #Set new card money

                    print("Money on card",self.CardsOnAccount[i].cardName,"-",self.CardsOnAccount[i].moneyOnCard) #Print how much money card haves
                    os.system("pause")
                    return True 

    def Transfer(self):

        print("\n\n\t\t Transfer between cards")
        baseCard = input("Insert base card name : ")
        indexBaseCard = 9999

        #Same method request, check existence set index base card to i variable
        for i in range(len(self.CardsOnAccount)):
            if(self.CardsOnAccount[i].owner == self.username):
                if(self.CardsOnAccount[i].cardName == baseCard):
                    pin = input("Insert pin : ")
                    if(pin != self.CardsOnAccount[i].cardPin):
                        print("Pin don't match")
                        os.system("pause")
                        return False
                    indexBaseCard = i

         #Same method request, check existence set transfer index card to i variable
        transferCard = input("Insert insert where to transfer name : ")
        indexTransferCard = 9999
        for i in range(len(self.CardsOnAccount)):
            if(self.CardsOnAccount[i].owner == self.username):
                if(self.CardsOnAccount[i].cardName == transferCard):
                    pin = input("Insert pin : ")
                    if(pin != self.CardsOnAccount[i].cardPin):
                        print("Pin don't match")
                        os.system("pause")
                        return False
                    indexTransferCard = i
        
        if(indexBaseCard == 9999 or indexTransferCard == 9999): #Print cards doens't exist
            print("Problem with cards : Existence")
            os.system("pause")
            return False

        transferSum = int(input("How much to transfer : ")) #Get number of money to transfer

        if(transferSum > self.CardsOnAccount[indexBaseCard].moneyOnCard): #Check if user have enought to transfer
            print("No enought money to transfer !")
            os.system("pause")
            return False

        if(transferSum < 0): #Cannot transfer negative numbers
            print("Cannot transfer negative numbers !")
            os.system("pause")
            return False

        #Compute transfer
        self.CardsOnAccount[indexBaseCard].moneyOnCard -= transferSum 
        self.CardsOnAccount[indexTransferCard].moneyOnCard += transferSum
        print("Transfer succesfully")       
        os.system("pause")
        return True