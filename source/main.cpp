#include "s3ePointer.h"
#include "s3eDevice.h"
#include <time.h>

#include "Iw2D.h"
#include "IwGx.h"
#include "IwResManager.h"

#include "game.h"
#include "rendering.h"
#include "localise.h"
#include "effects.h"
#include "titlescreen.h"


bool g_ScreenSizeChanged = true;

int32 ScreenSizeChangeCallback(void* systemData, void* userData)
{
    //g_ScreenSizeChanged = true;
    return 0;
}

void UpdateScreenSize()
{
    if (g_ScreenSizeChanged)
    {
        g_ScreenSizeChanged = false;

		IwGxScreenOrient t = IwGxGetScreenOrient();

		if (t == IW_GX_ORIENT_NONE ||
			t == IW_GX_ORIENT_180)
		{
			IwGxSetScreenOrient(IW_GX_ORIENT_270);
		}
		else 
		{
			IwGxSetScreenOrient(IW_GX_ORIENT_NONE);
		}

        font = Iw2DCreateFontResource("font");
        Iw2DSetFont(font);

		screen = CIwSVec2(IwGxGetScreenWidth(), IwGxGetScreenHeight());
    }
}


int main(int argc, char* argv[])
{
    Iw2DInit();
    IwResManagerInit();

    IwGetResManager()->LoadGroup("resources.group");

    UpdateScreenSize();
    s3eSurfaceRegister(S3E_SURFACE_SCREENSIZE, ScreenSizeChangeCallback, NULL);

	g_EffectsManager = new EffectManager;

    Game * game = new Game;
    TitleScreen * title = new TitleScreen;

    uint32 timer = (uint32)s3eTimerGetMs();

	IwGxSetColClear(0, 0, 0, 0xff);

    while (1)
    {
        s3eDeviceYield(0);

        if (s3eDeviceCheckQuitRequest())
            break;

        UpdateScreenSize();
		
		IwGxClear(IW_GX_COLOUR_BUFFER_F | IW_GX_DEPTH_BUFFER_F);

        int delta = uint32(s3eTimerGetMs()) - timer;
        timer += delta;

        if (delta < 0)
            delta = 0;
        if (delta > 100)
            delta = 100;

        UpdateInput(delta);

        if (g_GameMode == MODE_TITLE)
        {
            title->Update(delta);
            title->Render();

            if (g_GameMode == MODE_GAMEPLAY)
                game->Reset();
        }
        else
        {
            game->Update(delta);
            game->Render();
        }

        Iw2DSurfaceShow();
    }

    s3eSurfaceUnRegister(S3E_SURFACE_SCREENSIZE, ScreenSizeChangeCallback);

	delete g_EffectsManager;

    delete game;
    delete title;

    CleanupImages();

    IwResManagerTerminate();
    Iw2DTerminate();

    return 0;
}