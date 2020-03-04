#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(HIC"�Ҷ�"HIW"�U��"NOR, ({ "imitate mirror", "mirror" }));
    if( !clonep() ) {
        set("unit", "��");
        set("value", 0);
        set("weight", 5);
        set("long", "�᯾�ӱK����l�A�W���B�ۤ@���r�u"HIR"copy on <�Y�H>"NOR"�v");
    }
    setup();
}
void init()
{
    add_action("do_copy", "copy");
}
int do_copy(string arg)
{
    string npc;
    object ob, fm;

    if( !arg ) return notify_fail("���O�榡: copy on <�Y�H> \n");
    if( sscanf(arg, "on %s", npc) !=1 ) return notify_fail("���O�榡: copy on <�Y�H> \n");

    ob = LOGIN_D->find_body(npc);
    if(!ob) return notify_fail(HIR"�u�W�S�� "NOR+npc+HIR" �o���H���C\n"NOR);
    message_vision("$N"HIY"���X"NOR"$n"HIY"��"NOR+ob->name()+HIY"�@�ӡA"NOR"$n"HIY"���M�o�X�@�}ģ�������~�I\n"NOR, this_player(), this_object());
    if( !ob->is_character() || ob->is_corpse() || !userp(ob)) {
        message_vision("���L�èS���o�ͥ���Ʊ��C\n"NOR, this_object());
        tell_object(this_player(),HIR"�����n�G�ڤ���ҥ�D�ͩR���F��C\n"NOR);
        return 1;
    }
    fm = new("/u/m/mouse/npc/fight.c");
    if( !objectp(fm) ) {
        write(HIR"�����n�G�]��������]�ϧڵL�k�ҥ�I\n"NOR);
        return 1;
    }
    if( environment(this_player())->is_area() ) {
        if( !area_move(environment(this_player()), fm, this_player()->query("area_info/x_axis"), this_player()->query("area_info/y_axis")) ) {
            message_vision("���~�����ܮz...�o�S�o�ͥ���ơC\n"NOR, this_object());
            destruct(fm);
            return 1;
        }
    } else {
        if( !fm->move(environment(this_player())) ) {
            message_vision("���~�����ܮz...�o�S�o�ͥ���ơC\n"NOR, this_object());
            destruct(fm);
            return 1;
        }
    }
    fm->set_name(ob->query("name")+"���ƻs�H", ({ "copy's "+ob->query_id(), "copy"}));
    message_vision("$N�q���~���{�ΡA�P"+ob->name()+"���ۦ��״X�G�ʤ����ʡC\n"NOR, fm, this_player());

    // ���ŻP���H�ۦP
    fm->set("level", ob->query("level"));
    fm->set("gender", ob->query("gender"));
    fm->set("age", ob->query("age"));

    // ���A�O�q�B�ӱ��B���z�P���H�ۦP
    fm->set_attr("str", ob->query_attr("str"));
    fm->set_attr("con", ob->query_attr("con"));
    fm->set_attr("dex", ob->query_attr("dex"));
    fm->set_attr("int", ob->query_attr("int"));

    // ��O�P���H�ۦP
    fm->set_stat_current("ap", ob->query_stat_current("ap"));
    fm->set_stat_maximum("ap", ob->query_stat_maximum("ap"));
    fm->set_stat_current("hp", ob->query_stat_current("hp"));
    fm->set_stat_maximum("hp", ob->query_stat_maximum("hp"));
    fm->set_stat_current("mp", ob->query_stat_current("mp"));
    fm->set_stat_maximum("mp", ob->query_stat_maximum("mp"));

    // skill�u�O�d���ɳs�B�氫�B��ۡB�{���P���H�ۦP
    fm->set_skill("continual hit", ob->query_skill("continual hit"));
    fm->set_skill("savage hit", ob->query_skill("savage hit"));
    fm->set_skill("heavy hit", ob->query_skill("heavy hit"));
    fm->set_skill("combat", ob->query_skill("combat"));
    fm->set_skill("parry", ob->query_skill("parry"));
    fm->set_skill("dodge", ob->query_skill("dodge"));

    // �R���򥻥\
    fm->delete_skill("ninja");
    fm->delete_skill("force");
    fm->delete_skill("magic");
    fm->delete_skill("strength");
    fm->delete_skill("concrete");
    fm->delete_skill("special");
    fm->delete_skill("operation");
    fm->delete_skill("emit");
    fm->delete_skill("variation");
    return 1;
}
