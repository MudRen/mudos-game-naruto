#include <ansi.h>
#include <armor.h>
inherit F_FINGER_EQ;
void create()
{
    set_name(BRED+HIR"���~�P�@"NOR, ({ "blood finger", "finger" }) );
    set_weight(100);
    setup_finger_eq();
    if( !clonep() ) {
        set("unit", "�u");
        set("value", 0);
        set("long", "�㦳�����\�Ī�����\n");
        set("wear_as", "finger_eq");
        set("apply_armor/finger_eq", ([
            "dex": 5,
            "str": 5,
            "int": 5,
            "con": 5,
            "armor": 10,
            "continual hit": 30,
            "parry": 30,
            "combat": 30,
            "ninja": 30,
            "magic": 30,
            "force": 30,
            "savage hit": 30,
            "heavy hit": 30,         
            ]) ); 
   set("wear_msg",RED+"$N���W"+name()+RED"���P�ɡA�⤤���t���d�J�Ԭ�M�z�{�X�ӡI\n"NOR);
    }

    setup();
}


