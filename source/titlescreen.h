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
    TitleScreen()
    {
        timer = 0;
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

		return true;
	}
};

#endif /* !_TITLESCREEN_H */
