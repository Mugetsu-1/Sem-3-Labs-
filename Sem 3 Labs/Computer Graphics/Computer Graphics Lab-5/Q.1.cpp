#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>

class Cube {
    struct Point { float x, y, z; };
    Point vertices[8], original[8];
    char screen[20][120];  // Wider screen for side-by-side rendering

    void rotatePoint(Point& p, float ax, float ay, float az) {
        float cx = cos(ax), sx = sin(ax), cy = cos(ay), sy = sin(ay), cz = cos(az), sz = sin(az);
        float nx = p.x * (cy * cz) + p.y * (sx * sy * cz - cx * sz) + p.z * (cx * sy * cz + sx * sz);
        float ny = p.x * (cy * sz) + p.y * (sx * sy * sz + cx * cz) + p.z * (cx * sy * sz - sx * cz);
        float nz = p.x * (-sy) + p.y * (sx * cy) + p.z * (cx * cy);
        p.x = nx; p.y = ny; p.z = nz;
    }

    void slowDelay(long iterations = 800000000) { 
        for (long i = 0; i < iterations; ++i) { 
            // Empty loop for delay 
        } 
    }

    void renderCube(Point* temp, int offsetX, float rotX, float scale) {
        int projX[8], projY[8];
        for (int i = 0; i < 8; ++i) {
            projX[i] = static_cast<int>(temp[i].x * 7 + offsetX);
            projY[i] = static_cast<int>(temp[i].y * 7 + 10);
        }

        int edges[12][2] = {
            {0,1}, {1,3}, {3,2}, {2,0},  
            {4,5}, {5,7}, {7,6}, {6,4},  
            {0,4}, {1,5}, {2,6}, {3,7}   
        };

        for (int e = 0; e < 12; ++e) {
            int x1 = projX[edges[e][0]], y1 = projY[edges[e][0]];
            int x2 = projX[edges[e][1]], y2 = projY[edges[e][1]];

            int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
            int dy = -abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
            int err = dx + dy, e2;

            while (true) {
                if (x1 >= 0 && x1 < 120 && y1 >= 0 && y1 < 20) {
                    screen[y1][x1] = '+';
                }
                if (x1 == x2 && y1 == y2) break;
                e2 = 2 * err;
                if (e2 >= dy) { err += dy; x1 += sx; }
                if (e2 <= dx) { err += dx; y1 += sy; }
            }
        }

        for (int i = 0; i < 8; ++i) {
            if (projX[i] >= 0 && projX[i] < 120 && projY[i] >= 0 && projY[i] < 20) {
                screen[projY[i]][projX[i]] = '*';
            }
        }
    }

public:
    Cube() {
        float coords[2] = {-1, 1};
        int idx = 0;
        for (int x = 0; x < 2; ++x)
            for (int y = 0; y < 2; ++y)
                for (int z = 0; z < 2; ++z) {
                    vertices[idx].x = original[idx].x = coords[x];
                    vertices[idx].y = original[idx].y = coords[y];
                    vertices[idx].z = original[idx].z = coords[z];
                    ++idx;
                }
    }

    void reset() { 
        for (int i = 0; i < 8; ++i) vertices[i] = original[i]; 
    }

    void render(float rotX = 0, float rotY = 0, float scale = 1.0) {
        for (int i = 0; i < 20; ++i)
            for (int j = 0; j < 120; ++j)
                screen[i][j] = ' ';

        Point tempRotate[8], tempScale[8];
        for (int i = 0; i < 8; ++i) {
            tempRotate[i] = tempScale[i] = vertices[i];

            if (rotX) rotatePoint(tempRotate[i], rotX, 0, 0);
            if (rotY) rotatePoint(tempRotate[i], 0, rotY, 0);

            tempScale[i].x *= scale;
            tempScale[i].y *= scale;
            tempScale[i].z *= scale;
        }

        renderCube(tempRotate, 30, rotX, 1.0);
        renderCube(tempScale, 90, 0, scale);

        system("cls");
        for (int i = 0; i < 20; ++i) {
            for (int j = 0; j < 120; ++j) {
                std::cout << screen[i][j];
            }
            std::cout << std::endl;
        }
        std::cout << "Rotation X: " << static_cast<int>(rotX * 180 / 3.14159) 
                  << "                                                                 Scaling: " << std::fixed << std::setprecision(2) << scale << std::endl;
    }

    void demonstrate() {
        std::cout << "=== CUBE TRANSFORMATIONS ===\n";

        std::cout << "\nGradual Rotation and Scaling:\n";
        reset();
        for (float progress = 0; progress <= 2 * 3.14159; progress += 3.14159 / 12) {
            float angle = progress;
            float scale = 1 + sin(progress) * 0.5;
            render(angle, angle, scale);
            slowDelay(800000000);  // Increased delay
        }
    }
};
/*
int main() {
    Cube cube;
    cube.demonstrate();
    return 0;
}
*/
