#pragma once


// Track the state of normal keys
extern bool keyStates[256];

// Track the state of special keys
extern bool specialKeyStates[256];

extern bool mouseStates[256];

void MouseMovement(int x, int y);

