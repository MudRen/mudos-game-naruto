#include <ansi.h>

inherit ITEM;
int i;

void create()
{
    set_name(HIY"������"NOR, ({ "gold bell", "bell" }));
    if( !clonep() ) {
        set("unit", "�L");
        set("base_value", 200000);
        set("base_weight", 500);
        set("no_box", 1);
        set("long", "�ª����y�������A�ҺV�T(use)���n���X�����աA���H�߯������C");
    }
    setup();
}
int do_use(object me)
{
    if( i < 9) {
        message_vision("$N�o�X���ժ��n���u����㾴��㾴���v\n", this_object());
        i = i+1;
        return 1;
    } else if( i == 9) {
        message_vision("�u�y���v�@�n���T$n���p�ߧ�$N�V�a�F�I\n", this_object(), me);
        set_name("�l�a��"HIY"������"NOR, ({ "bad bell", "bell", "_BAD_BELL_" }));
        set("changed", 1);
        set("long", "�öQ���������A�i���w�g�V�a�F�C");
        set("base_value", 0);
        i = i+1;
        return 1;
    } else if( i > 9) {
        message_vision("$N�o���X�����n���C\n", this_object(), me);
        return 1;
    }
}
