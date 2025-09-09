#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int Limits = 1024;


int points(float v) {
    int r = (int)lround(v);
    if (r < 0) r = 0;
    if (r >= Limits) r = Limits - 1;
    return r;
}

void Line_s(ofstream &out, float x1, float y1, float x2, float y2) {
    out << "(" << points(x1) << "," << points(y1) << ")"
        << "(" << points(x2) << "," << points(y2) << ")\n";
}


void draw(float x, float y, float angle_deg, float dist, float &nx, float &ny) {
    float rad = angle_deg * acos(-1.0f) / 180.0f;
    nx = x + dist * cos(rad);
    ny = y + dist * sin(rad);
}


void DrawKoch(int depth, float x, float y, float angle, float length, ofstream &out) {
    if (depth == 0) {
        float nx, ny;
        draw(x, y, angle, length, nx, ny);
        Line_s(out, x, y, nx, ny);
    } else {
        float seg = length / 3.0f;

        float x2, y2;
        draw(x, y, angle, seg, x2, y2);

        float x3, y3;
        draw(x2, y2, angle - 60.0f, seg, x3, y3);

        float x4, y4;
        draw(x3, y3, angle + 60.0f, seg, x4, y4);

        DrawKoch(depth - 1, x,  y,  angle,       seg, out);
        DrawKoch(depth - 1, x2, y2, angle - 60., seg, out);
        DrawKoch(depth - 1, x3, y3, angle + 60., seg, out);
        DrawKoch(depth - 1, x4, y4, angle,       seg, out);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 6) {
        cerr << "Uso:\n  " << argv[0] << " <x0> <y0> <angle> <length> <depth>\n";
        return 1;
    }

    float x0     = atof(argv[1]);
    float y0     = atof(argv[2]);
    float angle  = atof(argv[3]);
    float length = atof(argv[4]);
    int depth    = atoi(argv[5]);

    if (depth < 0 || depth > 10) {
        cerr << "depth debe estar entre 0 y 10\n";
        return 1;
    }

    ofstream out("lines.txt");
    if (!out) {
        cout << "Fail to create lines.txt\n";
        return 1;
    }

    DrawKoch(depth, x0, y0, angle, length, out);
    out.close();

    cout << "The Koch curve segments are in lines.txt\n";
    return 0;
}
