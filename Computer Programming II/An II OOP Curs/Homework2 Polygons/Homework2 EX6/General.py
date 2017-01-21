from Poligons import *
from math import *
from turtle import *
from Point import *
import random

class General:

    itemsInContainer = []   #list which contain type of polygons

    #Just draw container turtle commands
    def DrawContainer(self,marimeContainer):
        pu()
        goto(-marimeContainer, marimeContainer)
        pd()
        goto(-marimeContainer, -marimeContainer)
        goto(marimeContainer, -marimeContainer)
        goto(marimeContainer, marimeContainer)
        pu()
        goto(0,0)

    #Get are of a polygon
    def GetArea(self, polygon):
        area = 0
        for i in range(len(polygon.points) - 1):
            area += (polygon.points[i].xCoord/10) * (polygon.points[i + 1].yCoord/10) - (polygon.points[i + 1].xCoord/10) * (polygon.points[i].yCoord/10)
        return fabs(area / 2)

    def func(self):
        return self.itemsInContainer[0].polygonPerimeter < self.itemsInContainer[1].polygonPerimeter
    
    #Sort polygons by perimeter
    def SortPolygonsByPerimeter(self):
        print("Polygons before sort by perimeter")
        self.printPolygons()
        print("\n")
        self.itemsInContainer.sort()

        print("Polygons after sort by perimeter")
        self.printPolygons()

    #From list of polygons get the polygon with minim perimeter
    def GetMinimPerimeterPolygon(self):
        min= 9999
        for i in range (len(self.itemsInContainer)):
            if(self.itemsInContainer[i].polygonPerimeter < min):
                min = self.itemsInContainer[i].polygonPerimeter
        for i in range (len(self.itemsInContainer)):
            if(self.itemsInContainer[i].polygonPerimeter == min):
                print("Poligonul cu perimetru minim este",self.itemsInContainer[i].polygonName,"cu perimetrul",self.itemsInContainer[i].polygonPerimeter)

     #delete a polygon from container
    def DeleteFromContainer(self, polyName):
        for i in range (len(self.itemsInContainer)):
            if(self.itemsInContainer[i].polygonName == polyName):
                self.itemsInContainer.remove(self.itemsInContainer[i])
                break
    
    #show polygons in console
    def printPolygons(self):
        for i in range(len(self.itemsInContainer)):
            print(self.itemsInContainer[i].polygonName,",Aria :",self.itemsInContainer[i].polygonArea,",Perimetru :",self.itemsInContainer[i].polygonPerimeter)
    
    #Turtle # Draw a polygon
    def DrawPolygons(self, color, pName):

        pencolor(color)
        for i in range(len(self.itemsInContainer)):
            if(self.itemsInContainer[i].polygonName == pName):
                for j in range(len(self.itemsInContainer[i].points)):
                    if(self.itemsInContainer[i].points[j].pOwner == pName):
                        if(j == 0):
                            pu()
                            goto(self.itemsInContainer[i].points[j].xCoord, self.itemsInContainer[i].points[j].yCoord)
                        else:
                            pd()
                            goto(self.itemsInContainer[i].points[j].xCoord, self.itemsInContainer[i].points[j].yCoord)
                break
            pu()
            goto(0,0)
    
     #Create polygon
    def CreatePolygon(self, n, side_length):
        pencolor("black")
        pu()
        goto(random.randint(-100,100), random.randint(-100,100)) #go to random position in container
        pd()

        #start tracking turtle pen
        begin_poly()
        for i in range(n):
            left(360/n)
            forward(side_length)
        end_poly() #stop tracking
        polygonX = get_poly() #put all coords in a list
        pu()
        goto(0,0)
        return polygonX #return the list with points

    #Create a segment
    def SegmentX(self, marime):
        poly = self.CreatePolygon(1, marime)  #create segment
        marime = int(marime/10) #reduce the size  
        polygonC = Polygon() #create an instance of polygon
        polygonC.polygonName = "segment" #set name
        polygonC.polygonArea = 0 #set area
        polygonC.polygonPerimeter = marime * 1 #set perimeter

        Point1 = Point(poly[0][0], poly[0][1]) #setpoint 1
        Point1.pOwner = polygonC.polygonName 

        Point2 = Point(poly[1][0], poly[1][1]) #setpoint 2
        Point2.pOwner = polygonC.polygonName

        polygonC.points.append(Point1) #append point to polygon
        polygonC.points.append(Point2) #append point to polygon
        self.itemsInContainer.append(polygonC) #append polygon to container 
    
    #Create triangle same method as segment
    def TriunghiX(self, marime):
        
        poly = self.CreatePolygon(3, marime)
        marime = int(marime/10)
        polygonC = Polygon()

        polygonC.polygonName = "triunghi"
        polygonC.polygonPerimeter = marime * 3

        Point1 = Point(poly[0][0], poly[0][1])
        Point1.pOwner = polygonC.polygonName

        Point2 = Point(poly[1][0], poly[1][1])
        Point2.pOwner = polygonC.polygonName

        Point3 = Point(poly[2][0], poly[2][1])
        Point3.pOwner = polygonC.polygonName

        polygonC.points.append(Point1)
        polygonC.points.append(Point2)
        polygonC.points.append(Point3)
        polygonC.points.append(Point1)

        polygonC.polygonArea = int(self.GetArea(polygonC))
        self.itemsInContainer.append(polygonC) 
    
    #create square
    def PatratX(self, marime):
        
        poly = self.CreatePolygon(4, marime)
        marime = int(marime/10)
        polygonC = Polygon()

        polygonC.polygonName = "patrat"
        polygonC.polygonPerimeter = marime * 4

        Point1 = Point(poly[0][0], poly[0][1])
        Point1.pOwner = polygonC.polygonName

        Point2 = Point(poly[1][0], poly[1][1])
        Point2.pOwner = polygonC.polygonName

        Point3 = Point(poly[2][0], poly[2][1])
        Point3.pOwner = polygonC.polygonName

        Point4 = Point(poly[3][0], poly[3][1])
        Point4.pOwner = polygonC.polygonName

        polygonC.points.append(Point1)
        polygonC.points.append(Point2)
        polygonC.points.append(Point3)
        polygonC.points.append(Point4)
        polygonC.points.append(Point1)

        polygonC.polygonArea = int(self.GetArea(polygonC))

        self.itemsInContainer.append(polygonC)
    #create pentagon
    def PentagonX(self, marime):
   
        poly = self.CreatePolygon(5, marime)
        marime = int(marime/10)
        polygonC = Polygon()

        polygonC.polygonName = "pentagon"
        polygonC.polygonPerimeter = marime * 5

        Point1 = Point(poly[0][0], poly[0][1])
        Point1.pOwner = polygonC.polygonName

        Point2 = Point(poly[1][0], poly[1][1])
        Point2.pOwner = polygonC.polygonName

        Point3 = Point(poly[2][0], poly[2][1])
        Point3.pOwner = polygonC.polygonName

        Point4 = Point(poly[3][0], poly[3][1])
        Point4.pOwner = polygonC.polygonName

        Point5 = Point(poly[4][0], poly[4][1])
        Point5.pOwner = polygonC.polygonName

        polygonC.points.append(Point1)
        polygonC.points.append(Point2)
        polygonC.points.append(Point3)
        polygonC.points.append(Point4)
        polygonC.points.append(Point5)
        polygonC.points.append(Point1)

        polygonC.polygonArea = int(self.GetArea(polygonC))

        self.itemsInContainer.append(polygonC)
    #create hexagon
    def HexagonX(self, marime):       
        poly = self.CreatePolygon(6, marime)
        marime = int(marime/10)
        polygonC = Polygon()

        polygonC.polygonName = "hexagon"
        polygonC.polygonPerimeter = marime * 6

        Point1 = Point(poly[0][0], poly[0][1])
        Point1.pOwner = polygonC.polygonName

        Point2 = Point(poly[1][0], poly[1][1])
        Point2.pOwner = polygonC.polygonName

        Point3 = Point(poly[2][0], poly[2][1])
        Point3.pOwner = polygonC.polygonName

        Point4 = Point(poly[3][0], poly[3][1])
        Point4.pOwner = polygonC.polygonName

        Point5 = Point(poly[4][0], poly[4][1])
        Point5.pOwner = polygonC.polygonName

        Point6 = Point(poly[5][0], poly[5][1])
        Point6.pOwner = polygonC.polygonName

        polygonC.points.append(Point1)
        polygonC.points.append(Point2)
        polygonC.points.append(Point3)
        polygonC.points.append(Point4)
        polygonC.points.append(Point5)
        polygonC.points.append(Point6)
        polygonC.points.append(Point1)

        polygonC.polygonArea = int(self.GetArea(polygonC))

        self.itemsInContainer.append(polygonC)
