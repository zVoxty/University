#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class point {
public:
	point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	int x;
	int y;
};

class polygon {
public:
	virtual int perimeter() {
		int perim = 0;
		for (int i = 0; i < points.size()-1; i++) {
			perim = getDistance(points[i], points[i + 1]);
		}
		return perim;
	}
	double getDistance(point p1, point p2) {
		return sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
	}
	vector<point> points;
};

class triangle : public polygon {
public:
	triangle(int x0, int x1, int y0, int y1, int z0, int z1) {
		point p1(x0, x1);
		point p2(y0, y1);
		point p3(z0, z1);
		points.push_back(p1);
		points.push_back(p2);
		points.push_back(p3);
	}
	int perimeter() {
		return (getDistance(points[0], points[1]) + getDistance(points[1], points[2]) + getDistance(points[2], points[0]));
	}
};


void main() {
	polygon *polygons[10];
	polygons[0] = new triangle(0,0,0,1,1,0);
	cout << polygons[0]->perimeter();

	//etc...
	cout << endl;
	system("PAUSE");
}