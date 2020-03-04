#include <npc.h>
#include <ansi.h>

inherit F_SOLDIER;

void create()
{
    set_name("�X���P", ({ "dang ge pi", "pi" , "__GUARD__" }) );

    set_class("superior");  // �W��
    set_level(55);

    set("title", "���~���˦u��");

    set("long", "�@�Ӧu�@�����~���˪��W�ԡA����������H�~���i�h�A�]�O�@�H��\n"
                "�������~���˸̪����~�����C\n");

    // �u�ۥX�f
    set("guard_exit", ({"east", "northeast", "southeast"}));

    // �@���G����
    set("vendetta_mark", "wizard");

    setup();

    // �H���������ޯ�]�w
    set_skill("dodge", 200);               // �򥻡G �j�קޥ�
    set_skill("parry", 200);               // �򥻡G ���m�ޥ�
    set_skill("combat", 200);              // �򥻡G �氫�ޥ�
    set_skill("savage hit", 200);          // �򥻡G ����
    set_skill("heavy hit", 200);           // �򥻡G ����
    set_skill("force", 200);               // �򥻡G ��N
    set_skill("ninja", 10);                // �򥻡G �ԳN
    set_skill("magic", 10);                // �򥻡G �۳N
}

int do_guard_exit(int x, int y, string exit)
{
    object me, area;
    string area_file = "/world/area/god_forest/god_1.c";

    me = this_player();

    if( !objectp(area = load_object(area_file)) ) return 0;
    if( !area->is_area() ) return 0;
    if( !userp(me) || me->query_level() < 35 ) {
        message_vision("$n����N$N�d��C\n", me, this_object());
        do_chat((: command, "say ���~�˪L�̪����~���c�o�ܡA�A�̦n�O�i�h�C":));
    } else {
        message_vision("$n���D�R"HIG"�J�M$N�w�g���p����O�A�ڤ]������$N�i�J�F�C\n"NOR, me, this_object());
        message_vision(CYN"\n$n����o�X�ť��A�N$N�����e�i�F���~�˪L�C\n\n", me, this_object());
        if( !area_move(area, me, 1, 29) ) return 0;
    }
    return 1;
}

int accept_fight(object ob)
{
    do_chat((: command, "say ��Z�H�ڥi�S�šA�A�h��O�H�ոէa�C":));
    return 0;
}
