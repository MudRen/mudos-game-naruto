#include <ansi.h>
#include <armor.h>

inherit F_CLOTH;

void create()
{
    set_name(HIW"�q�l"NOR+HIG"�Ԧ�"NOR, ({ "electorn cloth", "cloth" }));
    set_weight(500);
    setup_cloth();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 10);
        set("long", "���Ӳ����A�֦��԰����ɧU�^�_���\��C\n");
        set("wear_as", "cloth");
        set("wear_msg", "$n"HIM"�Ƭ����l���A�]��"NOR"$N"HIM"�A�C�C�Φ��@��X�����Ԧ�C\n"NOR);
        set("unequip_msg", "$n"HIM"�u���j�v�@�n�A�N�������}�H�뺥������"NOR"$N"HIM"�C\n"NOR);
        set("apply_armor/cloth", ([
            "exact": 500,
            "evade": 500,
            "intimidate": 500,
            "wittiness": 500,
            "carriage": 1000,
            "savage hit": 50,
            "continual hit": 50,
            "heavy hit": 50,
            "combat": 20,
        ]));
    }
    setup();
}
void init()
{
    add_action("do_wear", "wear");
}
int do_wear(string arg)
{
    call_out("fightheal_1", 10, this_player());
}
void fightheal_1()
{
    int i, heal;
    i = random(3);
    if( !this_object()->query("equipped")) {
        return;
    }
    if( !this_player()->is_fighting() ) {
        call_out("fightheal_1", 20, this_player());
        return;
    }
    if( i == 0) {
        heal = random(130)+20;
        message_vision("\n$N"HIC"�o�X�}�}���~�A���G�^�_�F"NOR"$n"HIC"���믫�C("+heal+")\n\n"NOR, this_object(), this_player());
        this_player()->heal_stat("ap", heal);
        call_out("fightheal_1", 10, this_player());
        return;
    }
    if( i == 1) {
        heal = random(250)+50;
        message_vision("\n$N"HIR"�o�X�}�}���~�A���G�^�_�F"NOR"$n"HIR"����O�C("+heal+")\n\n"NOR, this_object(), this_player());
        this_player()->heal_stat("hp", heal);
        call_out("fightheal_1", 10, this_player());
        return;
    }
    if( i == 2) {
        heal = random(120)+20;
        message_vision("\n$N"HIY"�o�X�}�}���~�A���G�^�_�F"NOR"$n"HIY"���ۢޡC("+heal+")\n\n"NOR, this_object(), this_player());
        this_player()->heal_stat("mp", heal);
        call_out("fightheal_1", 10, this_player());
        return;
    }
    return;
}
