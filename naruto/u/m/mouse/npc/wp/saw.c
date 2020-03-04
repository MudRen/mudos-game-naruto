#include <weapon.h>
#include <ansi.h>

inherit F_WEAPON;

void create()
{
    set_name(HIY"�q"HIW""BLK"��"NOR, ({ "An Electroc Saw", "saw" }));
    set_weight(15000);
    setup_weapon(100, 150, 200, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "twohanded" }) );
        set("unit", "�`");
        set("value", 10);
        set("long", "�@�`�¤O�j�j���q���A���󪺪F�賣�g���_���@���C\n" );
        set("wield_msg", "$N���_$n�����ԤF�X�U�A���M$n�o�X�F�F���n���ö}�l��ʡC\n");
        set("unwield_msg", "$n�n�����������A$n����ʤ]����F�C\n");
    }
    // ���[��O
    set("apply_weapon/righthand", // ����A��
        ([ "str" : 10,            // �ݩʡG�O�q
           "attack" : 10,         // �����O�q
           "intimidate" : 10,     // ������O
    ]) );
    set("apply_weapon/twohanded", // ����A��
        ([ "str" : 10,            // �ݩʡG�O�q
           "attack" : 20,         // �����O�q
           "intimidate" : 20,     // ������O
    ]) );
    setup();
}
