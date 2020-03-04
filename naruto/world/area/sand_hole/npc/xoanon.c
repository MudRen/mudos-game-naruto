#include <npc.h>
#include <ansi.h>

void create()
{
    if( random(40) == 20 ) {
        set_name(HIY"�����۹����L"NOR, ({ "golden xoanon", "xoanon" }) );
        set_level(45);
        set("long", "���⪺���j�۹��L�A�ڻ��O�۹��Q�Ӷ��Ӯg����ܤƦӦ��C\n");
        set("item_drop", "/world/area/sand_hole/npc/eq/waist.c");
        set("molecule", 1);            // ���l
        set("denominator", 100);       // ����
        set("set_drop", ({
            ([ "type":"wp", "id":6, "amount":1, "p1":40, "p2":100 ]),       // ���b��
            ([ "type":"wp", "id":37, "amount":1, "p1":15, "p2":100 ]),      // ���`���
            ([ "type":"eq", "id":113, "amount":1, "p1":1, "p2":400 ]),      // �Ӷ����@�a
        }) );
    } else {
        set_name("�۹����L", ({ "xoanon" }) );
        set_level(35);
        set("long", "�Q�F�s���X�Ϫ��_�ǥ۹��A���G�O�F�޻��j��}�����ݡC\n");
        set("item_drop", "/world/area/sand_hole/npc/eq/waist.c");
        set("molecule", 1);            // ���l
        set("denominator", 400);       // ����
        set("set_drop", ({
            ([ "type":"wp", "id":44, "amount":1, "p1":40, "p2":100 ]),      // �j�۩�
            ([ "type":"wp", "id":32, "amount":1, "p1":15, "p2":100 ]),      // ����
        }) );
    }
    set_race("human");
    set("attitude", "aggressive");
    set("age", 1000+random(5001));
    set("title",YEL"�j�N����"NOR);
    setup();
    carry_object(_DIR_AREA_"thorn_pine/npc/wp/whirls_axe.c")->wield("twohanded");
    carry_object(_DIR_AREA_"blood_wild/npc/eq/black_streak_gloves.c")->wear();
    carry_object(__DIR__"eq/waist.c")->wear();
    add_temp("apply/armor", 300);
}
