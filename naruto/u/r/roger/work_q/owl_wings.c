#include <ansi.h>
#include <armor.h>

inherit F_CLOTH;

void create()
{
    set_name(HIY"�����l"NOR, ({ "owl wings", "wings" }) );
    set_weight(1200);
    setup_cloth();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 187700);
        set("long", "�a�������ͻH�A��W���H��@���N�ప���ƤQ�V�C\n");
        // wear��۱ԭz, unequip��U�ԭz
        set("wear_msg", "$N"HIC"�N"NOR"$n"HIC"�ܦb���W�A�|�P��_�@�}�ۭ��C\n"NOR);
        set("unequip_msg", "$N"HIC"����"NOR"$n"HIC"���˳ơC\n"NOR);
        set("wear_as", "cloth");
        set("apply_armor/cloth", ([
            "armor": 15,
            "dex": 4,
            "evade": 15,
            "wittiness": 10,
        ]));
    }
    setup();
}
