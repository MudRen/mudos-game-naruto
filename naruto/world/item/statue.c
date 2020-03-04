/* statue.c write by -Acme-
*/

#include <login.h>
#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(HIW"�J��"NOR, ({ "statue"}));
    set_weight(3);
    if( !clonep() ) {
        set("unit", "�L");
        set("value", 0);
        set("no_box", 1);
        set("no_get", 1);
        set("long", "�@�L�Ӹ��������J���A��������|�X�{�b�o�Ӧa��A�A�i�H�o�{�J��\n"
                    "���D�`���ơA�n���`�`���H�hĲ�N(touch)���ˤl�C");
    }
    setup();
}

void init()
{
    add_action("do_touch", "touch");
}

int do_touch(string arg)
{
    object room;

    if( environment(this_object())->is_area() )
        if( !area_environment(this_object(), this_player()) ) return 0;

    if( this_player()->is_busy() || this_player()->is_fighting() ) 
        return notify_fail("�A�{�b�S���šC\n");

    if( !arg ) return notify_fail("�A�QĲ�N����F��H\n");

    if( !this_object()->id(arg) ) return notify_fail("�A�QĲ�N����F��H\n");

    if( !objectp(room = load_object(START_ROOM)) ) {
        message_vision("$N���⩹$n���N�F�X���A�õo�X�u�������v�����n...\n", this_player(), this_object());
        return 1;
    }

    message_vision("$N���⩹$n���N�F�X���A�õo�X�u�������v�����n�A���۴N�����F�C\n", this_player(), this_object());

    this_player()->move(room);
    
    message_vision("$N��M�q�ѤW���F�U��...\n", this_player());

    this_player()->start_busy(3);

    return 1;
}
