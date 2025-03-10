#include "data.h"
#include "display.h"
#include "simulation.h"



void main(int argc, char** argv)
{
	setlocale(LC_ALL, "ru");
	
	// инициализация библиотеки GLUT
	glutInit(&argc, argv);
	// инициализация дисплея (формат вывода)
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);
	// СОЗДАНИЕ ОКНА:
	// 1. устанавливаем верхний левый угол окна
	glutInitWindowPosition(200, 200);
	// 2. устанавливаем размер окна
	glutInitWindowSize(800, 600);
	// 3. создаем окно
	glutCreateWindow("Laba_05");
	GLenum err = glewInit();
	if (err != GLEW_OK)
	{
		printf("Error: %s\n", glewGetErrorString(err));
	}
	printf("Using GLEW %s\n", glewGetString(GLEW_VERSION));
	initData();
	// УСТАНОВКА ФУНКЦИЙ ОБРАТНОГО ВЫЗОВА
	// устанавливаем функцию, которая будет вызываться для перерисовки окна
	glutDisplayFunc(display);
	// устанавливаем функцию, которая будет вызываться при изменении размеров окна
	glutReshapeFunc(reshape);
	// устанавливаем функцию, которая будет вызвана через 20 мс
	glutIdleFunc(simulation);
	// основной цикл обработки сообщений ОС
	glutMainLoop();
};