#include <kinc/audio1/audio.h>
#include <kinc/graphics1/graphics.h>
#include <kinc/input/keyboard.h>
#include <kinc/input/mouse.h>
#include <kinc/io/filereader.h>
#include <kinc/math/core.h>
#include <kinc/system.h>

#include "GraphicsHelper.h"
#include "Memory.h"
#include "ObjLoader.h"

const int width = 512;
const int height = 512;

double start_time;
struct Mesh* mesh;

void update(void* data) {
	float t = (float)(kinc_time() - start_time);
	kinc_a2_update();
	
	kinc_g1_begin();
	clear(0.0f, 0.0f, 0.0f);
	
	/************************************************************************/
	/* Exercise 3 Practical Task 1                                          */
	/* Implement camera controls to translate and rotate the mesh           */
	/* Implement perspective projection                                     */
	/************************************************************************/

	for (int i = 0; i < mesh->num_faces; ++i) {
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
		float draw_scale = 1024;
		draw_triangle(
			x1 * draw_scale + width / 2, y1 * draw_scale + height / 2,
			x2 * draw_scale + width / 2, y2 * draw_scale + height / 2,
			x3 * draw_scale + width / 2, y3 * draw_scale + height / 2);
	}

	kinc_g1_end();
}

void key_down(int code, void* data) {
	if (code == KINC_KEY_LEFT) {
		/************************************************************************/
		/* Use the keyboard input to control the transformations                */
		/************************************************************************/
	}
}

void key_up(int code, void* data) {
	if (code == KINC_KEY_LEFT) {
		// ...
	}
}

void mouse_move(int window, int x, int y, int movementX, int movementY, void* data) {
	// ...
}

void mouse_press(int window, int button, int x, int y, void* data) {
	// ...
}

void mouse_release(int window, int button, int x, int y, void* data) {
	// ...
}

int kickstart(int argc, char** argv) {
	kinc_init("Exercise 3", width, height, NULL, NULL);

	kinc_g1_init(width, height);
	kinc_set_update_callback(update, NULL);

	start_time = kinc_time();
	
	kinc_a1_init();

	memory_init();
	mesh = load_obj("bunny.obj");

	kinc_keyboard_set_key_down_callback(key_down, NULL);
	kinc_keyboard_set_key_up_callback(key_up, NULL);
	kinc_mouse_set_move_callback(mouse_move, NULL);
	kinc_mouse_set_press_callback(mouse_press, NULL);
	kinc_mouse_set_release_callback(mouse_release, NULL);

	kinc_start();

	return 0;
}
