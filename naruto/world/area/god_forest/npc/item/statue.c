#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(WHT"�s�Ťj���۹�"NOR, ({ "statue", "_DRAGON_STATUE_" }));
    set_weight(1);
    if( !clonep() ) {
        set("unit", "�L");
        set("value", 0);
        set("no_box", 1);
        set("no_get", 1);
        set("long", "�ݰ_�Ӯݮݦp�ͪ��۹��A�߿W�ݤf�������Q�}�F�@�Ӥj�}�A�q�̭���\n"
                    "�c�y�ӬݡA���G�O����F��Q�ި��F�C���L�N��p���̵M����۹�\n"
                    "�Ҵ��o����աA�Pı�o���O�@�몺�۹��C\n"
                    "�]�\�A�i�H��F���^�O(beset)�i�o�Ӥj�}���C\n");
    }
    setup();
}
void init()
{
    add_action("do_beset", "beset");
}
int do_beset(string arg)
{
    object me, obj;

    me = this_player();

    if( !me->query_temp("know_dragon") ) {
        me->set_temp("know_dragon", 1);
        tell_object(me, CYN"�n���Ƕi�A��������...�y�C�~�I...��Ŧ�I...�z\n"NOR);
        tell_object(me, CYN"�i���n���D�`�L�z�Ať���X�өҥH�M�ӡC\n"NOR);
    }
    if( !arg ) return notify_fail("�A�Q�n�^�O����F��H\n");
    if( me->is_busy() ) return notify_fail("�A���b���L���A�����^�O�C\n");
    if( !objectp(obj = present(arg, me))) return notify_fail("�A���W�S���o�˪F��C\n");
    if( obj->query("keep_this") ) return notify_fail("�o�˪F��A�w�g keep �L�k�^�O�C\n");
    if( me->query_level() != 40 ) return notify_fail("�۹��o�X�j�j�������A�L�k�^�O�C\n");

    if( obj->query("name") == HIY"���~"RED"��Ŧ"NOR ) {
        message_vision("$N�N"+obj->query("name")+"�^�i$n�����I\n"NOR, me, this_object());
        me->start_busy(6);
        call_out("lvup_1", 5, me, this_object());
        destruct(obj);
    } else {
        return notify_fail("�o�˪F�褣�A�X�O�J�C\n");
    }
    return 1;
}
void lvup_1(object me, object ob)
{
    message("system", HIY"\n\n\t�q���~�˪L�@�h�o�X�j�P�������I\n\t"NOR+YEL"������~�����ۤƦ��s���A��Ѫŵo�X��q�I"NOR"\n\n\t���~�˪L�@�h���D�w"HIG"�s�Ťj��"NOR"���ʦL\n\t"HIW"�Q�^�i��"NOR+HIC+BLINK+me->query("name")+NOR"("CYN+BLINK+me->query_id()+NOR")"HIW"���}�ѤF..."NOR"\n\n\t"HIC"�Ӧb����ݰ}�� "HIR+me->query("title")+HIC" �����A�]�L�H������L���W���F�I\n\n\n"NOR, users());
    me->move(_DIR_AREA_"god_forest/king2.c");
    if( me->query("class") == "hxh_intermediate" ) {
        me->set_class("hxh_senior");
        tell_object(me, HIY"�]���W�n�������A�y�H���|�ɧA����¾�y�H�F�I\n"NOR);
    } else if( me->query("class") == "middle" ) {
        me->set_class("superior");
        tell_object(me, HIY"�]���\���ѨM���j�ƥ�A�츭�Ԫ̧��M�w�N�A���ɬ��W�ԡI\n"NOR);
    } else if( me->query("class") == "thief_sea" ) {
        me->set_class("big_sea");
        tell_object(me, HIY"�@�ɬF���󭫵��A���¯٩ʡA������A���a����B�����j����I\n"NOR);
    } else if( me->query("class") == "soldier_sea" ) {
        me->set_class("officer_sea");
        tell_object(me, HIY"�A�������Ȧ��\�A�Q�¤��h�x�����ŤF�I\n"NOR);
    } else {
        tell_object(me, HIR+BLINK"���G�X�F������D...\n"NOR);
    }
    me->add("level", 1);
    CLASS_D(me->query_class())->advance_level(me);
    RACE_D(me->query_race())->advance_level(me);
    tell_object(me, HIY"�A�����Ŵ��ɦ� "+me->query_level()+" �šC\n"NOR);
    if( me->query_temp("dolomite_ok") ) me->delete_temp("dolomite_ok");
    return;
}
