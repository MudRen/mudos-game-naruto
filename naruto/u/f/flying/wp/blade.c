#include <weapon.h>
#include <ansi.h>

inherit F_WEAPON;

void create()
{
    set_name(HIY"�٭��M"NOR, ({ "jhan shou blade", "blade" }));
    set_weight(15000);
    setup_weapon(100, 130, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "twohanded" }) );
        set("unit", "��");
        set("value", 365230);
        set("long", "�ԤM�C�H���A�������k�`�Ԫ̦A���٪��R�M�A�A���ٴ��Q�Φۤv����\n"
                    "�`�H�äO�N�٭��M��@����D��ϥΡC\n" );
    }
    
    // ���[��O
    set("apply_weapon/twohanded", 
        ([ "str" : 5,            // �ݩʡG�O�q
           "attack" : 5,         // �����O�q
           "intimidate" : 10,     // ������O
    ]) );

    setup();
}


