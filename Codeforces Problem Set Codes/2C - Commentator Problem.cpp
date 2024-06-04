#include <bits/stdc++.h>
#define square(a) ((a)*(a))
using namespace std;

double dx, dy, stadiums_x[3], stadiums_y[3], radii[3], distances[3];

double calculateObjective(double dx, double dy) {
	double result = 0;
	for(int i = 0; i < 3; i++)
		distances[i] = sqrt(square(dx - stadiums_x[i]) + square(dy - stadiums_y[i])) / radii[i];
	for(int i = 0; i < 3; i++)
		result += square(distances[i] - distances[(i + 1) % 3]);
	return result;
}

int main() {
	for(int i = 0; i < 3; i++)
		scanf("%lf%lf%lf", &stadiums_x[i], &stadiums_y[i], &radii[i]);
	for(int i = 0; i < 3; i++)
		dx += stadiums_x[i] / 3, dy += stadiums_y[i] / 3;
	for(double step = 1; step > 1e-6;) {
		if (calculateObjective(dx, dy) > calculateObjective(dx + step, dy)) dx += step;
		else if (calculateObjective(dx, dy) > calculateObjective(dx - step, dy)) dx -= step;
		else if (calculateObjective(dx, dy) > calculateObjective(dx, dy + step)) dy += step;
		else if (calculateObjective(dx, dy) > calculateObjective(dx, dy - step)) dy -= step;
		else step *= 0.7;
	}
	if (calculateObjective(dx, dy) < 1e-5)
		printf("%.5lf %.5lf\n", dx, dy);
	return 0;
}
