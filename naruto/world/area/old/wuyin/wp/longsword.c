#include <weapon.h>

inherit F_SWORD;

void create()
{
    set_name("�Ӫ��C", ({ "long sword","sword"}));
    set_weight(200);
    setup_sword(1, 10, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", "sword");
        set("unit", "��");
        set("value", 500);
        set("long", "����²�K���C�A������a�A�����ˤO�������C");
    }
    setup();
}
