#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(HIR"�ݱ����O"NOR, ({ "kill all", "all" }));
    set_weight(1);
    if( !clonep() ) {
        set("unit", "��");
        set("value", 1);
        set("long", "�i�H�R�O���NPC���ۧ����C"HIR"(fkill mob1 with mob2)"NOR);
    }
    setup();
}
void init()
{
    add_action("do_fk", "fk");
}
int do_fk(string arg)
{
    string str, npc;
    object ob, me, obj;

    me = this_player();

    seteuid(getuid());
    if( !arg || sscanf(arg, "%s with %s", str, npc) != 2 )
        return notify_fail("���O�榡�Rfk <Mob> with <Mob>\n");

    if( !(ob = present(str, environment(me))) )
        return notify_fail(HIR"�o�̨S�� "NOR+str+HIR" �o���H���C\n"NOR);

    if( !(obj = present(npc, environment(me))) )
        return notify_fail(HIR"�o�̨S��"NOR+npc+HIR"�o���H���C\n"NOR);

    if( !ob->is_character() || !obj->is_character() )
        return notify_fail(HIY"��Ӫ��󤤦��䤤���@�L�k����R�O�C\n"NOR);

    if( userp(ob) || userp(obj) )
        return notify_fail(HIY"�Q�R�O�����褣�i�O���a�C\n"NOR);

    message_vision(HIR"$N�o�X���O��"NOR+ob->name()+HIR"�D�ʧ���"NOR+obj->name()+HIR"�I\n"NOR, me);
    ob->kill_ob(obj);
    obj->kill_ob(ob);
    return 1;
}
