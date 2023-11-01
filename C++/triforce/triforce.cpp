/********************************************************************************
**                              Can You Even Triforce?                         **
**                       Date of development: October 31st, 2023               **
**                        Last modified: October 31st, 2023                    **
**                             Designed by: Ryan Hatch                         **
********************************************************************************/

/********************************************************************************
**                 This code uses iteration to draw a Triforce shape.          **
**                                                                             **
**  It starts by drawing the largest equilateral triangle, then draws smaller  **
**                 Triforce shapes within each larger triangle.                **
**                                                                             **
**          The height parameter controls the size of the Triforce shape.      **
**        The code positions the triangles to ensure the entire shape is       **
**                             visible on the screen.                          **
********************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Class to represent the Triforce shape
class Triforce {
public:
    // Constructor to initialize the height and size of the plane
    Triforce(int height) : height(height), pw(height * 4), ph(height * 2) {
        plane.resize(ph, string(pw, ' '));
    }

    // Function to draw a triangle at the given position with the given width and height
    void drawTriangle(int x, int y, int width, int height) {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (j == width / 2 - i || j == width / 2 + i) {
                    plane[y + i][x + j] = '/';
                }
                else if (j > width / 2 - i && j < width / 2 + i) {
                    plane[y + i][x + j] = ' ';
                }
                else if (j == width - 1 && i == height - 1) {
                    plane[y + i][x + j] = '\\';
                }
            }
        }
        for (int i = 0; i < width - 1; ++i) {
            plane[y + height - 1][x + i] = '_';
        }
    }

    // Function to display the Triforce shape
    void display() {
        for (const string& row : plane) {
            int idx = row.find_last_not_of(' ');
            if (idx != string::npos) {
                cout << row.substr(0, idx + 1) << endl;
            }
        }
    }

private:
    int height;  // Height of the Triforce shape
    int pw, ph;  // Width and height of the plane
    vector<string> plane;  // 2D plane to represent the Triforce shape
};

int main() {
    int height;
    cout << "Enter height: ";
    cin >> height;
    // Validate the height input
    if (height < 2 || height > 20) {
        cout << "Invalid height." << endl;
        return 1;
    }

    Triforce triforce(height);
    int rw = height * 2;
    int rh = height;
    // Draw the three triangles of the Triforce
    triforce.drawTriangle(0, rh, rw, rh);
    triforce.drawTriangle(rw / 2, 0, rw, rh);
    triforce.drawTriangle(rw, rh, rw, rh);
    // Display the Triforce
    triforce.display();

    return 0;
}