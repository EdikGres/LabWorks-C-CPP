//
// Created by atlon on 13.09.2021.
//

#ifndef POINT_H
#define POINT_H

struct Point {
    int x;
    int y;
    int z;

    bool operator==(Point p) const {
        return (x == p.x && y == p.y && z == p.z);
    }

    bool operator!=(Point p) const {
        return (x != p.x || y != p.y || z != p.z);
    }

    bool operator>(Point p) const {
        double a1 = sqrt(x * x + y * y + z * z);
        double a2 = sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
        return a1 > a2;
    }

    bool operator<(Point p) const {
        double a1 = sqrt(x * x + y * y + z * z);
        double a2 = sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
        return a1 < a2;
    }

    Point &operator=(Point p) {
        x = p.x;
        y = p.y;
        z = p.z;
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &out, const Point p) {
        out << "(" << p.x << "," << p.y << "," << p.z << ")";
        return out;
    }
};


#endif //POINT_H
