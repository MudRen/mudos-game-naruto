#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;
void create()
{
    set_name(HIR"�F�]���"NOR,({"yan mo blade","blade"}));;
    set_weight(15000);
    setup_weapon(170, 200, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "��");
        set("value", 800000);
        set("long",RED"���ݰ��ڪ��h��T�D�k�s�ɼC�ʩҥ��y���]�M�O�]�g���٩ұM�ݪ��ؤM\n"
                      "���ӬO�F�蹩�ߩҫ���������g���������y����ɭԧ⥦���^���m���]�g�C\n"
                      "�b�M�`������������]�i��N�O�o��M����q�ӷ��a�C\n"NOR);
}
    set("apply_weapon/twohanded", 
        ([ "str"   : 3,            
           "con"   : 3,
           "hp"    : 1000,        
    ]) );
    setup();
}

