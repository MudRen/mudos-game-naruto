#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(HIR"���]"HIW"�o�e��"NOR, ({ "Cash Robot", "cash", "robot" }));
    if( !clonep() ) {
        set("unit", "��");
        set("value", 0);
        set("weight", 1);
        set("long", "�@�ƭ��~�Ҽ˪������H�A�M���o"HIY"(send to �Y�H)"NOR"���]�ΡC");
    }
    setup();
}
void init()
{
    add_action("do_send", "send");
}
int do_send(string arg)
{
    string npc;
    object ob, fm;

    if( !arg ) return notify_fail("���O�榡: send to <�Y�H> \n");
    if( sscanf(arg, "to %s", npc) !=1 ) return notify_fail("���O�榡: send to <�Y�H> \n");

    ob = LOGIN_D->find_body(npc);
    if(!ob) return notify_fail(HIR"�u�W�S�� "NOR+npc+HIR" �o���H���C\n"NOR);
    message_vision("$N���X$n��J"HIW+ob->name()+NOR"���W�r�A$n���M�o�X�@�}ģ�������~�I\n"NOR, this_player(), this_object());
    if( !ob->is_character() || ob->is_corpse() || !userp(ob)) {
        message_vision("���L�èS���o�ͥ���Ʊ��C\n"NOR, this_object());
        tell_object(this_player(),HIR"�����n�G�ڤ���N���~�e���D���a���H�C\n"NOR);
        return 1;
    }
    fm = new("/u/m/mouse/npc/item/red.c");
    if( !objectp(fm) ) {
        write(HIR"�����n�G���]�U�a���F�I�L�k�o�e�I\n"NOR);
        return 1;
    }
    if( environment(this_player())->is_area() ) {
        if( !area_move(environment(this_player()), fm, this_player()->query("area_info/x_axis"), this_player()->query("area_info/y_axis")) ) {
            message_vision(HIR"��۸t�ϸ˪��ѭ��~"NOR"���D�G"HIG"�ڦn���ӿ��a��F�H\n"NOR, this_object());
            destruct(fm);
            return 1;
        }
    } else {
        if( !fm->move(environment(this_player())) ) {
            message_vision(HIR"��۸t�ϸ˪��ѭ��~"NOR"���D�G"HIG"�ڦn���ӿ��a��F�H\n"NOR, this_object());
            destruct(fm);
            return 1;
        }
    }
    if( fm->move(ob) ) {
        message_vision(HIY"�@����~�Ҽ˪��H�b�����U�{���A���F�y"HIW"�u���ߵo�]�v"HIY"��N"NOR"$N"HIY"�浹�F$n�C\n"NOR, fm, ob);
    } else if( fm->move(environment(ob)) ) {
        message_vision(HIY"�@����~�Ҽ˪��H�b�����U�{���A���F�y"HIW"�u���ߵo�]�v"HIY"��N"NOR"$N"HIY"��b$n�}��C\n"NOR, fm, ob);
    } else {
        destruct(fm);
        return 0;
    }
    return 1;
}
