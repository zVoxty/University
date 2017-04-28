from turtle import *
from operator import itemgetter
from math import *

def length(v):
    return sqrt(v[0]**2+v[1]**2)

def dot_product(v,w):
   return v[0]*w[0]+v[1]*w[1]

def determinant(v,w):
   return v[0]*w[1]-v[1]*w[0]

def inner_angle(v,w):
   cosx=dot_product(v,w)/(length(v)*length(w))
   rad=acos(cosx) # in radians
   return rad*180/pi # returns degrees

def angle_clockwise(A, B):
    inner=inner_angle(A,B)
    det = determinant(A,B)
    if det<0: #this is a property of the det. If the det < 0 then B is clockwise of A
        return inner
    else: # if the det > 0 then A is immediately clockwise of B
        return 360-inner

# Get rectangle coords
def GetRectangleOfPolygon(polygon):
    polygon.sort()  # Sort polygon coords by x
    xMin = polygon[0][0]  # Get xMin = first element
    xMax = polygon[len(polygon) - 1][0]  # Get xMax = last element

    polygon.sort(key=lambda x: x[1])  # Sort polygon by Y coord

    yMin = polygon[0][1]  # Get yMin from first point
    yMax = polygon[len(polygon) - 1][1]  # Get yMax from last point

    rectangle = [[xMin, yMin], [xMax, yMin], [xMax, yMax], [xMin, yMax]]  # Set rectangle points

    return rectangle  # return rectangle


# Function used to get area of a polygon with n points
def GetArea(polygon):
    area = 0
    for i in range(len(polygon) - 1):
        area += polygon[i][0] * polygon[i + 1][1] - polygon[i + 1][0] * polygon[i][1]
    return fabs(area / 2)


# Function used to get the distance between two points
def GetDistance(point1, point2):
    return sqrt((point2[0] - point1[0]) ** 2 + (point2[1] - point1[1]) ** 2)


# Function used to get the perimeter of a polygon
def GetPolygonPerimeter(polygon):
    perimeter = 0
    for i in range(len(polygon) - 1):
        perimeter += GetDistance(polygon[i],
                                 polygon[i + 1])  # Get distance between point 1 and point 2 and add to perimeter

    return perimeter


def GetInfo(polygon):
    numberOfPoints = int(input("Insert number of points : "))
    for i in range(numberOfPoints):
        print("Point ", i + 1, ":")
        X = int(input("Insert X:"))
        Y = int(input("Insert Y:"))
        point = [X, Y]
        polygon.append(point)


# Display graphic polygon using turtle library
def DisplayPolygon(polygon):
    pu()
    for i in range(len(polygon) - 1):
        goto(polygon[i][0] * 20, polygon[i][1] * 20)
        pd()
        dot()

    goto(polygon[0][0] * 20, polygon[0][1] * 20)


# Function used to get gravity center of polygon
def GetGravityCenter(polygon):
    x = 0
    y = 0
    for i in range(len(polygon)):
        x += polygon[i][0]
        y += polygon[i][1]

    x /= len(polygon)
    y /= len(polygon)

    return [x, y]


# Print polygon points on screen
def PrintPolygon(polygon):
    for i in range(len(polygon)):
        print("Point ", i + 1, ":", polygon[i])


# Function used to compare area of two polygons
def ComparePolygons(polygon1, polygon2):
    p1Area = GetArea(polygon1)
    p2Area = GetArea(polygon2)

    if (p1Area > p2Area):
        return "Aria poligonului mai mare decat cea a dreptunghiului"
    else:
        return "Aria dreptunghiului mai mare decat cea a poligonului"

def checkConvexity(polygon):
    angles = []

    if(len(polygon) < 4):
        return True

    for i in range(len(polygon)-1):
        angles.append(int(angle_clockwise(polygon[i], polygon[i+1])))

    convex = True

    for i in range(len(angles)):
        if(angles[i] < 180):
            convex = False

    print(angles)

    if(convex == True):
        return True
    else:
        return False
# Function used to print X and Y axes graphic using turtle
def printGraph():
    pu()
    goto(0, -200)
    lt(90)
    pd()
    fd(400)
    pu()
    goto(-200, 0)
    pd()
    rt(90)
    fd(400)
    goto(0, 0)