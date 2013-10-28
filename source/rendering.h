/*
 * This file is part of the Marmalade SDK Code Samples.
 *
 * (C) 2001-2012 Marmalade. All Rights Reserved.
 *
 * This source code is intended only as a supplement to the Marmalade SDK.
 *
 * THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
 * KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
 * PARTICULAR PURPOSE.
 */

#ifndef _RENDERING_H
#define _RENDERING_H

#include "game.h"

// Foward declarations
class CIw2DImage;
class CIw2DFont;
class TitleScreen;

extern CIw2DFont* font;
extern CIw2DFont* fontLarge;

extern CIwSVec2 screen;

void CleanupImages();
void SetupImages();
void DrawTitleScreen(TitleScreen *title);
void DrawGameBackground();
void DrawGround();
void DrawBootSequence();
void DrawGameOverScreen();
void DrawScale(CIwFVec2 aim);

// Global variable used by the rendering functions to scale graphics.
extern int g_TileSize;

#endif /* !_RENDERING_H */
