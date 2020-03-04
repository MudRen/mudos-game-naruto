#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(HIY"�׸�"HIW"�u���"NOR, ({ "the wizard's object", "object" }));
    if( !clonep() ) {
        set("unit", "�c");
        set("value", 0);
        set("weight", 1);
        set("long", "�׸� lv41 �ɯŨS�[��O�Ϊ��u��A�Ф��H�N�ϥΡC"NOR);
    }
    setup();
}
void init()
{
    add_action("do_add", "addd");
}
int do_add(string arg)
{
    string npc;
    object ob;

    if( this_player()->query_id() != "mouse" || !wizardp(this_player()) )  return notify_fail("�A�S���v�Q�ϥγo�˪��~�C\n");
    if( !arg ) return notify_fail("���O�榡: addd on <�Y�H> \n");
    if( sscanf(arg, "on %s", npc) !=1 ) return notify_fail("���O�榡: addd on <�Y�H> \n");

    ob = LOGIN_D->find_body(npc);
    if(!ob) return notify_fail("�u�W�S�� "HIY+npc+NOR" �o���H���C\n"NOR);

    message_vision("$N"CYN"�q"NOR"$n"CYN"�����X�@�靈���S���u��A���"NOR+ob->query("name")+CYN"�����a�V�V����...\n"NOR, this_player(), this_object());
    if( !ob->is_character() || ob->is_corpse() || !userp(ob)) {
        message_vision(HIR"���L�èS���o�ͥ���Ʊ��C\n"NOR, this_object());
        tell_object(this_player(),HIR"\n�����n�G�ڤ���״_�D�ͩR���F��C\n"NOR);
        return 1;
    }
    message_vision(CYN"�S�h�["NOR+ob->query("name")+CYN"�N�ܪ��صM�@�s�F�I\n"NOR, this_player(), this_object());
    ob->add_point("score", 150);
    ob->add_point("attribute", 4);
    ob->add_point("skill", 2);

    log_file("lv41update", sprintf("[%s] %s(%s) �ץ� %s(%s) ���Ŵ��ɥ��W�[����O�C\n", ctime(time())[0..15], this_player()->query("name"), this_player()->query_id(), ob->query("name"), ob->query_id()) );

    return 1;
}
