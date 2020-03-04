#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",HIC"���Ť���"NOR);
    set("long", @long
�򭱼�b�S���@�I�岫�A�M��������ϩ��i�H�ݨ��򩳡A�]����
�B������R���A��K���ڳ��]�S�O�ʤj�A���O�o�u��¶�۴���l����
���Ӥ��g�V�򭱡A�٦��K���N�������}�϶����Ө��W�A�n�����ͩR
��a�b�������y�̨Ϊ���ı���[�C�ֳ\�������Ӯg��򭱻P���W�S
�]�Φ��}�G���m���A�󬰳o���p�P�Ҫ��a���W�K�F���֬��P�Cı�o
�f���i�H�N�a���δ���A�]�\�����򯫩_���ĪG��C
long);
    set("exits", ([
        "north" : __DIR__"forest0.c",
        "south" : __DIR__"forest0.c",
        "west" : __DIR__"forest0.c",
        "east" : __DIR__"forest0.c",
    ]));
    set("detail", ([
        "���": HIB"�M��������A�i�H����(drink)�C"NOR,
    ]));
    set("no_recall", 1);
    set("no_fight", 1);
    setup();
}
void init()
{
    add_action("do_drink", "drink");
}
int do_drink(string arg)
{
    mapping cnd = ([]), weapons;
    string skill;
    object ob;

    if( arg == "���") {
        if( this_player()->query_condition("blue_lake", 1) != 0 ) {
            tell_object(this_player(), HIB"�ӳg�ߤF�a�A�A�ܥi��|�Q�ᦨ�B�H��I\n"NOR);
            return 1;
        }
        if( mapp(weapons = this_player()->query_temp("weapon")) && sizeof(weapons) ) {
            foreach(skill, ob in weapons) ob->unequip();
        }
        message_vision(CYN"$N�N�Z����U���X�����_����A�B�P�B�P���ܤF�X�f�C\n"NOR, this_player());
        tell_object(this_player(), HIC"(�z�E�ߡE�D�I�������Pı���A²���n���W�ѤF�I)\n"NOR);

        cnd["name"] = HIC"�z�߲D"NOR;
        cnd["duration"] = 100;

        this_player()->set_condition("blue_lake", cnd);
        return 1;
    }
}
int valid_leave(object me, string dir)
{
    object mob;
    if( !me ) return 0;
    if( userp(me) && (dir == "west" || dir == "east" || dir == "south" || dir == "north" ) ) {
        message_vision("$N�̨̤��˦a���}�F�o�̡C\n", this_player());
        me->start_busy(1);
        call_out("oldtree", 2, me);
    }
    return notify_fail("");
}
void oldtree(object me)
{
    string area = __DIR__"forest"+random(20)+".c";
    me->move(area);
}
