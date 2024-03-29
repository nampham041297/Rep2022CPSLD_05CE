/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.05
 */

#include <iostream>
#include <functional>

using namespace std;
// hàm đọc dữ liệu đầu vào
void getInputData(double& length, double& width, double& height) {
	cout << "Nhap chieu dai, rong, cao: ";
	cin >> length >> width >> height;
}
// hàm tính diện tích xung quanh trừ hai đáy
double surroundingArea(double length, double width, double height) {
	return 4 * height * (length + width);
}
// hàm tính diện tích toàn phần
double totalArea(double length, double width, double height) {
	return 8 * (length + width + height);
}
// hàm tính thể tích
double volume(double length, double width, double height) {
	return length * width * height;
}
// hàm hiện kết quả
void showResult(double a, double b, double c,
	function<double(double, double, double)> calculate) {
	cout << calculate(a, b, c) << endl;
}

int main() {
	double length; // chiều dài
	double width; // chiều rộng
	double height; // chiều cao

	getInputData(length, width, height);
	if (length >= 0 && width >= 0 && height >= 0) {
		function<double(double, double, double)> calculate;
		calculate = surroundingArea;
		cout << "Dien tich xung quanh hop = ";
		showResult(length, width, height, calculate);

		calculate = totalArea;
		cout << "Dien tich toan phan hinh hop = ";
		showResult(length, width, height, calculate);

		calculate = volume;
		cout << "The tich hinh hop = ";
		showResult(length, width, height, calculate);
	}
	else {
		cout << "Nhap cac canh > 0" << endl;
	}

	return 0;
}