#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name("����", ({ "octopus" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", 40);
        set("base_weight", 100);
        set("food_stuff", 30);              // �����q�A���~�@�w�n�������q
        set("long", "���v�ͪ��A�ϥΧl�L�����ʡC�����O�ث��o�����ͪ��A���`�|�H�O�@\n"
                    "�����æۤv�C�K���}�O�e���S�x�C\n");
    }
    setup();
}
