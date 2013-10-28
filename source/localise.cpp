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

#include "localise.h"

const char * g_LocalisationEnglish[] = {
    "Score:",
    "Level:",
    "Game Over",
    "Orientation unsupported.\nPlease rotate your device.",
};

unsigned g_Current_Line = 0;
const unsigned g_Total_Lines = 32;
const char * g_Bootup_Sequence[] = {
	"(C) Copyright 1985 Fox Corporation, All Rights Reserved.",
	" ",
	"PatriotOS BIOS v0.5c - Build 02/08/85",
	"Revision v1.17 $ Timestamp 1985-08-02T16:45:42-0700",
	"Options: -rtmode -failsafe -vgaenbld",
	" ",
	"Detecting kernel version...",
	"Kernel: FoxLite v1.1.25 build 7741 rev4",
	"Testing interrupt controller... OK",
	"Interrupts enabled.",
	" ",
	"Unpacking OS image from flash... ",
	"Done.",
	" ",
	"Welcome to PatriotOS (C)",
	"System initialization in progress...",
	"Starting log activity...",
	" ",
	"[00:00:00] Log daemon task started.",
	"[00:00:01] Scheduling policy updated.",
	"[00:00:02] Testing graphics capabilities...",
	"[00:00:05] VGA detected: UI interaction enabled.",
	"[00:00:05] Testing sensors and actuators...",
	"[00:00:06] All systems responsive.",
	"[00:00:06] Scanning communication devices...",
	"[00:00:07] Communication system online.",
	"[00:00:09] Operator control enabled.",
	" ",
	">> Welcome to the new Patriot anti-ballistic missile defense system.",
	">> Shoot down as many missiles as you can.",
	">> Don't let them reach the city.",
	">> Good luck."
};

const char ** g_Localisation = g_LocalisationEnglish;
