#include <ansi.h>
#include <room.h>

inherit ROOM;

void create() 
{
    set("short", "���U�t�O");
    set("long", @LONG
�o�Ӧa�貧�`�H�N�A����]�S���A�u����������ť��ܫs�˪��۫ߡC
LONG);
    set("exits", ([ /* sizeof() == 2 */
       "north"  : "/u/b/byron/workroom2.c",  
       "down"   : "/world/area/jail.c",
       "wizard" : "/world/area/wizard/guildhall",
       "south"  : ([ "filename" : "/world/area/wizard/wizard.c",
                      "x_axis" : 35,
                      "y_axis" : 15, ])
    ]));
    set("no_clean_up", 0);
    setup();
    load_object("/daemon/board/byron");
}
private void goin(string arg, object me)
{
    if( arg != "" ) {
        if( arg[0] == 'y' || arg[0] == 'Y' ) {
            tell_object(me, HIK"\n�A���T�S���Y��...�M�w�h�ʺ��Y�c���C\n"NOR);
            this_player()->move("/world/area/jail.c");
            return;
        } else if( arg[0] == 'N' || arg[0] == 'n' ) {
            tell_object(me, HIW"\n�A�Q�F�Q�٬O�M�w���i�h�F�C\n"NOR);
            return;
        }
    }
    tell_object(me, HIR"\n���U���O�ʺ����a�I�A�T�w�n�i�h�H"HIW"(Y/n)"NOR);
    input_to("goin", me);
    return;
}
int valid_leave(object me, string dir, string arg)
{
    if( !me ) return 0;
    if( !wizardp(me) && dir == "north" ) {
        return notify_fail("���̥u���Ův�~��i�h\n");
    }
    if( dir == "down" ) {
        if( !userp(me) ) return 0;
        tell_object(me, HIR"���U���O�ʺ����a�I�A�T�w�n�i�h�H"HIW"(Y/n)"NOR);
        input_to("goin", me);
        return notify_fail("");
    }
    return ::valid_leave(me, dir);
}
