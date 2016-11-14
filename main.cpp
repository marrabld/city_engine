#include "tests/tests.h"
#include <GL/freeglut.h>
#include <iostream>
#include "Cube.h"
#include "Math.h"

using namespace tests;

bool light = false;

Vector3D verts[24] = { Vector3D(0.5, -0.5, -0.5), Vector3D(0.5, 0.5, -0.5), Vector3D(-0.5, 0.5, -0.5), Vector3D(-0.5, -0.5, -0.5),
                           Vector3D(0.5, -0.5, 0.5), Vector3D(0.5, 0.5, 0.5), Vector3D(-0.5, 0.5, 0.5), Vector3D(-0.5, -0.5, 0.5),
                           Vector3D(0.5, -0.5, -0.5), Vector3D(0.5, 0.5, -0.5), Vector3D(0.5, 0.5, 0.5), Vector3D(0.5, -0.5, 0.5),
                           Vector3D(-0.5, -0.5, 0.5), Vector3D(-0.5, 0.5, 0.5), Vector3D(-0.5, 0.5, -0.5), Vector3D(-0.5, -0.5, -0.5),
                           Vector3D(0.5, 0.5, 0.5), Vector3D(0.5, 0.5, -0.5), Vector3D(-0.5, 0.5, -0.5), Vector3D(-0.5, 0.5, 0.5),
                           Vector3D(0.5, -0.5, -0.5), Vector3D(0.5, -0.5, 0.5), Vector3D(-0.5, -0.5, 0.5), Vector3D(-0.5, -0.5, -0.5)};


Vector3D colours[6] = {Vector3D(1.0, 0.0, 0.0), Vector3D(0.0, 1.0, 0.0), Vector3D(0.0, 0.0, 1.0),
                      Vector3D(0.5, 0.5, 0.5), Vector3D(0.0, 1.0, 1.0), Vector3D(0.3, 0.2, 0.1)};

GLfloat angleCube = 0.0f;     // Rotational angle for cube [NEW]
int refreshMills = 5;        // refresh interval in milliseconds [NEW]


void timer(int value) {
    glutPostRedisplay();      // Post re-paint request to activate display()
    glutTimerFunc(refreshMills, timer, 0); // next timer call milliseconds later
}

void draw_a_cube(void) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
// Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS);

    glLoadIdentity();                 // Reset the model-view matrix
    glTranslatef(0.1f, 0.1f, 0.0f);  // Move right and into the screen
    glRotatef(angleCube, 1.0f, 1.0f, 1.0f);

    for (int i = 0; i < 6; i++) {
        //glBegin(GL_LINE_STRIP);
        glBegin(GL_LINES);

        for (int j = 0; j < 4; j++){
            glVertex3f(verts[(i * 4) + j].x, verts[(i * 4) + j].y, verts[(i * 4) + j].z);
        }
    }

    glEnd();

    for (int i = 0; i < 6; i++) {
        //glBegin(GL_LINE_STRIP);
        glBegin(GL_QUADS);
        glColor3f(colours[i].x, colours[i].y, colours[i].z);

        for (int j = 0; j < 4; j++){
            glVertex3f(verts[(i * 4) + j].x, verts[(i * 4) + j].y, verts[(i * 4) + j].z);
        }
    }

    glEnd();

    //glRotatef(angleCube, 1.0f, 1.0f, 1.0f);  // Rotate about (1,1,1)-axis [NEW]
    glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)

    // Update the rotational angle after each refresh [NEW]
    angleCube -= 0.15f;
}

int main(int argc, char** argv)
{
    Vector3D centerPosition = Vector3D(1.f, 1.f, 1.f);
    Vector3D eyePosition = Vector3D(0.f, 0.f, 0.f);
    Vector3D upVector = Vector3D(0.f, 0.f, 1.f);

    glutInit(&argc, argv);

    // Reset transformations
    glLoadIdentity();

    gluLookAt(eyePosition.x, eyePosition.y, eyePosition.z, centerPosition.x, centerPosition.y, centerPosition.z, upVector.x, upVector.y, upVector.z);

    glScalef(1,1,1);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glClearDepth(1.0f);                   // Set background depth to farthest
    glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
    glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections

    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("City Engine");
    glShadeModel(GL_SMOOTH);   // Enable smooth shading
    glEnable(GL_LIGHT1);

    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat light_position[] = { 0.0, 1.0, 1.0, 0.0 };

    if (light){
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);

        float ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
        float diffuseLight[] = { 0.8f, 0.8f, 0.8, 1.0f };
        float specularLight[] = { 0.5f, 0.5f, 0.5f, 1.0f };
        float position[] = { -1.5f, 1.0f, -4.0f, 1.0f };

// Assign created components to GL_LIGHT0
        glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
        glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
        glLightfv(GL_LIGHT0, GL_POSITION, position);

        glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
        glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
        glLightfv(GL_LIGHT0, GL_POSITION, light_position);


        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_DEPTH_TEST);
        glEnable ( GL_LIGHTING ) ;

    }

    glEnable(GL_LIGHT0);

    glutDisplayFunc(draw_a_cube);
    GLfloat angleCube = 0.0f;
    glRotatef(angleCube, 1.5f, 0.8f, 1.0f);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();

    glutPostRedisplay();

    return 0;
}

//int main() {
    // Vector tests
    // Test 1 Subtract
    //tests::test1();
    // Test 2 dot product
    //tests::test2();
    // Test 3 cross product
    //tests::test3();
    // Test 4 sum
    //tests::test4();
    // Test 5 multiply
    //tests::test5();
    // Test 6 magnitude
    // tests::test6();  THIS ISN'T WORKING
    // tests::test8();

    //Matrix tests
    // test7();

    // test9();
    // Matrix multiplication
    // test10();
    // Matrix subtraction
    // test11();
    // test12();

//    return 0;
//}

