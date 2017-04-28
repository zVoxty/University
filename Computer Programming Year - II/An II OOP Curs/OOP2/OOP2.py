from GeneralBank import * #import GeneralBank - a core for our project 
import os #import "os" for : system("pause") - pause the program in this point, system("cls") - clear screen

if __name__ == "__main__":

    generalBank = GeneralBank()  #in generalBank we create a instance of General bank

    while(generalBank.aplicationOn):  #generalBank contain a variable to handle the python window application

        os.system("cls")   
        generalBank.Refresh() #Method used to refresh client session from false to true 

        #Here start the main interface
        print("\n\n\t\t Main")
        print("1) Login")
        print("2) Register")
        print("3) Exit")
        option = input("\n Your option : ")

        #Then fetch the user input
        if(option == "1"):  #This option is the login menu option used to create a session for client to create/register/close cards ... etc.
            os.system("cls")
            print("\n\n\t\t Login form\n")
            username = input("Insert username : ")

            userIndex = generalBank.VerifyUsername(username)   #This methos is used to check if the inserted username exist in our clients list if no back to main

            if(userIndex != 9999): #Our VerifyUsername return the index of the user in list so if there are no users or user don't exist return '9999'
                #If username is inserted properly
                password = input("Insert password : ") #Catch the password
                if(generalBank.VerifyPassword(userIndex,password)): #Verify the passord
                    while(generalBank.Accounts[userIndex].clientSession): #If password properly inserted start client session
                        os.system("cls")
                        #Print Clinet session interface
                        print("\n\t\t User interface ")
                        print("1) Register card ")
                        print("2) Check cards ")
                        print("3) Close card ")
                        print("4) Deposit to card")
                        print("5) Withdraw from card")
                        print("6) Transfer between cards")
                        print("7) Exit")

                        option = input("Your option : ")

                        #Then fetch our input
                        if(option == "1"): #Option 1 used for register a new card for client
                            bank = generalBank.Accounts[userIndex].RegisterAccountCard() 
                            #Check return of RegisterAccountCard method
                            if(bank != ""):
                                print("Registration card succesfully to bank",bank)
                                os.system("pause")
                            else:
                                print("Problem with card registration try later")
                                os.system("pause")

                        elif(option == "2"): #Option 2 used to show all client cards
                            generalBank.Accounts[userIndex].CheckCards()

                        elif(option == "3"): #Option 3 used to close a card for this client
                            if(generalBank.Accounts[userIndex].CloseCard()): #If close card method return succesfull                        
                                print("Card closed succesfully")
                                os.system("pause")
                            else:
                                print("Card doens't exist !")
                                os.system("pause")

                        elif(option == "4"): #Option 4 used to deposit on a specified clien card
                            if(generalBank.Accounts[userIndex].DepositToCard()):
                                print("Deposit succesfully and refreshed account")
                                os.system("pause")
                            else:
                                print("Problem to deposit !")
                                os.system("pause")

                        elif(option == "5"): #Option 5 used to withdraw money on a specified client card
                            if(generalBank.Accounts[userIndex].Withdraw()):
                                print("Withdraw succesfully and refreshed account")
                                os.system("pause")
                            else:
                                print("Problem to withdraw !")
                                os.system("pause")

                        elif(option == "6"): #Option 6 used to transfer money between cards
                            if(generalBank.Accounts[userIndex].Transfer()):                               
                                print("Transfer succesfully and refreshed account")
                                os.system("pause")
                            else:
                                print("Problem to transfer try again later !")
                                os.system("pause")

                        elif(option == "7"): #Exit from client session
                            generalBank.Accounts[userIndex].clientSession = False
                        else:
                            print("Wrong choice")
                else:
                    print("Password don't match !")
                    os.system("pause")
            else:
                print("Username don't exist !")
                os.system("pause")

        elif(option == "2"): #Option used to register a client account
            if(generalBank.RegisterAccount()):
                print("Registration succesfull")
                os.system("pause")
            else:
                print("Registration problem")
                os.system("pause")
        elif(option == "3"): #Exit application
            generalBank.aplicationOn = False
        else:
            print("Wrong option")