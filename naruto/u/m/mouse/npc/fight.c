#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("���վԯ�", ({ "fight man", "man" }));
    set_race("human");
    set("long", "�@��M���ΨӴ��ժ��ƻs�H�C\n");
    setup();
}
void relay_say(object ob, string arg)
{
    string adv;
    int i;
    if( !arg || sscanf(arg, "%s %d", adv, i) != 2 ) return 0;
    if( wizardp(this_player()) ) {
        if( adv == "��O" ) {
            this_object()->add_temp("apply/attack", i);
            message_vision("$N���D�G"HIG"�W�["+adv+"��O("HIW+i+HIG")�I�����C\n"NOR, this_object());
        } else
        if( adv == "���O" ) {
            this_object()->add_temp("apply/armor", i);
            message_vision("$N���D�G"HIG"�W�["+adv+"��O("HIW+i+HIG")�I�����C\n"NOR, this_object());
        } else
        if( adv == "�R��" ) {
            this_object()->add_temp("apply/exact", i);
            message_vision("$N���D�G"HIG"�W�["+adv+"��O("HIW+i+HIG")�I�����C\n"NOR, this_object());
        } else
        if( adv == "�j��" ) {
            this_object()->add_temp("apply/evade", i);
            message_vision("$N���D�G"HIG"�W�["+adv+"��O("HIW+i+HIG")�I�����C\n"NOR, this_object());
        } else
        if( adv == "���" ) {
            this_object()->add_temp("apply/intimidate", i);
            message_vision("$N���D�G"HIG"�W�["+adv+"��O("HIW+i+HIG")�I�����C\n"NOR, this_object());
        } else
        if( adv == "����" ) {
            this_object()->add_temp("apply/wittiness", i);
            message_vision("$N���D�G"HIG"�W�["+adv+"��O("HIW+i+HIG")�I�����C\n"NOR, this_object());
        } else
        if( adv == "����" ) {
            this_object()->add_temp("apply/move", i);
            message_vision("$N���D�G"HIG"�W�["+adv+"��O("HIW+i+HIG")�I�����C\n"NOR, this_object());
        } else
        if( adv == "�t��" ) {
            this_object()->add_temp("apply/carriage", i);
            message_vision("$N���D�G"HIG"�W�["+adv+"��O("HIW+i+HIG")�I�����C\n"NOR, this_object());
        }
    }
}
void unconcious()
{
    this_object()->die();
    return;
}
void die()
{
    message_vision(HIW"\n$N�ե��@�{�A���M�a�N�����b�A���e�F�C\n"NOR, this_object());
    destruct(this_object());
    return;
}
