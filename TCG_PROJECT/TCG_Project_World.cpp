#include <GL/glut.h>
#include "TCG_Project_World.hpp"

using namespace TCG_Project;

void MyEnvironment::draw()
{
   drawEnvironment();
}

void MyEnvironment::drawEnvironment()
{
    glDisable(GL_CULL_FACE);

    glBegin(GL_QUADS);
        //back wall
        glColor3f(0.5f, 0.1f, 0.3f );
        glVertex3f(-125.1f, 0.1f, 0.1f );
        glVertex3f(125.1f, 0.1f, 0.1f );
        glVertex3f(125.1f, 100.1f, 0.1f );
        glVertex3f(-125.1f, 100.1f, 0.1f );
        //front wall
        glColor3f(0.5f, 0.1f, 0.3f );
        glVertex3f(-125.1f, 0.1f, 250.1f );
        glVertex3f(125.1f, 0.1f, 250.1f );
        glVertex3f(125.1f, 100.1f, 250.1f );
        glVertex3f(-125.1f, 100.1f, 250.1f );
        //left wall
        glColor3f(0.5f, 0.1f, 0.8f );
        glVertex3f(-125.1f, 0.1f, 0.1f );
        glVertex3f(-125.1f, 0.1f, 250.1f );
        glVertex3f(-125.1f, 100.1f, 250.1f );
        glVertex3f(-125.1f, 100.1f, 0.1f );
        //right wall
        glColor3f(0.5f, 0.1f, 0.8f );
        glVertex3f(125.1f, 0.1f, 0.1f );
        glVertex3f(125.1f, 0.1f, 250.1f );
        glVertex3f(125.1f, 100.1f, 250.1f );
        glVertex3f(125.1f, 100.1f, 0.1f );
        //floor
        glColor3f(0.0f, 1.0f, 1.0f );
        glVertex3f(-125.1f, 0.1f, 0.1f );
        glVertex3f(125.1f, 0.1f, 0.1f );
        glVertex3f(125.1f, 0.1f, 250.1f );
        glVertex3f(-125.1f, 0.1f, 250.1f );
        //roof
        glColor3f(0.0f, 1.0f, 1.0f );
        glVertex3f(-125.1f, 100.1f, 0.1f );
        glVertex3f(125.1f, 100.1f, 0.1f );
        glVertex3f(125.1f, 100.1f, 250.1f );
        glVertex3f(-125.1f, 100.1f, 250.1f );
    glEnd();

    glEnable(GL_CULL_FACE);
}

void MyWarden::draw()
{
    drawWarden();
}

// ===== SIMPLE CUBE =====
void MyWarden::drawCube(float size)
{
    float s = size / 2.0f;

    glBegin(GL_QUADS);

    // FRONT
    glVertex3f(-s, -s,  s);
    glVertex3f( s, -s,  s);
    glVertex3f( s,  s,  s);
    glVertex3f(-s,  s,  s);

    // BACK
    glVertex3f(-s, -s, -s);
    glVertex3f(-s,  s, -s);
    glVertex3f( s,  s, -s);
    glVertex3f( s, -s, -s);

    // LEFT
    glVertex3f(-s, -s, -s);
    glVertex3f(-s, -s,  s);
    glVertex3f(-s,  s,  s);
    glVertex3f(-s,  s, -s);

    // RIGHT
    glVertex3f( s, -s, -s);
    glVertex3f( s,  s, -s);
    glVertex3f( s,  s,  s);
    glVertex3f( s, -s,  s);

    // TOP
    glVertex3f(-s,  s, -s);
    glVertex3f(-s,  s,  s);
    glVertex3f( s,  s,  s);
    glVertex3f( s,  s, -s);

    // BOTTOM
    glVertex3f(-s, -s, -s);
    glVertex3f( s, -s, -s);
    glVertex3f( s, -s,  s);
    glVertex3f(-s, -s,  s);

    glEnd();
}

// ===== WARDEN MODEL =====
void MyWarden::drawWarden()
{
    glDisable(GL_CULL_FACE); // same style as environment

    // ===== BODY =====
    glPushMatrix();
        glTranslatef(0.0f, 10.0f, 0.0f);
        glScalef(8.0f, 12.0f, 4.0f);
        glColor3f(0.1f, 0.6f, 0.6f);
        drawCube(1.0f);
    glPopMatrix();

    // ===== HEAD =====
    glPushMatrix();
        glTranslatef(0.0f, 20.0f, 0.0f);
        glScalef(6.0f, 6.0f, 6.0f);
        glColor3f(0.0f, 0.4f, 0.4f);
        drawCube(1.0f);
    glPopMatrix();

    // ===== LEFT ARM =====
    glPushMatrix();
        glTranslatef(-7.0f, 10.0f, 0.0f);
        glScalef(2.0f, 10.0f, 2.0f);
        glColor3f(0.0f, 0.5f, 0.5f);
        drawCube(1.0f);
    glPopMatrix();

    // ===== RIGHT ARM =====
    glPushMatrix();
        glTranslatef(7.0f, 10.0f, 0.0f);
        glScalef(2.0f, 10.0f, 2.0f);
        glColor3f(0.0f, 0.5f, 0.5f);
        drawCube(1.0f);
    glPopMatrix();

    // ===== LEFT LEG =====
    glPushMatrix();
        glTranslatef(-3.0f, 0.0f, 0.0f);
        glScalef(2.0f, 10.0f, 2.0f);
        glColor3f(0.0f, 0.3f, 0.3f);
        drawCube(1.0f);
    glPopMatrix();

    // ===== RIGHT LEG =====
    glPushMatrix();
        glTranslatef(3.0f, 0.0f, 0.0f);
        glScalef(2.0f, 10.0f, 2.0f);
        glColor3f(0.0f, 0.3f, 0.3f);
        drawCube(1.0f);
    glPopMatrix();

    // ===== HORNS =====
    glPushMatrix();
        glTranslatef(-2.0f, 25.0f, 0.0f);
        glScalef(1.0f, 4.0f, 1.0f);
        glColor3f(0.8f, 0.8f, 0.5f);
        drawCube(1.0f);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(2.0f, 25.0f, 0.0f);
        glScalef(1.0f, 4.0f, 1.0f);
        glColor3f(0.8f, 0.8f, 0.5f);
        drawCube(1.0f);
    glPopMatrix();

    glEnable(GL_CULL_FACE);
}

