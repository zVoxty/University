from Client import *

class GeneralBank:
    Accounts = []

    aplicationOn = True

    def RegisterAccount(self):   
        newClient = Client() #Create a instance of client class
        print("\n\n\t\t Account registration")

        rUsername = input("Insert username : ") #Get userName

        if(rUsername == ""): #Username cannot be empty
            print("Cannot set empty username")
            return False;

        if(len(self.Accounts) != 0): #Check if username exist
            for i in range(len(self.Accounts)):
                if(self.Accounts[i].username == rUsername):
                    print("Username already exist !")
                    return False;

        newClient.RegisterClientAccount(rUsername) #Send username to client to get other informations

        self.Accounts.append(newClient) #Add the client to accounts list
        return True

    def VerifyUsername(self, uname):
        for i in range(len(self.Accounts)):
            if(self.Accounts[i].username == uname):
                return i
        return 9999

    def VerifyPassword(self, index, uPass):
        if(self.Accounts[index].password == uPass):
            return True
        return False

    def Refresh(self):
        for i in range(len(self.Accounts)):
            self.Accounts[i].clientSession = True

    def RevAccounts(self):
        accounts = len(self.Accounts)

        if(accounts == 0):
            print("No accounts registered !")
        else:
            for i in range(accounts):
                print(self.Accounts[i].username, self.Accounts[i].password)
    