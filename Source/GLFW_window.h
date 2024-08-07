#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <vector>
#include <iomanip>


#include "SingleTon.h"
#include "../Resource/Shader/shader.h"
#include "Camera.h"
#include "Block.h"
#include "Chunk.h"


struct mousePosition{
	float xPos, yPos;
	mousePosition(float _x, float _y) : xPos(_x), yPos(_y) {};
};

class Window :public SingleTon
{
public:
	Window(int HEIGHT, int _WIDTH);
	~Window();
	void run();
	bool loadTexture(std::string name);
	void Draw();
	void processInput();

	unsigned int SCR_WIDTH;
	unsigned int SCR_HEIGHT;

private:
	void glfwInitialize();
	glm::mat4 projection , view;

	shader* ourShader;
	Camera* camera;
	struct mousePosition mousePos;
	float deltaTime, lastTime , lastFrame;
	bool firstMouse;

	GLFWwindow* window;

public:
	void setMousePos(mousePosition _mousePos) { mousePos = _mousePos; };
	shader* getShader() { return ourShader; };
	bool getFirstMouse() { return firstMouse; };
	float getDelteTime() { return deltaTime; };
	float getLastTime() { return lastTime; };
	float getLastFrame() { return lastFrame; };
	Camera* getCamera() { return camera; };
	mousePosition getMousePos() { return mousePos; };
	void setFirstMouse(bool _value) { firstMouse = _value; };
	World* _world;
};

// preprocessor
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);


