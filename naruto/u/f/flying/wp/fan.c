#include <weapon.h>
#include <ansi.h>

inherit F_WEAPON;

void create()
{
    set_name(HIB"����"NOR, ({ "big fan", "fan" }));
    set_weight(15000);
    setup_weapon(45, 55, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "twohanded" }) );
        set("unit", "��");
        set("value", 127100);
        set("long", "�������M�ΪZ���A�i�H�t�X�ԳN���_���j���F�ЩM�ϥΧԳN�D\n"
                    "�T�^�A�åB�۷��T�A�i�H��@���m�ʪZ���ϥΡC\n" );
    }
    
    // ���[��O
    set("apply_weapon/twohanded", 
        ([ "int" : 5,            // �ݩʡG�O�q
           "con" : 5,            // ������O
    ]) );

    setup();
}

