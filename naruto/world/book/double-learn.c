#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("�i"HIG"���I�G����"NOR"�j�@�p��", ({ "double learn-points book", "book", "__BOOK__" }));
    set_weight(1);
    if( !clonep() ) {
        set("unit", "��");
      set("value", -1);
         set("long", "�@�ӨϥΫ�i�H���A�b�@�p�ɤ�����o�����ǲ��I�ƪ����_���b�C\n"
                    "�ϥΤ覡�G use book\n");
    }

    setup();
}

void do_use(object me, string arg)
{
    mapping c;
    mapping cnd = ([]);

    message_vision(HIW"$N�N$n"NOR+HIW"�r�b�L���A����P�ɵ��L�I�I\n\n"NOR, me, this_object());
    message_vision("$N�|�g���X�ƹD���~�A��ӤH��R���Ъ��A�����D�b��������l...\n",me);

    if( !mapp(c = me->query_condition("double-learn")) ) c = ([]);

    cnd["name"] = HIG"���I�G��"NOR;
    cnd["duration"] = 1800 + c["duration"];
    me->set_condition("double-learn", cnd);

    destruct(this_object());
}
