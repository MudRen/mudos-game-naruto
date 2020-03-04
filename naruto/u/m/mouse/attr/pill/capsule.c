#include <ansi.h>
inherit ITEM;

void create()
{
    set_name(RED"��"HIW"��"HIK"���n"NOR, ({ "capsule" }));
    switch( random(4) ) {
        case 0: set("name",HIR"[�O�q]"NOR+query("name"));
                set("attr","str");
                break;
        case 1: set("name",YEL"[���]"NOR+query("name"));
                set("attr","con");
                break;
        case 2: set("name",HIC"[�ӱ�]"NOR+query("name"));
                set("attr","dex");
                break;
        case 3: set("name",HIB"[���z]"NOR+query("name"));
                set("attr","int");
                break;
    }
    set("unit", "��");
    set("value", 0);
    set("no_box", 1);
    set("no_sell", 1);
    set("no_drop", 1);
    set("check_pill", 1);
    set("long", "���n�����p�ĤY�A���o�����@�뽦�n�u�O�N�ĩ�J�H�C��Ϥ������C\n"
                "���ĥ~�ߪ��C��z���ਣ�䤤�A�Ĥ��b��q���A�b�䳷�աC�����a��\n"
                "���H�g�b���y���m���A�ո̫o�O�@���ťաA�u���ǳ\���į��b����C\n"
                "����C��\����G�����O���A���O�o�Q�W��H��k�X�����ġC\n"
             HIY"�ϥΤ�k��(use capsule)�A"NOR+BLINK+HIR"�`�N�G"NOR+HIR"�Y�U��|�N���ݩʦ^�k��1�šI"NOR);
}

void do_use(object me)
{
    int attr;
    object ob = query("attr");
    if( me->query_attr(ob, 1) <= 20 ) {
        write("�A�{�b�����p���ݭn�Y�o���ġC\n");
        return;
    }
    if( me->is_busy() ) {
        write("�A�����ۡA�S���ŦY�ġC\n");
        return;
    }
    if( me->is_fighting() ) {
        write("�԰����ٶæY�ġA����`���C\n");
        return;
    }
    message_vision("\n$N���_$n���L�̤@��A�ܤF�f����$n�]�i�{���C\n\n", me, this_object());

    attr = me->query_attr(ob, 1) - 20;

    message_vision(HIW"$N���M�}�U�@�Ӥ�í�A�����@�դf�R�ժj�˦b�a�W�C\n\n"NOR, me);

    me->add_point("attribute", attr);
    me->set_attr(ob, 20);

    me->unconcious();
    destruct(this_object());
}
