#include <npc.h>
#include <ansi.h>

void to_do_say()
{
    do_chat( ({
        (: command, "say ���F���P���b�������ʡC" :),
        (: command, "say �C�ѳ��n�X���h�h�������G�C" :),
        (: command, "sweat" :),
    }) );
}
void create()
{
    set_name("����", ({ "fish father", "father" }) );
    set_race("human");
    set_level(10);
    set("nickname", HIG"��������"NOR);
    set("age", 41);
    set("long", "�@��ͬ��b���������H�A�����D�L���s�ө~�O�����]�H\n");
    set("chat_chance", 1);
    set("chat_msg", ({
        (: to_do_say :),
    }));
    setup();
}
