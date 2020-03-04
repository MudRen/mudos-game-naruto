#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("�i"HIW"�O�����L�h"NOR"�j��ѧޯ�", ({ "book" }));
    set_weight(1);
    if( !clonep() ) {
        set("unit", "��");
        set("value", -1);
        set("long", "�@�ӨϥΫ�i�H�i�H���A��ѱ��ǲ߹L���ޯ�C\n"
                    "�ϥΤ覡�G use book to <�ޯ�>\n");
    }

    setup();
}

void do_use(object me, string arg)
{
    int point;

    if( !arg ) {
        write("�A�n��Ѥ���ޯ�H\n");
        return;
    }

    if( !me->query_skill(arg) ) {
        write("�A�S���ǹL " + arg + " �o�ӧޯ�...\n");
        return;
    }

    message_vision(HIW"$N�N"BGRN+HIY"�i"HIW"�O�����L�h"HIY"�j"NOR+HIW"���b�r�b�L���A����P�ɵ��L�I�I\n\n"NOR, me);
    message_vision( "$N���D�G" + HIG "�ѱ��i" + arg + "�j���s�b�C\n\n"NOR +
                    HIW"�Ѫũ��M���U�@��W�j���K�l�A������$N�Y�W�V�h�I�I�I\n"NOR +
                    HIM"$Nݳ���Y�W���j�]�A�b�a�W�������u�s�z�A�y�W�G��������\���A�D�`���T�V...\n\n"NOR, me);

    point = me->query_skill_ability(arg);
    me->add_point("skill", point);
    me->delete_skill(arg);

#ifdef SAVE_USER
    if( (int)me->save() ) {
        write("�ɮ��x�s�����C\n");
        me->set_temp("last_save", (int)(time()/60) );
    }
#endif

    destruct(this_object());
}
