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

#ifndef _LOCALISE_H
#define _LOCALISE_H

// Very simple localisation support
// To get a string in code, use g_Localisation[ID_xxx]
enum LocalisationIDs
{
    ID_SCORE,
    ID_LEVEL,
    ID_GAME_OVER,
    ID_UNSUPPORTED_ORIENTATION,
};

extern const char ** g_Localisation;
extern const char * g_Bootup_Sequence[];
extern unsigned g_Current_Line;
extern const unsigned g_Total_Lines;

#endif /* !_LOCALISE_H */
