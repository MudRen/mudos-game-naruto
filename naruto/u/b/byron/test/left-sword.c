#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;
void create()
{
    set_name(HIC"�C�P�ˮp�C"NOR,({"sevenstar barb sword","sword","sevenstar"}));;
    set_weight(15000);
    setup_weapon(170, 200, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "lefthand" }) );
        set("unit", "��");
        set("value", 800000);
        set("long",HIB"�o��C�����X�n�A�i�O�b�A��X�o��C�ɡA�o�o�{�o��C���ݦ�M�i��\n"
                      "���B�A�b�C�W�W�������ǳ\\����w�y�S�X�ӡC�ǻ��o��C�O�j�N�ɲ��H\n"
                      "�Φ�M���Kű�����A�ҥH�o�@��C�O�L�񪺾W�Q�M�L�񪺦�{�C\n"NOR);
}
    // ���[��O
    set("apply_weapon/righthand", 
        ([ "str"   : 10,            
           "con"   : 10,
           "exact" : 20,         
           "mp"    : 500,        
    ]) );
    setup();
}

