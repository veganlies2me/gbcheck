#include <gbdk/platform.h>
#include <stdio.h>
extern uint8_t _is_GBA;
void main()
{
    // Wait 4 frames
    // For PAL SNES(SGB) this delay is required on startup
    for (uint8_t i = 4; i != 0; i--)
        wait_vbl_done();
    //We make sure we print the messages if the ROM is not run on a Super Game Boy
    if (_cpu == DMG_TYPE && !sgb_check())printf("This is a DMG! (OG Game Boy)");
    else if (_cpu == DMG_TYPE && sgb_check())printf("This is a SGB1!");
    else if (_cpu == MGB_TYPE && !sgb_check())printf("This is a MGB! (Game Boy Pocket / Light)");
    else if (_cpu == MGB_TYPE && sgb_check())printf("This is a SGB2!");
    else if (_cpu == CGB_TYPE && !_is_GBA && !sgb_check())printf("This is a CGB! (Game Boy Color)");
    //The GBA acts like a Game Boy Color. Adding !_is_GBA will make sure this only shows on a GBC
    if(_is_GBA)printf("This is a GBA!");
}