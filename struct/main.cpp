#include <iostream>
#include <math.h>
using namespace std;

struct Point {
	double x;
	double y;
};


double findDistance(const Point& p1, const Point& p2) {
	double new_x = p2.x - p1.x;
	double new_y = p2.y - p1.y;

	return pow((new_x * new_x + new_y * new_y), 0.5);
}
int main() {
	double input_x; cout << "Enter a coord x for first point:"; cin >> input_x;
	double input_y; cout << "Enter a coord y for first point:"; cin >> input_y;

	Point first_point = { input_x, input_y };

	cout << "Enter a coord x for second point:"; cin >> input_x;
	cout << "Enter a coord y for second point:"; cin >> input_y;

	Point second_point = { input_x, input_y };

	double dist = findDistance(first_point, second_point);

	cout << "\nDistance between this two points equals:" << dist << endl;
	
	return 0;
}