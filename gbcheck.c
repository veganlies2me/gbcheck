#include <gbdk/platform.h>
#include <stdio.h>
extern uint8_t _is_GBA;
void main()
{
    //We make sure we print the messages if the ROM is not run on a Super Game Boy
    if (_cpu == DMG_TYPE && !sgb_check())printf("This is a DMG! (OG Game Boy)");
    else if (_cpu == MGB_TYPE && !sgb_check())printf("This is a MGB! (Game Boy Pocket / Light)");
    else if (_cpu == CGB_TYPE && !_is_GBA && !sgb_check())printf("This is a CGB! (Game Boy Color)");
    //The GBA acts like a Game Boy Color. Adding !_is_GBA will make sure this only shows on a GBC
    if (sgb_check()) printf("This is a SGB! (Super Game Boy 1/2)");
    if(_is_GBA)printf("This is a GBA!");
}