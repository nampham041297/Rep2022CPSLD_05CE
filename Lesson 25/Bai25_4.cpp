/*
 * @author Branium Academy
 * @version 2021.02
 * @website braniumacademy.net
 */

#define _USE_MATH_DEFINES
#include <iostream>

using namespace std;
// khai báo hàm nguyên mẫu
void getHeightAndRadius(double& height, double& radius);
double surroundingArea(double height = 1.0, double radius = 1.0);
double totalArea(double height = 1.0, double radius = 1.0);
double cylinderVolume(double height = 1.0, double radius = 1.0);
double volumeCylinderFitEarth();

int main() {
	double height, radius;
	getHeightAndRadius(height, radius);
	cout << "height = " << height << ", radius = " << radius << endl;
	cout << "=========================" << endl;
	// gọi hàm tính diện tích XQ với các bộ đối số khác nhau
	cout << "Dien tich XQ voi day du doi so: Sxq = "
		<< surroundingArea(height, radius) << endl;
	cout << "Dien tich XQ khuyet 1 doi so: Sxq = "
		<< surroundingArea(height) << endl;
	cout << "Dien tich XQ khuyet 2 doi so: Sxq = "
		<< surroundingArea() << endl;
	cout << "=========================" << endl;
	// gọi hàm tính diện tích toàn phần với các bộ đối số khác nhau
	cout << "Dien tich TP voi day du doi so: S = "
		<< totalArea(height, radius) << endl;
	cout << "Dien tich TP khuyet 1 doi so: S = "
		<< totalArea(height) << endl;
	cout << "Dien tich TP khuyet 2 doi so: S = " << totalArea() << endl;
	cout << "=========================" << endl;
	// gọi hàm tính thể tích với các bộ đối số khác nhau
	cout << "The tich tru voi day du doi so: V = "
		<< cylinderVolume(height, radius) << endl;
	cout << "The tich tru khuyet 1 doi so: V = "
		<< cylinderVolume(height) << endl;
	cout << "The tich tru khuyet 2 doi so: V = "
		<< cylinderVolume() << endl;
	cout << "=========================" << endl;
	cout << "The tich tru chua duoc Trai Dat: V = "
		<< volumeCylinderFitEarth() << "km3" << endl;

	return 0;
}

void getHeightAndRadius(double& height, double& radius) {
	cout << "Nhap vao chieu cao, ban kinh: ";
	cin >> height >> radius;
	// đảm bảo kích thước các chiều của hình hộp là hợp lệ
	radius = radius > 0 ? radius : 1;
	height = height > 0 ? height : 1;
}
// diện tích xung quanh
double surroundingArea(double height, double radius) {
	return 2 * M_PI * radius * height;
}
// diện tích toàn phần
double totalArea(double height, double radius) {
	return 2 * M_PI * radius * (height + radius);
}
// thể tích trụ
double cylinderVolume(double height, double radius) {
	return M_PI * radius * radius * height;
}
// để chứa vừa trái đất thì bán kính và chiều cao của trụ
// phải bằng bán kính trái đất
double volumeCylinderFitEarth() {
	auto earthRadius = 6371;
	return cylinderVolume(earthRadius, earthRadius);
}