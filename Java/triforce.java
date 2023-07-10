/**
 * ================================================================================
 *                       Date of development: July 8th, 2023
 *                         Last modified: July 9th, 2023
 * ================================================================================
 *
 * ================================================================================
 *               This program draws a Triforce shape using recursion.
 *
 * It starts by drawing the largest equilateral triangle and recursively calls itself
 *        to draw smaller Triforce shapes within each larger triangle.
 *
 * The size of the Triforce shape is controlled by the 'size' parameter passed to
 *     the 'drawTriforce' method. The program positions the Triforce shape near the
 *                          bottom center of the screen.
 * ================================================================================
 * ================================================================================
 */

import java.awt.Color;
import java.awt.Graphics;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class triforce extends JPanel {
    private static final int WIDTH = 600;
    private static final int HEIGHT = 600;
    
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        
        // Set background color
        setBackground(Color.BLACK);
        
        // Set drawing color
        g.setColor(Color.WHITE);
        
        // Draw the triforce shape
        drawtriforce(g, WIDTH / 2, HEIGHT, HEIGHT);
    }
    
    private void drawTriangle(Graphics g, int x, int y, int size) {
        int[] xPoints = {x, x - size / 2, x + size / 2};
        int[] yPoints = {y, y - size, y - size};
        g.fillPolygon(xPoints, yPoints, 3);
    }
    
    private void drawtriforce(Graphics g, int x, int y, int size) {
        if (size < 10) {
            return;
        }
        
        // Draw the current triangle
        drawTriangle(g, x, y, size); 
        
        // Recursive calls to draw the smaller triforce shapes
        drawtriforce(g, x, y - size, size / 2);
        
        drawtriforce(g, x - size / 2, y, size / 2);
        
        drawtriforce(g, x + size / 2, y, size / 2);
    }
    
    public static void main(String[] args) {
        JFrame frame = new JFrame("triforce");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(WIDTH, HEIGHT);
        
        triforce panel = new triforce();
        frame.add(panel);
        
        frame.setVisible(true);
    }
}
