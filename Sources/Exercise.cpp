#include "pch.h"

#include <Kore/IO/FileReader.h>
#include <Kore/Math/Core.h>
#include <Kore/System.h>
#include <Kore/Input/Keyboard.h>
#include <Kore/Input/Mouse.h>
#include <Kore/Audio1/Audio.h>
#include <Kore/Graphics1/Graphics.h>
#include "GraphicsHelper.h"
#include "ObjLoader.h"

const int width = 512;
const int height = 512;

using namespace Kore;

namespace {
	double startTime;
	Mesh* mesh;

	void update() {
		float t = (float)(System::time() - startTime);
		Kore::Audio2::update();
		
		Graphics1::begin();
		clear(0.0f, 0.0f, 0.0f);
		
		/************************************************************************/
		/* Exercise 3 Practical Task 1                                          */
		/* Implement camera controls to translate and rotate the mesh           */
		/* Implement perspective projection                                     */
		/************************************************************************/

		for (int i = 0; i < mesh->numFaces; ++i) {
			// Get the indices into the vertices array for each vertex of the mesh
			int i1 = mesh->indices[i * 3 + 0];
			int i2 = mesh->indices[i * 3 + 1];
			int i3 = mesh->indices[i * 3 + 2];

			// Get the x, y, z coordinates of each vertex
			float x1 = mesh->vertices[i1 * 5 + 0];
			float y1 = -mesh->vertices[i1 * 5 + 1];
			float z1 = mesh->vertices[i1 * 5 + 2];

			float x2 = mesh->vertices[i2 * 5 + 0];
			float y2 = -mesh->vertices[i2 * 5 + 1];
			float z2 = mesh->vertices[i2 * 5 + 2];

			float x3 = mesh->vertices[i3 * 5 + 0];
			float y3 = -mesh->vertices[i3 * 5 + 1];
			float z3 = mesh->vertices[i3 * 5 + 2];

			// Draw the triangle
			float drawScale = 1024;
			drawTriangle(
				x1 * drawScale + width / 2, y1 * drawScale + height / 2,
				x2 * drawScale + width / 2, y2 * drawScale + height / 2,
				x3 * drawScale + width / 2, y3 * drawScale + height / 2);
			}

		Graphics1::end();
	}

	void keyDown(KeyCode code) {
		if (code == KeyLeft) {
			/************************************************************************/
			/* Use the keyboard input to control the transformations                */
			/************************************************************************/
		}
	}

	void keyUp(KeyCode code) {
		if (code == KeyLeft) {
			// ...
		}
	}

	void mouseMove(int window, int x, int y, int movementX, int movementY) {

	}
	
	void mousePress(int window, int button, int x, int y) {

	}

	void mouseRelease(int window, int button, int x, int y) {

	}
}

int kore(int argc, char** argv) {
	System::init("Exercise 3", width, height);

	Graphics1::init(width, height);
	Kore::System::setCallback(update);

	startTime = System::time();
	
	Kore::Audio2::init();
	Kore::Audio1::init();

	mesh = loadObj("bunny.obj");

	Keyboard::the()->KeyDown = keyDown;
	Keyboard::the()->KeyUp = keyUp;
	Mouse::the()->Move = mouseMove;
	Mouse::the()->Press = mousePress;
	Mouse::the()->Release = mouseRelease;

	Kore::System::start();
	
	return 0;
}
