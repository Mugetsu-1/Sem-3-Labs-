#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <vector>

class WireframeCube {
    struct Point { 
        float x, y, z; 
        Point(float x=0, float y=0, float z=0) : x(x), y(y), z(z) {}
    };
    
    // Screen dimensions
    static const int SCREEN_WIDTH = 120;
    static const int SCREEN_HEIGHT = 40;
    char screen[SCREEN_HEIGHT][SCREEN_WIDTH];

    // Cube parameters
    float startX, startY, startZ;
    float width, height, depth;
    std::vector<Point> vertices;
    std::vector<std::pair<int, int> > edges;

    // Rotation function
    void rotatePoint(Point& p, float ax, float ay, float az) {
        float cx = cos(ax), sx = sin(ax), cy = cos(ay), sy = sin(ay), cz = cos(az), sz = sin(az);
        float nx = p.x * (cy * cz) + p.y * (sx * sy * cz - cx * sz) + p.z * (cx * sy * cz + sx * sz);
        float ny = p.x * (cy * sz) + p.y * (sx * sy * sz + cx * cz) + p.z * (cx * sy * sz - sx * cz);
        float nz = p.x * (-sy) + p.y * (sx * cy) + p.z * (cx * cy);
        p.x = nx; p.y = ny; p.z = nz;
    }

    // Delay function
    void slowDelay(long iterations = 30000000) {
        for (long i = 0; i < iterations; ++i) { /* Empty loop */ }
    }

    // Bresenham's line drawing algorithm
    void drawLine(int x1, int y1, int x2, int y2) {
        int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
        int dy = -abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
        int err = dx + dy, e2;

        while (true) {
            if (x1 >= 0 && x1 < SCREEN_WIDTH && y1 >= 0 && y1 < SCREEN_HEIGHT) {
                screen[y1][x1] = '+';
            }
            if (x1 == x2 && y1 == y2) break;
            e2 = 2 * err;
            if (e2 >= dy) { err += dy; x1 += sx; }
            if (e2 <= dx) { err += dx; y1 += sy; }
        }
    }

    // 3D Perspective Projection
    std::pair<int, int> projectPoint(const Point& p, float distance = 5.0f, float scale = 20.0f) {
        // Simple perspective projection
        float perspective = distance / (p.z + distance);
        int x = static_cast<int>(p.x * perspective * scale + SCREEN_WIDTH / 4);
        int y = static_cast<int>(p.y * perspective * scale + SCREEN_HEIGHT / 2);
        return std::make_pair(x, y);
    }

public:
    WireframeCube(float startX=0, float startY=0, float startZ=0, 
                  float width=2, float height=2, float depth=2) 
        : startX(startX), startY(startY), startZ(startZ), 
          width(width), height(height), depth(depth) {
        
        // Create 8 vertices of the cube
        vertices.push_back(Point(startX, startY, startZ));
        vertices.push_back(Point(startX + width, startY, startZ));
        vertices.push_back(Point(startX + width, startY + height, startZ));
        vertices.push_back(Point(startX, startY + height, startZ));
        vertices.push_back(Point(startX, startY, startZ + depth));
        vertices.push_back(Point(startX + width, startY, startZ + depth));
        vertices.push_back(Point(startX + width, startY + height, startZ + depth));
        vertices.push_back(Point(startX, startY + height, startZ + depth));

        // Define edges (12 edges of a cube)
        edges.push_back(std::make_pair(0,1));
        edges.push_back(std::make_pair(1,2));
        edges.push_back(std::make_pair(2,3));
        edges.push_back(std::make_pair(3,0));
        edges.push_back(std::make_pair(4,5));
        edges.push_back(std::make_pair(5,6));
        edges.push_back(std::make_pair(6,7));
        edges.push_back(std::make_pair(7,4));
        edges.push_back(std::make_pair(0,4));
        edges.push_back(std::make_pair(1,5));
        edges.push_back(std::make_pair(2,6));
        edges.push_back(std::make_pair(3,7));
    }

    // Render function with rotation and projection
    void render(float rotX = 0, float rotY = 0, float rotZ = 0) {
        // Clear screen
        for (int i = 0; i < SCREEN_HEIGHT; ++i)
            for (int j = 0; j < SCREEN_WIDTH; ++j)
                screen[i][j] = ' ';

        // Left Side: Static Wireframe Cube with Perspective
        std::vector<std::pair<int, int> > staticProjection;
        std::vector<Point> staticVertices = vertices;
        
        // Apply a slight initial rotation to show 3D perspective
        for (size_t i = 0; i < staticVertices.size(); ++i) {
            rotatePoint(staticVertices[i], 0.5, -0.3, 0.2);
        }
        
        for (size_t i = 0; i < staticVertices.size(); ++i) {
            staticProjection.push_back(projectPoint(staticVertices[i]));
        }
        
        for (size_t i = 0; i < edges.size(); ++i) {
            drawLine(
                staticProjection[edges[i].first].first, 
                staticProjection[edges[i].first].second,
                staticProjection[edges[i].second].first, 
                staticProjection[edges[i].second].second
            );
        }

        // Right Side: Rotating Wireframe Cube
        std::vector<Point> tempVertices = vertices;
        for (size_t i = 0; i < tempVertices.size(); ++i) {
            rotatePoint(tempVertices[i], rotX, rotY, rotZ);
        }

        std::vector<std::pair<int, int> > rotatingProjection;
        for (size_t i = 0; i < tempVertices.size(); ++i) {
            rotatingProjection.push_back(
                std::make_pair(
                    static_cast<int>(tempVertices[i].x * 10 + SCREEN_WIDTH * 3 / 4),
                    static_cast<int>(tempVertices[i].y * 10 + SCREEN_HEIGHT / 2)
                )
            );
        }
        for (size_t i = 0; i < edges.size(); ++i) {
            drawLine(
                rotatingProjection[edges[i].first].first, 
                rotatingProjection[edges[i].first].second,
                rotatingProjection[edges[i].second].first, 
                rotatingProjection[edges[i].second].second
            );
        }

        // Render screen
        system("cls");
        for (int i = 0; i < SCREEN_HEIGHT; ++i) {
            for (int j = 0; j < SCREEN_WIDTH; ++j) {
                std::cout << screen[i][j];
            }
            std::cout << std::endl;
        }
        std::cout << "Static Wireframe (Left) | Rotating Wireframe (Right)\n";
        std::cout << "Rotation X: " << std::fixed << std::setprecision(2) << rotX 
                  << " Y: " << rotY 
                  << " Z: " << rotZ << std::endl;
    }

    void demonstrate() {
        render(0, 0, 0);  // Show static wireframe + initial rotating cube
        slowDelay();
        for (float progress = 0; progress <= 6.28; progress += 0.26) {
            render(progress, progress/2, progress/3);
            slowDelay();
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
    cube.demonstrate();

    return 0;
}
