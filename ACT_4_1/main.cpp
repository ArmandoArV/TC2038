#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x, y;
};

// Función para verificar si un punto c está en el segmento ab
bool isOnSegment(const Point &a, const Point &b, const Point &c) {
    if (c.x >= min(a.x, b.x) && c.x <= max(a.x, b.x) &&
        c.y >= min(a.y, b.y) && c.y <= max(a.y, b.y)) {
        return true;
    }
    return false;
}


// Función para calcular el producto cruz de dos vectores (puntos)
int crossProduct(const Point &a, const Point &b, const Point &c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

// Función para verificar si dos segmentos de recta se intersectan
bool doSegmentsIntersect(const Point &p1, const Point &p2, const Point &p3, const Point &p4) {
    int d1 = crossProduct(p3, p4, p1);
    int d2 = crossProduct(p3, p4, p2);
    int d3 = crossProduct(p1, p2, p3);
    int d4 = crossProduct(p1, p2, p4);

    if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) &&
        ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0))) {
        return true;
    }

    if (d1 == 0 && isOnSegment(p3, p4, p1)) return true;
    if (d2 == 0 && isOnSegment(p3, p4, p2)) return true;
    if (d3 == 0 && isOnSegment(p1, p2, p3)) return true;
    if (d4 == 0 && isOnSegment(p1, p2, p4)) return true;

    return false;
}


int main() {
    int n;
    cout << "Ingrese el número de segmentos de recta: ";
    cin >> n;

    vector<bool> intersections;

    for (int i = 0; i < n; i++) {
        Point p1, p2, p3, p4;
        cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;

        bool intersect = doSegmentsIntersect(p1, p2, p3, p4);
        intersections.push_back(intersect);
    }

    for (bool intersect: intersections) {
        cout << (intersect ? "True" : "False") << std::endl;
    }

    return 0;
}
