/* mouse_tooth.c
   �츭���U���D�����S�O����...
   write by -Acme-
*/

#include <ansi.h>
#include <armor.h>

inherit F_CLOTH;

void create()
{
    set_name(YEL"����"NOR, ({ "cockroach's wings", "wings" }) );

    set_weight(1200);

    setup_cloth();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 105900);
        set("long", "�@�泌�j�������ͻH�A���W�h��n���|���@�ˡC\n");
        set("wear_as", "cloth");
        set("apply_armor/cloth", ([
            "armor": 10,
            "dex": 3,
            "evade": 10,
            "wittiness": 10,
            "dodge": 10,
        ]));
    }
    setup();
}