#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "���s�}�f");
    set("long", @long
�e�������s�}���A�u���@���e�Ǥ@�H���p�|�A�|�Y�����ݬO�Ӧa
�U�D�A���O�J�f�ﺡ�F���s�������ۡA�i��y�L�@�ʴN�|�v�T����
���s���[�c�A�p�G�Q�n�ʳo�ǩ��ۡA�i�n�n�n�Ҽ{�M���F�C
long);
    set("exits", ([
        "south" : ([ "filename": __DIR__"fire_isle.c",
                      "x_axis": 10,
                      "y_axis": 6,
                 ]),
    ]));
    set("detail", ([
        "����": "���ӥi�H��(dig)�}�a...���L�|�������G�O...",
    ]));
    setup();
}
void init()
{
    add_action("do_push", "dig");
}
int do_push(string arg)
{
    object mob, area;
    string area_file = "/world/area/lv60_area/fire.c";

    if( query("FIRE_WAR") != 0 ) return notify_fail("���s�}���w�g�Y��F�C\n");
    if( this_player()->query_level() < 21 ) return notify_fail("�A�ڥ��S�x�l�h���o�����ۡC\n");
    if( arg == "����" ) {
        message_vision("$N�N�j���Y�h�}��A�ΤO�©��۳��������I\n", this_player());
        message_vision(HIK"�u�����۩��M�P�ʤF�A$N��ӤH���i�}�̥h��...\n"NOR, this_player());

        if( !objectp(area = load_object(area_file)) ) return 0;
        if( !area->is_area() ) return 0;
        if( !area_move(area, this_player(), 1+random(19), 1+random(19)) ) return 0;

        this_player()->start_busy(1);
        set("FIRE_WAR", 1);
        WAR_D->doStartWar(this_player(), "/world/war/fire_die.c");
        call_out("push_1", 600, this_object());
        return 1;
    }
    return notify_fail("�A�Q������F��H\n");
}
void push_1(object ob)
{
    delete("FIRE_WAR");
    message_vision("���s�g�L�z�o�P���s��n�A���G�S�^�칡�M���A�F�C\n"NOR, ob);
    return;
}
