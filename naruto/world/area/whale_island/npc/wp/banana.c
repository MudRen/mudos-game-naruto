#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;

void create()
{
    set_name(HIY"����"NOR, ({ "banana" }));
    set_weight(15000);
    setup_weapon(75, 90, 100, 1);
    
    if( !clonep() ) {
            set("wield_as", ({ "twohanded" }) );
        set("unit", "��");
          set("value", 44982);
        set("long", @long
    �o�O�@�ڥ��j�������A�ڥ��N�O�@����j�F�A�A�յۥκɤO��]
�L�k��U�����֡A�ݼˤl�N�u��o�ˤl���ۤF�C
long
);
    }
    
    // ���[��O
      set("apply_weapon/twohanded", 
          ([ "str" : 1, "int" : 2, ]) 
   );

    setup();
}

