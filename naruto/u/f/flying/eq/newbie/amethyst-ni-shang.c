#include <ansi.h>
#include <armor.h>

inherit F_CLOTH;

void create()
{
    set_name(MAG"�����O�n"NOR, ({ "Amethyst ni shang", "shang" }) );

    set_weight(200);

    setup_cloth();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 10);
        set("long", "���@�_�礧�@�A�ڦ��j�T�����ϥΪ��F�Ӫ���O�C�ǻ��O�P�k�U�Z�~��\n"
                    "�ɦ�A�QACME�����C\n");
        set("wear_as", "cloth");
        set("apply_armor/cloth", ([
            "armor": 20,
            "dex": 5,
            "evade": 15,
            "wittiness": 15,
            "dodge": 12,
        ]));
    }
    setup();
}

