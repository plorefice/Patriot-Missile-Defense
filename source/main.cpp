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


void SetupScreen()
{
	SetupImages();

    font = Iw2DCreateFontResource("font");
	fontLarge = Iw2DCreateFontResource("font_large");
    Iw2DSetFont(font);

	screen = CIwSVec2(IwGxGetScreenWidth(), IwGxGetScreenHeight());
}


int main(int argc, char* argv[])
{
    Iw2DInit();
    IwResManagerInit();

    IwGetResManager()->LoadGroup("resources.group");

    SetupScreen();

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

	delete g_EffectsManager;

    delete game;
    delete title;

    CleanupImages();

    IwResManagerTerminate();
    Iw2DTerminate();

    return 0;
}
