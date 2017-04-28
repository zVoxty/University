from Functions import *
import os
from turtle import *

if __name__ == "__main__":

    #- Crearea poligonului
    polygon = [[1,1], [4, 4], [9,9],[2,10]]
    #GetInfo(polygon)
    print("Crearea Poligonului solved !\n")
    os.system("pause")

    #(***)Deoarece poligonul se intoarce in acelasi punct ultimul punct al poligonului va fi primul
    polygon.append(polygon[0])

    #- Afisarea poligonului
    PrintPolygon(polygon)
    print("Afisarea Poligonului solved !\n")
    printGraph()
    DisplayPolygon(polygon)
    os.system("pause")

    #- Determinarea dreptunghiului de arie minima care contine in interior poligonul;
    rectangle = GetRectangleOfPolygon(polygon)
    rectangle.append(rectangle[0]) # -> (***)
    DisplayPolygon(rectangle)
    PrintPolygon(rectangle)
    print("Determinarea dreptunghiului de arie minima care contine in interior poligonul solved !\n")
    os.system("pause")


    #- Determinarea ariei poligonului;
    print("Polygon area : ", GetArea(polygon))
    print("Determinarea ariei poligonului solved !\n")
    os.system("pause")

    #- Determinarea perimetrului poligonului;
    print("Polygon perimeter : ", GetPolygonPerimeter(polygon))
    print("Determinarea perimetrului poligonului solved !\n")
    os.system("pause")

    #- Determinarea centrului de greutate;
    print("Coordonatele centrului de greutate : ", GetGravityCenter(polygon))
    print("Determinarea centrului de greutate solved !\n")
    penup()
    gCenter = GetGravityCenter(polygon)
    goto(gCenter[0]*20,gCenter[1]*20)
    pendown()
    dot()
    os.system("pause")

    #- Determinarea daca poligonul este convex;
    print("Polygon convexity = ", checkConvexity(polygon))
    print("Polygon convexity solved ! \n")
    os.system("pause")

    #- Compararea poligoanelor in rapor cu aria lor;
    print(ComparePolygons(polygon, rectangle))
    print("Compararea poligoanelor in raport cu aria lor solved !\n")

    #- Concatenarea a doua poligoane; concatenarea a doua poligoane este intotdeauna un poligon convex
    #MISS