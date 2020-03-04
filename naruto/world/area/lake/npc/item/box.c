#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name("�Ǯa���_", ({ "house box", "box" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", 50);
        set("base_weight", 100);
        set("no_box", 1);
        set("long", "�}�ª��_�c�A�W���K���F�ʱ������L�k���}(use)�C");
    }
    setup();
}
int do_use(object me)
{
    object item;
    if( me->query_temp("quest/applaudbox") == 2) {
        message_vision("$N����Ĳ�I$n���P�ɡA$n��M�n�̤F�_�ӡI\n", me, this_object());
        message_vision("�u���c�l�N$N��W���Ŧ⯾���l�J�c���A�P�ɵo�X�@�}��H���j���C\n", me);
        me->delete_temp("quest/applaudbox");
        if( file_size(__DIR__"bell.c") < 0 ) return 0;
        if( catch(item = new(__DIR__"bell.c")) ) return 0;
        if( item->move(me) ) {
            message_vision("\n�|�P�ǥX���������n�A�u���j�����@�L�벴��"+item->name()+"�w�w����$N�⤤�C\n", me, this_object());
            destruct(this_object());
            return 1;
        } else
        if( item->move(environment(me)) ) {
            message_vision("\n�|�P�ǥX���������n�A�u���j�����@�L�벴��"+item->name()+"�w�w���b�a�W�C\n", me, this_object());
            destruct(this_object());
            return 1;
        }
        me->delete_temp("quest/applaudbox");
        destruct(item);
        destruct(this_object());
        return 0;
    }
    message_vision("$N�ΤO��}$n�A���O���ѤF�C\n", me, this_object());
    return 1;
}
