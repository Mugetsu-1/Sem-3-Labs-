#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>

#define SCREEN_WIDTH  80
#define SCREEN_HEIGHT 24

class WireframeCube {
    struct Point { 
        float x, y, z; 
        Point(float a=0, float b=0, float c=0) : x(a), y(b), z(c) {}
    };
    
    char screen[SCREEN_HEIGHT][SCREEN_WIDTH];
    float startX, startY, startZ;
    float width, height, depth;
    std::vector<Point> vertices;
    std::vector<std::pair<int, int> > edges;

    // Bresenham's line drawing algorithm
    void drawLine(int x1, int y1, int x2, int y2) {
        int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
        int dy = -abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
        int err = dx + dy, e2;

        while (true) {
            if (x1 >= 0 && x1 < SCREEN_WIDTH && y1 >= 0 && y1 < SCREEN_HEIGHT) {
                screen[y1][x1] = '#';
            }
            if (x1 == x2 && y1 == y2) break;
            e2 = 2 * err;
            if (e2 >= dy) { err += dy; x1 += sx; }
            if (e2 <= dx) { err += dx; y1 += sy; }
        }
    }

    // 3D Perspective Projection
    std::pair<int, int> projectPoint(const Point& p, float distance = 5.0f, float scale = 15.0f) {
        float perspective = distance / (p.z + distance);
        int x = int(p.x * perspective * scale + SCREEN_WIDTH / 2);
        int y = int(p.y * perspective * scale + SCREEN_HEIGHT / 2);
        return std::make_pair(x, y);
    }

public:
    WireframeCube(float x, float y, float z, float w, float h, float d) 
        : startX(x), startY(y), startZ(z), width(w), height(h), depth(d) {
        
        // 8 cube vertices
        vertices.push_back(Point(startX, startY, startZ));
        vertices.push_back(Point(startX + width, startY, startZ));
        vertices.push_back(Point(startX + width, startY + height, startZ));
        vertices.push_back(Point(startX, startY + height, startZ));
        vertices.push_back(Point(startX, startY, startZ + depth));
        vertices.push_back(Point(startX + width, startY, startZ + depth));
        vertices.push_back(Point(startX + width, startY + height, startZ + depth));
        vertices.push_back(Point(startX, startY + height, startZ + depth));

        // 12 edges
        int e[][2] = {{0,1},{1,2},{2,3},{3,0},{4,5},{5,6},{6,7},{7,4},{0,4},{1,5},{2,6},{3,7}};
        for (int i = 0; i < 12; i++) {
            edges.push_back(std::make_pair(e[i][0], e[i][1]));
        }
    }

    // Render function
    void render() {
        // Clear screen buffer
        for (int i = 0; i < SCREEN_HEIGHT; ++i)
            for (int j = 0; j < SCREEN_WIDTH; ++j)
                screen[i][j] = ' ';

        std::vector<std::pair<int, int> > projected;
        for (size_t i = 0; i < vertices.size(); ++i) {
            projected.push_back(projectPoint(vertices[i]));
        }

        for (size_t i = 0; i < edges.size(); ++i) {
            drawLine(
                projected[edges[i].first].first, 
                projected[edges[i].first].second,
                projected[edges[i].second].first, 
                projected[edges[i].second].second
            );
        }

        // Print screen buffer
        system("cls"); // Use "clear" for Linux/macOS
        for (int i = 0; i < SCREEN_HEIGHT; ++i) {
            for (int j = 0; j < SCREEN_WIDTH; ++j) {
                std::cout << screen[i][j];
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    float startX, startY, startZ, width, height, depth;

    std::cout << "Enter cube starting point (X Y Z): ";
    std::cin >> startX >> startY >> startZ;

    std::cout << "Enter cube dimensions (Width Height Depth): ";
    std::cin >> width >> height >> depth;

    WireframeCube cube(startX, startY, startZ, width, height, depth);
    cube.render();

    return 0;
}

