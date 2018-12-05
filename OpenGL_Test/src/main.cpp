//all includes that work with OpenGl
//(you may not need to use all of them)
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<GLUT/glut.h>
#include<OpenGL/OpenGL.h>

/////////////////////////////////////////
#include<iostream>

//main method includes argv and argc to use in the glutInit()
int main(int argv, char** argc)
{
    glutInit(&argv,argc);
    glutCreateWindow("GLEW TEST");
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        std::cout<<"error!"<<std::endl;
    }
    else
    {
        std::cout<<"success"<<std::endl;
    }
    return 0;
}
