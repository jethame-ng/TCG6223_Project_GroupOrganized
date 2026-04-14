#ifndef TCG_PROJECT_WORLD_HPP
#define TCG_PROJECT_WORLD_HPP

#include "TCG_Project_main.hpp"

namespace TCG_Project
{

class MyEnvironment
{
public:
    void draw();
    void drawEnvironment();
};

class MyWarden
{
public:
    void draw();
    void drawWarden();
    void drawCube(float size);
};

class MyVirtualWorld
{
public:
    MyEnvironment myenvironment;
    MyWarden mywarden;

    void draw()
    {
        myenvironment.draw();
        // ===== PUT WARDEN INSIDE BOX =====
        glPushMatrix();

            // Move inside box (slightly LEFT)
            glTranslatef(-63.0f, 0.0f, 125.0f);

            // Scale down to fit room
            glScalef(2.0f, 2.0f, 2.0f);

            mywarden.draw();

        glPopMatrix();
    }
    void tickTime() {}
    void init() {}
};

}

#endif
