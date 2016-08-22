#include <iostream>

#define IMG_WIDTH 1023
#define IMG_HEIGHT 1025
#define PI 3.14159265359

std::pair<double, double> lanlon2xy(double lon, double lat)
{

	double x = (lon + 180) * (IMG_WIDTH / 360.0);

	double latRadians = lat * PI / 180.0;
	double Mercator = std::log(std::tan((PI / 4.0) + (latRadians / 2.0)));
	double y = (IMG_HEIGHT / 2.0) - (IMG_WIDTH * Mercator / (2.0 * PI));

	return std::make_pair(x, y);
}
void main()
{
	std::pair<double, double> xy = lanlon2xy(115.25, 39.26);
	std::cout << xy.first << "\n" << xy.second;
	getchar();
}
