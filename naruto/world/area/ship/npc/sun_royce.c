#include <ansi.h>
#include <npc.h>

inherit F_SEABANDIT;

void create()
{
    set_name("���M", ({ "royce" }) );
    set_race("human");
    set_level(22);
    set("title", HIR"�T���"NOR);
    set("nickname", HIM"���J�O"NOR);
    set("gender", "male");
    set("class", "little_sea");
    set("camp", "robber");
    set("age", 42);
    set("long", "�T�ܭW�y������A���G���b�дo����Ʊ��C\n");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: command, "say �u����v�A�̶]���h�F�I���n��U�ڪ��I" :),
        (: command, "say �o�̳��O�L�;u�\...�~���ڤF Q__Q" :),
    }));
    set("set_drop", ({
        ([ "type":"obj", "id":127, "amount":1, "p1":10, "p2":100 ]),   // �ۦ�
    }) );
    setup();
    carry_object("/world/area/thorn_pine/npc/wp/long_hook.c")->wield();
    carry_object("/world/area/thorn_pine/npc/wp/long_hook.c")->wield("lefthand");
}

void relay_say(object ob, string arg)
{
    if( arg == "���" )  {
        do_chat(({
            (: command, "cry" :),
            (: command, "say ���Ѹ������_�èӨ�o�̡C" :),
            (: command, "say �ݨ�o�ӤѬi�ڭ̴N�T�H�_�ä@�w�b�̭��C" :),
            (: command, "say ���L�Ѭi�W���Ʀr...�@�몫�~�ڥ��񤣤U�C" :),
            (: command, "say �ҥH�ڭ̱N�����i����...�άO��U�a���F�l�Ӹ�..." :),
            (: command, "say ���G�o���񭷤ӱj�F...���ީ񤰻�F�賣�Q�j��..." :),
            (: command, "say ���������X�@�]�ǯ������A�~�M�S�Q�j���I" :),
            (: command, "say ����@���İ_�ӴN�a�ۤj�a���}�F..." :),
            (: command, "say �ڦ^�Ѭi�W���������]�ǯ��A�S�Q�����L�̤w�g���F�I" :),
            (: command, "say ����A�̦b���̪��I" :),
            (: command, "cry" :),
        }));
        return;
    }
}
