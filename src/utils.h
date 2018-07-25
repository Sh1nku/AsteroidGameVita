#pragma once
#include "headers.h"

#define PI 3.141592


extern GLuint loadTexture(const char* name);

static int radToDeg(float rad) {
	int deg = rad*(180/PI);
	return deg;
}

static void gluPerspective(float fov, float aspectRatio, float zNear, float zFar) {
	float yMax, xMax;
	yMax = zNear * tanf(fov * PI / 360.0);
	xMax = yMax * aspectRatio;
	glFrustum(-xMax, xMax, -yMax, yMax, zNear, zFar);
}

static void DrawCircle(int triangles, float r) 
{ 
		float theta = 2.f * PI / (float)triangles;
		float c = (float) cosf(theta);
		float s = (float) sinf(theta);
		float t;

		float x = r;
		float y = 0; 
	    glBegin(GL_TRIANGLE_FAN);
		for(int i = 0; i < triangles; i++) 
		{ 
			glVertex2f(x, y);
			t = x;
			x = c * x - s * y;
			y = s * t + c * y;
		}
		glEnd();
}