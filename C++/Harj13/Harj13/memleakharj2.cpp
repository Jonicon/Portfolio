// Two classes Point and Triangle are given in this program.  
// Triangle consists of three epices (points) that are allocated 
// from the dynamic memory when Triangle object is constructed.
// That's why the triangle class has three pointers to Point objects.
// In th eprogram also the Triangle object is allocated from the dynamic 
// memory. 
// The program has been designed for test purposes and it is possible to 
// cause an exception when the Point constructor is executed N:th time.
// In the beginning N is 4. It means that no exception happens and all three 
// points become fully constructed.

#include <iostream>
using namespace std;

// The exception is caused when the Point constructor is executed N:th time
#define N 3

//Class definition for Point
class Point {
	friend ostream& operator<<(ostream &out, const Point &point);
	public:
		Point(float x0 = 0.0, float y0 = 0.0);
		Point(const Point &p0);
		~Point();
        static int count;
	private:
		float x;
		float y;
};
int Point::count = 0;
class Triangle {
	friend ostream &operator<<(ostream & out, const Triangle &triangle);
	public:
		Triangle(float x1, float y1, float x2, float y2, float x3, float y3);
		~Triangle();
   private:
		Point *apex1;
		Point *apex2;
		Point *apex3;
};

//Definition for exception class
class Exception {
	public:
		Exception(const char *explanation0) {explanation = explanation0;}
		const char *what() const {return explanation;}
	private:
		const char *explanation;
};

//Main function
int main (void) {
	try {
        Triangle *p;
		p = new Triangle(1.0, 1.0, 2.0, 2.0, 3.0, 3.0);
		cout <<  *p;
        //throw Exception ("Exception after Triangle has been created");		
        delete p;
	}
	catch (Exception e) {
		cout << "Exception explanation is: " << e.what() << endl;
        cout << "Exception is managed now" << endl;
	}
    //cout << "Constructor for point is executed " << Point::count << " times" << endl;
	system("pause");
	return 0;
}

//-----------------------------------------------------------------
//Implementation of class Point
Point:: Point(float x0, float y0): x(x0), y(y0) {
    if (count >= N)
        throw Exception ("Does not succeed to create the last apex");
    cout << "Point constructor is done " << (void*)this << endl;
	count++;
}

Point::~Point() {
    cout << "\nDestructor for Point " << (void*)this << " : ("
            << x << "," << y << ")" << endl;
}
// Friend functions of Point
ostream &operator<<(ostream & out, const Point &point) {
	out << "(" << point.x << "," << point.y << ")";
	return out;
}
//-----------------------------------------------------------------
//Implementation of class Triangle
Triangle::Triangle(float x1, float y1, float x2, float y2, float x3, float y3) {
    apex1 = new Point(x1, y1);
    apex2 = new Point(x2, y2);
    apex3 = new Point(x3, y3);
    cout << "Triangle constructor is done " << (void*)this << endl;
}
Triangle::~Triangle() {
	cout <<  endl << "Destructor for Triangle " << (void*)this << endl;
    delete apex1;
    delete apex2;
    delete apex3;
	// cout << "Coming out of Triangle destructor" << endl;
}

// Friend functions of Triangle
ostream &operator<<(ostream & out, const Triangle &triangle) {
	out << "Triangle is : " ;
	out << *triangle.apex1 << " " << *triangle.apex2 << " " << *triangle.apex3 << endl;
	return out;
}

