#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<math.h>
#include <stdlib.h>

// NAME: Omar Mostafa REGNO.: 18101516
// NAME: Mohamed Tarek REGNO.: 18101737

GLfloat cloud1x = 0.0f; //defines the x coordinates cloud 1 should be translated to
GLfloat cloud2x = 0.0f; //defines the x coordinates cloud 2 should be translated to
GLfloat angle = 0.0f;  //defines the angle the wheel bar should rotate to
GLfloat carAndWheelX = 0; //defines the x coordinates CAR BODY, CAR TOP, WHEEL 1, WHEEL 2, WHEEL 1 BAR and WHEEL 2 BAR should be translated to
GLint red;  //stores the int value of red generated from rand()
GLint green; //stores the int value of green generated from rand()
GLint blue; //stores the int value of blue generated from rand()
GLfloat redf = 1.0f; //red color intensity of the CAR BODY and CAR TOP
GLfloat greenf = 0.0f; //green color intensity of the CAR BODY and CAR TOP
GLfloat bluef = 0.0f; //blue color intensity of the CAR BODY and CAR TOP

void init() {

    glClearColor(0.31, 0.58, 0.796, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);

}

void display(void)
{
    

    glClear(GL_COLOR_BUFFER_BIT);

    
    //----------CLOUD 1----------
    glPushMatrix();
    glTranslatef(cloud1x, 0, 0);
    glColor3f(0.7921, 0.8235, 0.8588);
    int radius = 5;
    double theta;
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        for(int i = 0; i < 360; i++) {
            theta = i * 3.142 /180;
            glVertex2f(radius * sin(theta), 50 + radius * cos(theta));
        }
    }
    glEnd();
    
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(5 + radius * cos(theta), (5 + 50) + radius * sin(theta));
            
    }

    glEnd();
    
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(5 + radius * cos(theta), (5 + 43) + radius * sin(theta));
    }
    glEnd();
    
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(10 + radius * cos(theta), (5 + 45) + radius * sin(theta));
            
    }
    glEnd();
    glPopMatrix();
    //----------END OF CLOUD 1----------
    
    
    //----------CLOUD 2----------
    glPushMatrix();
    glTranslatef(cloud2x, 0, 0);
    glColor3f(0.7921, 0.8235, 0.8588);
    glBegin(GL_POLYGON);

    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(-80 + radius * sin(theta), 30 + radius * cos(theta));
    }
    glEnd();
    
    glBegin(GL_POLYGON);

    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(-80 + 5 + radius * cos(theta), (5 + 30) + radius * sin(theta));
    }

    glEnd();
    
    glBegin(GL_POLYGON);

    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(-80 + 5 + radius * cos(theta), (5 + 23) + radius * sin(theta));
    }

    glEnd();
    
    glBegin(GL_POLYGON);

    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(-80+ 10 + radius * cos(theta), (5 + 25) + radius * sin(theta));
    }

    glEnd();
    glPopMatrix();
    //----------END OF CLOUD 2----------
    
    
    
    //----------MAIN ROAD----------
    glColor3f(0.2235f, 0.2784f, 0.30588f);
    glBegin(GL_POLYGON);
    glVertex3f(-100, -100, 0);
    glVertex3f(-100, -60, 0);
    glVertex3f(100, -60, 0);
    glVertex3f(100, -100, 0);
    glEnd();
    
    //----------MAIN ROAD DIVIDER 1----------
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(-90, -85, 0);
    glVertex3f(-90, -80, 0);
    glVertex3f(-70, -80, 0);
    glVertex3f(-70, -85, 0);
    glEnd();
    
    //----------MAIN ROAD DIVIDER 2----------
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(-50, -85, 0);
    glVertex3f(-50, -80, 0);
    glVertex3f(-30, -80, 0);
    glVertex3f(-30, -85, 0);
    glEnd();
    
    //----------MAIN ROAD DIVIDER 3----------
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(-10, -85, 0);
    glVertex3f(-10, -80, 0);
    glVertex3f(10, -80, 0);
    glVertex3f(10, -85, 0);
    glEnd();
    
    //----------MAIN ROAD DIVIDER 4----------
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(30, -85, 0);
    glVertex3f(30, -80, 0);
    glVertex3f(50, -80, 0);
    glVertex3f(50, -85, 0);
    glEnd();
    
    //----------MAIN ROAD DIVIDER 5----------
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(70, -85, 0);
    glVertex3f(70, -80, 0);
    glVertex3f(90, -80, 0);
    glVertex3f(90, -85, 0);
    glEnd();
    
    
    //----------TRIMMED GRASS----------
    glColor3f(0.5019, 0.58431, 0.34901);
    glBegin(GL_POLYGON);
    glVertex2f(-100, -60);
    glVertex2f(-100, -70);
    glVertex2f(100, -70);
    glVertex2f(100, -60);
    glEnd();
    
    //----------GRASS----------
    glColor3f(0.423, 0.5411, 0.239);
    glBegin(GL_POLYGON);
    glVertex2f(-100, -60);
    glVertex2f(-100, 0);
    glVertex2f(100, 0);
    glVertex2f(100, -60);
    glEnd();
    
    
    //----------MAIN BUILDING----------
    glColor3f((float)46/255, (float)43/255, (float)42/255);
    glBegin(GL_POLYGON);
    glVertex2f(-10, 40);
    glVertex2f(-10, -10);
    glVertex2f(25, -10);
    glVertex2f(25, 40);
    glEnd();
    
    
    
    //----------BULDING WINDOWS ROW1----------
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-5, 30);
    glVertex2f(-5, 25);
    glVertex2f(0, 25);
    glVertex2f(0, 30);
    glEnd();
    
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(5, 30);
    glVertex2f(5, 25);
    glVertex2f(10, 25);
    glVertex2f(10, 30);
    glEnd();
    
    
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(15, 30);
    glVertex2f(15, 25);
    glVertex2f(20, 25);
    glVertex2f(20, 30);
    glEnd();
    //----------END OF BULDING WINDOWS ROW1----------
    
    
    //----------BULDING WINDOWS ROW2----------
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-5, 15);
    glVertex2f(-5, 10);
    glVertex2f(0, 10);
    glVertex2f(0, 15);
    glEnd();
    
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(5, 15);
    glVertex2f(5, 10);
    glVertex2f(10, 10);
    glVertex2f(10, 15);
    glEnd();
    
    
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(15, 15);
    glVertex2f(15, 10);
    glVertex2f(20, 10);
    glVertex2f(20, 15);
    glEnd();
    //----------END OF BULDING WINDOWS ROW2----------
    
    

    
    //----------CAR AND WHEELS----------
    //car and wheels are pushed in matrix so they can be translated on th X axis
    glPushMatrix();
    glTranslatef(carAndWheelX, 0.0f, 0.0f);
    
    //----------CAR TOP----------
    glColor3f(redf, greenf, bluef);
    glBegin(GL_POLYGON);
    glVertex2f(-100, -80);
    glVertex2f(-105, -85);
    glVertex2f(-55, -85);
    glVertex2f(-60, -80);
    glEnd();
    
    //----------CAR BODY----------
    glColor3f(redf, greenf, bluef);
    glBegin(GL_POLYGON);
    glVertex2f(-110, -85);
    glVertex2f(-110, -95);
    glVertex2f(-50, -95);
    glVertex2f(-50, -85);
    glEnd();
    
    //----------CAR HEADLIGHTS----------
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-55, -88);
    glVertex2f(-55, -91);
    glVertex2f(-50, -91);
    glVertex2f(-50, -88);
    glEnd();
    
    //----------WHEEL 1----------
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(-95 + 5 * cos(theta), -95 + 5 * sin(theta));
    }
    glEnd();
    
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(-95  + 2.5 * cos(theta), -95 + 2.5 * sin(theta));
    }
    glEnd();
    //----------END OF WHEEL 1----------
    
    //----------WHEEL 2----------
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(-65 + 5 * cos(theta), -95 + 5 * sin(theta));
    }
    glEnd();
    
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142 /180;
        glVertex2f(-65  + 2.5 * cos(theta), -95 + 2.5 * sin(theta));
    }
    glEnd();
    //----------END OF WHEEL 2----------
    glPopMatrix();
    
    
    
    //----------WHEEL 1 BAR----------
    //wheel bar is pushed in a matrix so it can be rotated and translated
    glPushMatrix();
    glTranslatef(carAndWheelX + -95.0f, -95.0f, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glTranslatef(-1*carAndWheelX + 95.0f, 95.0f, 0.0f);
    glTranslatef(carAndWheelX, 0.0, 0.0);
    glColor3f((float)46/255, (float)43/255, (float)42/255);
    glBegin(GL_POLYGON);
    glVertex2f(-97, -96);
    glVertex2f(-97, -94);
    glVertex2f(-93, -94);
    glVertex2f(-93, -96);
    glEnd();
    glPopMatrix();

    //----------WHEEL 2 BAR----------
    //whee2 bar is pushed in a matrix so it can be rotated and translated
    glPushMatrix();
    glTranslatef(carAndWheelX + -65.0f, -95.0f, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glTranslatef(-1*carAndWheelX + 65.0f, 95.0f, 0.0f);
    glTranslatef(carAndWheelX, 0.0, 0.0);
    glColor3f((float)46/255, (float)43/255, (float)42/255);
    glBegin(GL_POLYGON);
    glVertex2f(-67, -96);
    glVertex2f(-67, -94);
    glVertex2f(-63, -94);
    glVertex2f(-63, -96);
    glEnd();
    glPopMatrix();
    
    
    glutSwapBuffers();

}

void timer(int) {
    
    glutPostRedisplay();
    glutTimerFunc(1000/60, timer, 0);
    cloud1x += 0.30;
    cloud2x += 0.35;
    
    //if cloud is outside the viewport
    if (cloud1x > 120) {
        cloud1x = -120;
    }

    if (cloud2x > 190) {
        cloud2x = -100;
    }
    
    angle += 5;
    carAndWheelX +=1;
    //if car is outside the viewport
    //change the color to any color from 0 to 254 + 20(to avoid darker colors)
    if (carAndWheelX > 250) {
        red = rand() % 255 + 20;
        green = rand() % 255 + 20;
        blue = rand() % 255 + 20;
        
        redf = (float)red/255;
        greenf = (float)green/255;
        bluef = (float)blue/255;
        carAndWheelX = -50;
    }
        
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1200, 800);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(200, 0);

    glutCreateWindow("18101516 - 18101737");

    init();

    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);

    glutMainLoop();

    return 0;
}
