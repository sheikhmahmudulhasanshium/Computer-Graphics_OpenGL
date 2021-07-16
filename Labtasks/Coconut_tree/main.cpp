#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<math.h>
/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */

void CoconutLeafStick()
{
    glBegin(GL_POLYGON);
    glColor3b(0.4, 19.6, 12.5);//leaf-stick
    glVertex2f(255,400);
    glVertex2f(315,400);
    glVertex2f(255,395);
    glEnd();

     // Create and draw the curves for every 4 points

}
void CoconutLeaf()
{
    CoconutLeafStick();

    float   x1=265,y1=400;//lower-leaf-upper
    float   x2=270,y2=375;//lower-leaf-lower
    float   x3=x2-5,y3=y2+22;//upper-leaf-lower
    float   x4=x1+5,y4=y1+22;//upper-leaf-upper

    for(int leafNo=1;leafNo<14;leafNo++)
    {
        glBegin(GL_LINES);//green-leaf-lower
        glColor3b(0.4, 19.6, 12.5);
        glVertex2f((x1+(3*leafNo)),y1);//lower-leaf
        glVertex2f((x2+(3*leafNo)),(y2+(leafNo*0.85)));

        glVertex2f((x3+(3*leafNo)),y3);//lower-leaf
        glVertex2f((x4+(3*leafNo)),(y4-(leafNo*0.85)));
    }
    glEnd();

}
void CoconutLeafLoop()
{
    CoconutLeaf();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    for(int leafNo=0;leafNo<6;leafNo++)
    {
        glTranslatef(255, 395, 0);
        glRotatef(30, 0.0f, 0.0f, 1.0f);//angle
        glTranslatef(-255, -395, 0);
        CoconutLeaf();

    }

    glPopMatrix();

}
void CoconutLog()
{
    glBegin(GL_POLYGON);
    glColor3ub(139,69,19);//brown-log
    glVertex2f(250.0f, 250.0f);    // x, y
	glVertex2f(250.0f, 400.0f);    // x, y

	glVertex2f(255.0f, 400.0f);    // x, y-center
	glVertex2f(260.0f, 250.0f);    // x, y

    glEnd();

}

void Coconuts()
{

    glBegin(GL_POLYGON);
    glColor3ub(0, 255, 62);//green-coconut
    for(int i=0;i<300;i++)
    {
        float r=5;
        float pi=3.1416;
        float A=i*2*pi/200;
        float x=255+r*cos(A);
        float y=380+r*sin(A);
        glVertex2f(x,y);
    }
    glEnd();

}
void CoconutTree()
{
    Coconuts();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-8,6,0);
    //glColor3b(150,90,62);//brown-coconut
    Coconuts();
    glPopMatrix();
    CoconutLeafLoop();

    CoconutLog();
}
void display() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
	glLineWidth(1.5);
	// Draw a Red 1x1 Square centered at origin
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex2f(0.0f, 250.0f);    // x, y
	glVertex2f(500.0f,250.0f);    // x, y
	glVertex2f(250.0f, 0.0f);    // x, y
	glVertex2f(250.0f, 500.0f);    // x, y


	glEnd();
    CoconutTree();
	glFlush();  // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);                 // Initialize GLUT
	glutCreateWindow("OpenGL Setup"); // Create a window with the given title
	glutInitWindowSize(320, 320);   // Set the window's initial width & height
	//gluOrtho2D(-500,500,-500,1000);
	gluOrtho2D(0,500,0,500);
	glutDisplayFunc(display); // Register display callback handler for window re-paint
	glutMainLoop();           // Enter the event-processing loop
	return 0;
}
