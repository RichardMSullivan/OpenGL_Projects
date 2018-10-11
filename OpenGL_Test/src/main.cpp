#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<GLUT/glut.h>
#include<OpenGL/OpenGL.h>
#include<iostream>

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
