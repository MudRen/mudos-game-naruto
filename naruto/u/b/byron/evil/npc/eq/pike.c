#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;
void create()
{
    set_name(HIW"�T�ϴu"NOR,({"wolf fume halberd","halberd"}));;
    set_weight(15000);
    setup_weapon(150, 180, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "��");
        set("value", 800000);
        set("long",HIW"�j�͹D�u���� �j�͵��l�ұM�ݪ��Z��\n"
                      "�]�O�h�𪺯T���k�s�ɼC�ʩҥ��y���Z���C\n"NOR);
}
    set("apply_weapon/twohanded", 
        ([ "str"   : 1,            
           "con"   : 1,
           "dex"   : 1,
           "int"   : 1,
              
    ]) );
    setup();
}

