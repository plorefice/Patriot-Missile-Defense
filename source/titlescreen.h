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

#ifndef _TITLESCREEN_H
#define _TITLESCREEN_H

#include "s3eKeyboard.h"
#include "s3ePointer.h"
#include "s3eDevice.h"

class TitleScreen
{
private:
    int timer;

public:
	CIwFVec2 btnDim, btnTopLeft;

public:
    TitleScreen()
    {
        timer = 0;

		btnDim.x = 200.0f;
		btnDim.y = 80.0f;

		btnTopLeft.x = (screen.x - btnDim.x)/2;
		btnTopLeft.y = (screen.y - btnDim.y)/2 + 80;
    }

    void Update(int deltaTimeMs)
    {
        timer += deltaTimeMs;

        if ((s3eKeyboardGetState(s3eKeyAbsBSK) & S3E_KEY_STATE_PRESSED) ||
			(s3eKeyboardGetState(s3eKeyEsc) & S3E_KEY_STATE_PRESSED) || 
			(s3eKeyboardGetState(s3eKeyBack) & S3E_KEY_STATE_PRESSED)
			)
        {
            s3eDeviceRequestQuit();
        }

        if (PlayButtonPressed())
        {
            g_GameMode = MODE_GAMEPLAY;
        }
    }

    void Render()
    {
		DrawTitleScreen(this);
    }

	bool PlayButtonPressed()
	{
		int x = s3ePointerGetX();
		int y = s3ePointerGetY();

		if ((s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) & S3E_POINTER_STATE_PRESSED)
			&& (x >= btnTopLeft.x && x <= btnTopLeft.x + btnDim.x)
			&& (y >= btnTopLeft.y && y <= btnTopLeft.y + btnDim.y))
		{
			return true;
		}

		return false;
	}
};

#endif /* !_TITLESCREEN_H */
