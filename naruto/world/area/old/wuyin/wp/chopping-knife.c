
#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name("��M", ({ "chopping knife", "knife" }));
    set_weight(6000);
    setup_weapon(24, 26, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "lefthand" }) );
        set("unit", "��");
        set("value", 5000);
        set("long", "����߱ڪ��̳߷R�Z���A�ɱ`���æb�I��A�N�����������ĤH�C\n" );
    }

    setup();
}

