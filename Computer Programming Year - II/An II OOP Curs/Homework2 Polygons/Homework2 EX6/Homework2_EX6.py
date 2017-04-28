from General import *
import os

if __name__ == "__main__": #Main function
    speed(9)   #turtle speed
    pOn = True   #application switch
    gen = General()   #instance of general class
    gen.DrawContainer(200)   # draw container on screen

    # Homework requests
    while(pOn):
        #Interface of program
        os.system("cls")
        print("\n\n\t\t Tema 2")
        print("1) Adaugarea si stergerea unor poligoane din container") #Done
        print("2) Afisarea poligoanelor din container") #Done
        print("3) Afisarea ariilor si perimetrelor poligoanelor") #Done
        print("4) Aplicarea unei operatii afine asupra unui poligon") 
        print("5) Determinarea si afisarea poligonului (poligoanelor) de perimetru minim") #Done
        print("6) Determinarea claselor de echivalenta pentru fiecare tip de poligon")
        print("7) Afisarea, pentru fiecare tip de poligon, a numarului de clase de echivalenta")
        print("8) Sortarea poligoanelor, pentru fiecare tip de poligon, in ordinea crescatoare a perimetrului acestora") #Done

        option = input("Insert option : ")

        if(option == "1"): #Add / delete section
            op2 = input("add / delete (x to go back) : ")
            if(op2 == "add"):
                op3 = input("What to add (segment, triunghi, patrat, pentagon, hexagon) : ")

                for i in range(len(gen.itemsInContainer)):
                    if(gen.itemsInContainer[i].polygonName == op3):
                        print("Poligonul deja exista")
                        op3 = "x"

                if(op3 == "segment"):
                    marime = int(input("Marimea laturei : "))
                    gen.SegmentX(marime)
                elif(op3 == "triunghi"):
                    marime = int(input("Marimea laturei : "))
                    gen.TriunghiX(marime)
                elif(op3 == "patrat"):
                    marime = int(input("Marimea laturei : "))
                    gen.PatratX(marime)
                elif(op3 == "pentagon"):
                    marime = int(input("Marimea laturei : "))
                    gen.PentagonX(marime)
                elif(op3 == "hexagon"):
                    marime = int(input("Marimea laturei : "))
                    gen.HexagonX(marime)
                else:
                    print("Wrong option")
                    os.system("pause")
            elif(op2 == "delete"):
                op3 = input("What to delete (segment, triunghi, patrat, pentagon, hexagon) : ")
                if(op3 == "segment"):
                    gen.DrawPolygons("white", op3)
                    gen.DeleteFromContainer(op3)                           
                elif(op3 == "triunghi"):
                    gen.DrawPolygons("white", op3)
                    gen.DeleteFromContainer(op3)
                elif(op3 == "patrat"):
                    gen.DrawPolygons("white", op3)
                    gen.DeleteFromContainer(op3)
                elif(op3 == "pentagon"):
                    gen.DrawPolygons("white", op3)
                    gen.DeleteFromContainer(op3)
                elif(op3 == "hexagon"):
                    gen.DrawPolygons("white", op3)
                    gen.DeleteFromContainer(op3)
                else:
                    print("Wrong option")
                    os.system("pause")
            else:
                print("Wrong option")
                os.system("pause")
            
        elif(option == "2"): #Print content of container
            os.system("cls")
            print("\n\n\t\tPolygons in container")
            gen.printPolygons()
            os.system("pause")
        elif(option == "3"): #Print content of container
            os.system("cls")
            print("\n\n\t\tPolygons in container")
            gen.printPolygons()
            os.system("pause")
        elif(option == "4"):
            os.system("pause")
        elif(option == "5"): #Print polygon with minim perimeter
            gen.GetMinimPerimeterPolygon()
            os.system("pause")
        elif(option == "6"):
            os.system("pause")
        elif(option == "7"):
            os.system("pause")
        elif(option == "8"):
            gen.SortPolygonsByPerimeter() #Sort polygons by perimeter
            os.system("pause")
        else:
            print("Wrong option")

    gen.DrawPolygons("white")


    