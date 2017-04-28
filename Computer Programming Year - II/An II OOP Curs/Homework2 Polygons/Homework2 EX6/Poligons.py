from Point import *
import os
class Polygon:

    points = []     #  list with polygons
    polygonName = ""    #name of polygon
    polygonArea = 0 #Polygon Area
    polygonPerimeter = 0 #Polygon Perimeter

    def __lt__(self, other):    #__lt__ used to sort polygons
         return self.polygonPerimeter < other.polygonPerimeter



    

