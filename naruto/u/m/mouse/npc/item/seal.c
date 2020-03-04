#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(HIY"��ů�"NOR, ({ "seal" }));
    if( !clonep() ) {
        set("unit", "�i");
        set("value", 0);
        set("weight", 5);
        set("long", "����g�۩_�Ǥ�r���ȱi�C");
    }
    setup();
}
void init()
{
    add_action("do_spell", "spell");
}
int do_spell(string arg)
{
    string npc;
    object ob, zombie;

    if( !arg ) return notify_fail("���O�榡: spell on <����> \n");
    if( sscanf(arg, "on %s", npc) !=1 ) return notify_fail("���O�榡: spell on <����> \n");

    if( !(ob = present(npc, environment(this_player()))) ) return notify_fail(HIR"�o�̨S��"NOR+npc+HIR"�o���H���C\n"NOR);
    message_vision(HIR"$N������������M��j�ۤ@�n�G�u���p�ߥO�I�v�K�N"NOR""HIY"�ů�"NOR""HIR"�K�b"NOR+ob->name()+HIR"�Y�W�C\n"NOR, this_player());
    if( !ob->is_corpse()) {
        message_vision("���L�èS���o�ͥ���Ʊ��C\n"NOR, this_object());
        tell_object(this_player(),HIK"�]�������D����ϥΩҥH�ůȮ����F...\n"NOR);
        destruct(this_object());
        return 1;
    }
    if( ob->query("userp") >=1 ) {
        message_vision("���L�èS���o�ͥ���Ʊ��C\n"NOR, this_object());
        tell_object(this_player(),HIG"����缾�a������ϥΦ��ůȡC\n"NOR);
        return 1;
    }
    if( ob->query("no_zombie") >=1 ) {
        message_vision("���L�èS���o�ͥ���Ʊ��C\n"NOR, this_object());
        tell_object(this_player(),HIG"�w�g�����L���F�褣��A�״_���C\n"NOR);
        return 1;
    }
    zombie = new("/u/m/mouse/npc/zombie.c");
    if( !objectp(zombie) ) {
        write("�o�i�ůȬO������A�Q�A�աI\n");
        destruct(this_object());
        return 1;
    }
    if( environment(this_player())->is_area() ) {
        if( !area_move(environment(this_player()), zombie, this_player()->query("area_info/x_axis"), this_player()->query("area_info/y_axis")) ) {
            message_vision("�L�����M���F�_�ӡA���O�ܧ֤S�ˤF�U�h...\n"NOR, this_object());
            destruct(zombie);
            destruct(this_object());
            return 1;
        }
    } else {
        if( !zombie->move(environment(this_player())) ) {
            message_vision("�L�����M���F�_�ӡA���O�ܧ֤S�ˤF�U�h...\n"NOR, this_object());
            destruct(zombie);
            destruct(this_object());
            return 1;
        }
    }
    zombie->set_name(ob->query("victim_name") + "���L��", ({ ob->query_id() + "'s zombie",  "zombie" }));
    message_vision("$N�Y�W��ůȪ��r���M�o�X�����A�u��$N�ߨ诸�F�_�Ӹ��H$n�C\n"NOR, zombie, this_player());

    // ����
    zombie->set("level", ob->query("level"));
    zombie->set("gender", ob->query("gender"));
    zombie->set("age", ob->query("age"));

    // �������A�O�q�H���B���C�ӱ��B���z
    zombie->set_attr("str", zombie->query("level")*(random(2)+2));
    zombie->set_attr("con", zombie->query("level")*(random(2)+4));
    zombie->set_attr("dex", zombie->query("level")/(random(1)+1)+10);
    zombie->set_attr("int", zombie->query("level")/(random(3)+1)+5);

    // ��O���ӵ��ť[��
    zombie->set_stat_current("ap", zombie->query("level")*30);
    zombie->set_stat_maximum("ap", zombie->query("level")*30);
    zombie->set_stat_current("hp", zombie->query("level")*50);
    zombie->set_stat_maximum("hp", zombie->query("level")*50);
    zombie->set_stat_current("mp", zombie->query("level")*20);
    zombie->set_stat_maximum("mp", zombie->query("level")*20);

    // skill����
    zombie->set_skill("continual hit", zombie->query("level")*2);
    zombie->set_skill("savage hit", zombie->query("level")*4);
    zombie->set_skill("heavy hit", zombie->query("level")*3);
    zombie->set_skill("combat", zombie->query("level")*4);
    zombie->set_skill("parry", zombie->query("level")*4);
    zombie->set_skill("dodge", zombie->query("level")*2);

    // �R���򥻥\
    zombie->delete_skill("ninja");
    zombie->delete_skill("force");
    zombie->delete_skill("magic");
    zombie->delete_skill("strength");
    zombie->delete_skill("concrete");
    zombie->delete_skill("special");
    zombie->delete_skill("operation");
    zombie->delete_skill("emit");
    zombie->delete_skill("variation");

    // ���H & �O�@�D�H
    zombie->guard_ob(this_player());
    zombie->set_leader(this_player());

    destruct(ob);
    destruct(this_object());
    return 1;
}
