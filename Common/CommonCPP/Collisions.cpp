#include "../CommonH/Player.h"
#include "../CommonH/Collisions.h"
#include "../../Level1/Level1H/Axe.h"

#include <algorithm>
#include <iostream>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

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

	GLfloat (*obstacles)[6] = L1obstacles;
	int numberOfObstacles = L1numberOfObstacles;

	if (level == 2) {
		obstacles = L2obstacles;
		numberOfObstacles = L2numberOfObstacles;
	}

	for (int i = 0; i < numberOfObstacles; i++)
	{
		GLfloat* currentObstacle = obstacles[i];
		if (checkCollision(centerX, centerY, centerZ, currentObstacle[0], currentObstacle[1], currentObstacle[2], currentObstacle[3], currentObstacle[4], currentObstacle[5])) {
			GLfloat high = currentObstacle[2];
			GLfloat low = currentObstacle[3];
			if (high < low) {
				high = low;
				low = currentObstacle[2];
			}
			if (deltaY != 0) {
				// make player move with the horizontally moving platform
				handleMovingPlatformHorizontal();

				// make player slide if standing on slippery ground
				handleSlipperyFloor();

				// player on top of object and platform is moving
				if (playerY != high && (playerY + playerHeight) >= low) {
					playerY = high + 0.001f;
					// update camera as well
					if (viewMode == FIRST_PERSON) {
						setFirstPersonCamera();
					}
					if (viewMode == THIRD_PERSON) {
						setThirdPersonCamera();
					}
					isPlayerJumping = false;
				}
			}

			return true;
		}
	}
	return false;
}


/////////////////////////////////// AXE

bool checkAxeCollision(Axe& axe) {
	GLfloat halfLength = axe.GetLength() / 2;
	GLfloat lengthStart = halfLength + 1.0f;
	GLfloat lengthEnd = halfLength - 1.0f;
	GLfloat thetaStart = axe.GetRotY();
	GLfloat thetaEnd = axe.GetRotY() - 20.0;
	GLfloat x = axe.GetPosX();
	GLfloat y = axe.GetPosY();
	GLfloat z = axe.GetPosZ();
	GLfloat offsetYStart = lengthStart * cos(thetaStart * M_PI / 180);
	GLfloat offsetZStart = lengthStart * sin(thetaStart * M_PI / 180);
	GLfloat offsetYEnd = lengthEnd * cos(thetaEnd * M_PI / 180);
	GLfloat offsetZEnd = lengthEnd * sin(thetaEnd * M_PI / 180);

	return checkCollision(playerX, playerY, playerZ,
		x - 0.3, x + 0.3,
		y + offsetYStart, y + offsetYEnd,
		z + offsetZStart, z + offsetZEnd);
}


void handleAxeCollision(Axe& axe) {
	//std::cout << "Collision Occured" << std::endl;
	if (checkAxeCollision(axe)) {
		playerX = spawnPoint.x;
		playerY = spawnPoint.y;
		playerZ = spawnPoint.z; 

	
		PlaySound(TEXT("music/axe.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
}


// Horizontal Moving Platform
void handleMovingPlatformHorizontal() {
	// makes the player move with the moving platform
	if (level == 1 && -228 < playerX && playerX < -203) { //men x=-203 le7ad x=-227
		GLfloat obstacleCenterX = (L1obstacles[39][0] + L1obstacles[39][1]) / 2;
		playerX = obstacleCenterX;
	}
}


//// Collectible Collision
void handleCoinCollision(Collectible& coin) {
	float tolerance = 0.5f;

	if (!coin.IsCollected() &&
		fabs(playerX - coin.GetPosX()) <= tolerance &&
		fabs(playerY - coin.GetPosY()) <= tolerance &&
		fabs(playerZ - coin.GetPosZ()) <= tolerance) {

		coin.Collect();

		scoreL1 += 50;
	}
}


// level 2 stuff

void handleSlipperyFloor() {
	if (level == 2 && 25 < playerX && playerX < 49 && -20 < playerZ && playerZ < 35) {
		if (isMoving) {
			isSliding = true; // trigger sliding action
		}
	}
	else {
		isSliding = false;
	}
}

void handleChandelierCollision(Chandelier& chandelier) {
	float chandelierCenterX = chandelier.GetPosX();
	float chandelierCenterY = chandelier.GetPosY();
	float chandelierCenterZ = chandelier.GetPosZ();
	float chandelierSideLength = chandelier.getSideLength() / 2;

	float startX = chandelierCenterX - chandelierSideLength;
	float endX = chandelierCenterX + chandelierSideLength;
	float startZ = chandelierCenterZ - chandelierSideLength;
	float endZ = chandelierCenterZ + chandelierSideLength;
	float startY = chandelierCenterY;
	float endY = chandelierCenterY + 2.0f;
	float y = playerY + playerHeight;

	if (level == 2 && 
		startX < playerX && playerX < endX && 
		startZ < playerZ && playerZ < endZ && 
		startY < y && y < endY) {
		// kill the player - send him to Jesus

		playerX = spawnPoint.x;
		playerY = spawnPoint.y;
		playerZ = spawnPoint.z;
	}
}