#include <npc.h>
#include <ansi.h>

inherit F_VILLAGER;

void create()
{
    set_name(HIW"���H"NOR, ({ "servant" }));
    set_race("human");
    set_level(50);
    set("age", 16);
    set("long", "�󼯮a���a���A�C�ѳ��������y���I�C\n");
    set("gender", "female");                                 //�ʧO
    set("chat_chance", 0);    // �İ� �n�w�R��
    set("chat_msg", ({
        HIW"���H"NOR+CYN"���W����z�����ҡC\n"NOR,
        HIW"���H"NOR+CYN"�y�L�𮧵ۡC\n"NOR,
    }));
    setup();
    carry_object(__DIR__"eq/worker/cloth.c")->wear();
}
void init()
{
    int i;
    if( this_player()->id("mouse") && userp(this_player()) ) {
        i = random(3);
        if( i == 2) {
            do_chat((: command, "say �w��^�ӡA�D�H�C" :));
            return;
        } else
        if( i == 1) {
            do_chat((: command, "say �O�A�s�yż�äF���D�H�C" :));
            return;
        } else
        if( i == 0) {
            do_chat((: command, "sweat " + this_player()->query("id") :));
            return;
        }
    } else
    if( userp(this_player()) ) {
        i = random(5);
        if( i == 4) {
            do_chat((: command, "say �w��Ө칫���p�ۡC" :));
            return;
        } else
        if( i == 3) {
            do_chat((: command, "say ���Iż�ýЧO���N�C" :));
            return;
        } else
        if( i == 2) {
            do_chat((: command, "sweat" :));
            return;
        } else
        if( i == 1) {
            do_chat((: command, "say ���H�K���C" :));
            return;
        } else
        if( i == 0) {
            do_chat((: command, "courtesy" :));
            return;
        }
    }
    return;
}
int accept_fight(object ob)
{
    do_chat(HIW"���H"NOR"�ͮ𪺻��R"HIG"���־�z�����F�٧�ڥ��[�I"NOR"\n");
    return 0;
}
