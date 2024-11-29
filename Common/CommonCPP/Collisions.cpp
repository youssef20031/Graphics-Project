#include "../CommonH/Player.h"
#include "../CommonH/Collisions.h"
#include "../../Level1/Level1H/Axe.h"

#include <algorithm>
#include <iostream>

/////////////////////////// PLAYER

bool checkCollision(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2Start, GLfloat x2End, GLfloat y2Start, GLfloat y2End, GLfloat z2Start, GLfloat z2End) {
	if (x2Start > x2End) std::swap(x2Start, x2End);
	if (y2Start > y2End) std::swap(y2Start, y2End);
	if (z2Start > z2End) std::swap(z2Start, z2End);
	GLfloat playerXStart = x1 - playerWidth / 2;
	GLfloat playerXEnd = x1 + playerWidth / 2;
	GLfloat playerYStart = y1;
	GLfloat playerYEnd = y1 + playerHeight;
	GLfloat playerZStart = z1 - playerWidth / 2;
	GLfloat playerZEnd = z1 + playerWidth / 2;
	bool xOverlapping = ((x2Start <= playerXStart && playerXStart <= x2End) ||
		(x2Start <= playerXEnd && playerXEnd <= x2End) ||
		(playerXStart <= x2Start && x2Start <= playerXEnd) ||
		(playerXStart <= x2End && x2End <= playerXEnd));
	bool yOverlapping = ((y2Start <= playerYStart && playerYStart <= y2End) ||
		(y2Start <= playerYEnd && playerYEnd <= y2End) ||
		(playerYStart <= y2Start && y2Start <= playerYEnd) ||
		(playerYStart <= y2End && y2End <= playerYEnd));
	bool zOverlapping = ((z2Start <= playerZStart && playerZStart <= z2End) ||
		(z2Start <= playerZEnd && playerZEnd <= z2End) ||
		(playerZStart <= z2Start && z2Start <= playerZEnd) ||
		(playerZStart <= z2End && z2End <= playerZEnd));
	return xOverlapping && yOverlapping && zOverlapping;
}

// checks if player's new change in position would collide (overlap) any of the obstacles
bool isColliding(GLfloat deltaX, GLfloat deltaY, GLfloat deltaZ) {
	// calculate new coords
	GLfloat centerX = playerX + deltaX;
	GLfloat centerY = playerY + deltaY;
	GLfloat centerZ = playerZ + deltaZ;
	for (int i = 0; i < L1numberOfObstacles; i++)
	{
		GLfloat* currentObstacle = L1obstacles[i];
		if (checkCollision(centerX, centerY, centerZ, currentObstacle[0], currentObstacle[1], currentObstacle[2], currentObstacle[3], currentObstacle[4], currentObstacle[5])) {
			return true;
		}
	}
	return false;
}


/////////////////////////////////// AXE

bool checkAxeCollision(Axe& axe, GLfloat playerX, GLfloat playerY, GLfloat playerZ, GLfloat playerWidth, GLfloat playerHeight) {
	GLfloat rotatedX = axe.GetPosX() * cos(axe.GetRotY()) - axe.GetPosZ() * sin(axe.GetRotY());
	GLfloat rotatedZ = axe.GetPosX() * sin(axe.GetRotY()) + axe.GetPosZ() * cos(axe.GetRotY());
	GLfloat rotatedY = axe.GetPosY(); 

	return checkCollision(playerX, playerY, playerZ,
		rotatedX - axe.GetWidth() / 2.0f, rotatedX + axe.GetWidth() / 2.0f,
		rotatedY - axe.GetHeight() / 2.0f, rotatedY + axe.GetHeight() / 2.0f,
		rotatedZ - axe.GetWidth() / 2.0f, rotatedZ + axe.GetWidth() / 2.0f);
}


void handleAxeCollision() {
	if (checkAxeCollision(axe, playerX, playerY, playerZ, playerWidth, playerHeight)) {
		std::cout << "Collision Occured" << std::endl;


		playerX = -21.5;
		playerY = 0.1;
		playerZ = 48.25;


	}
}
