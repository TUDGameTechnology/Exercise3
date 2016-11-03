#include "pch.h"

#include <Kore/IO/FileReader.h>
#include <Kore/Math/Core.h>
#include <Kore/System.h>
#include <Kore/Input/Keyboard.h>
#include <Kore/Input/Mouse.h>
#include <Kore/Audio/Mixer.h>
#include "SimpleGraphics.h"
#include "ObjLoader.h"

using namespace Kore;

namespace {
	double startTime;
	Mesh* mesh;

	void update() {
		float t = (float)(System::time() - startTime);
		Kore::Audio::update();
		
		startFrame();

		clear(0, 0, 0);
		
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
			drawTriangle(
				x1 * 2000 + 600, y1 * 2000 + 600,
				x2 * 2000 + 600, y2 * 2000 + 600,
				x3 * 2000 + 600, y3 * 2000 + 600);
			}

		endFrame();
	}

	void keyDown(KeyCode code, wchar_t character) {
		if (code == Key_Left) {
			/************************************************************************/
			/* Use the keyboard input to control the transformations                */
			/************************************************************************/
		}
	}

	void keyUp(KeyCode code, wchar_t character) {
		if (code == Key_Left) {
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
	Kore::System::init("Exercise 3", width, height);

	initGraphics();
	Kore::System::setCallback(update);

	startTime = System::time();
	Kore::Mixer::init();
	Kore::Audio::init();
	//Kore::Mixer::play(new SoundStream("back.ogg", true));

	mesh = loadObj("bunny.obj");

	Keyboard::the()->KeyDown = keyDown;
	Keyboard::the()->KeyUp = keyUp;
	Mouse::the()->Move = mouseMove;
	Mouse::the()->Press = mousePress;
	Mouse::the()->Release = mouseRelease;

	Kore::System::start();
	
	return 0;
}
