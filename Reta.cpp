// Retas.cpp - Isabel H. Manssour
// Um programa OpenGL simples que desenha uma
// reta em uma janela GLUT.
// Este código está baseado no GLRect.c, exemplo 
// disponível no livro "OpenGL SuperBible", 
// 2nd Edition, de Richard S. e Wright Jr.

#include <windows.h>
#include <glut.h>

// Função callback chamada para fazer o desenho
void Desenha(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Limpa a janela de visualização com a cor de fundo especificada
    glClear(GL_COLOR_BUFFER_BIT);

    // Especifica que a cor corrente é vermelha
    //         R     G     B
    glColor3f(1.0f, 0.0f, 0.0f);
    glPointSize(5);
    glLineWidth(25);

    // Desenha uma reta com a cor corrente
    glBegin(GL_LINES);
    glVertex2i(200, 100);
    glVertex2i(50, 100);

    glEnd();

    // Executa os comandos OpenGL
    glFlush();
}

// Inicializa parâmetros de rendering
void Inicializa(void)
{
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
    // Evita a divisao por zero
    if (h == 0) h = 1;

    // Especifica as dimensões da Viewport
    glViewport(0, 0, w, h);

    // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Estabelece a janela de seleção (left, right, bottom, top)
    if (w <= h)
        gluOrtho2D(0.0f, 250.0f, 0.0f, 250.0f * h / w);
    else
        gluOrtho2D(0.0f, 250.0f * w / h, 0.0f, 250.0f);
}

// Programa Principal 
int main(void)
{
    {
        int argc = 1;
        char* argv[1] = { (char*)"Something" };
        glutInit(&argc, argv);
    }
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(660, 240);
    glutCreateWindow("Reta");
    glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
    Inicializa();
    glutMainLoop();
}