/* recall.c */

#include <ansi.h>
#include <login.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
    int pay = 0;
    if( !objectp(me) ) return 0;

    if( me->is_fighting() )
        return notify_fail("�A�٦b�԰����A�L�k�ϥ� recall ���O�C\n");

    if( me->is_busy() ) 
        return notify_fail("�A�����ۡA�L�k�ϥ� recall ���O�C\n");

    if( environment(me) && environment(me)->query("no_recall") )
        return notify_fail("�A�Ҧb���a��L�k�ϥ� recall ���O�C\n");

    if( me->query_temp("no_recall") )
        return notify_fail("�A�{�b�L�k�ϥ� recall ���O�C\n");

	if( me->query_level() <= 20 ) pay = 0;
	else pay = me->query_level() * (me->query_level()/10);

    if( !wizardp(me) && me->query("bank") < pay )
        return notify_fail("�A���Ȧ�̤��� " + pay + " ��Ȥl�A�L�k�V�ѯ��D�U�C\n");
    me->add("bank", -pay);
    message_vision(HIM"$N���W�����A�L�̻��w���p�L(Jolin)���W���A�C�C�a�Q�@�}�C�m�����]��F�C\n"NOR, me);

    me->start_busy(1);

    call_out("do_move", 2, me, arg);

    return 1;
}

int do_move(object me, string arg)
{
    string tmp;
    object room;

    if( arg == "start" ) tmp = START_ROOM;
    else {
    	if( !(tmp = me->query("recoverroom")) ) tmp = START_ROOM;
    }

    if( !objectp(room=load_object(tmp)) ) 
        if( !objectp(room=load_object(START_ROOM)) )
            tell_object(me, "��M�ɪŵo�ͤ@�}���áI�A�L�k���ʡI\n");

    message_vision(HIG"�u��$N"HIG"������Ʀ���������A�����b�b�ŤF....\n"NOR,me);

    me->move(room);

    message_vision(HIW"�@�}�M���j�Ӱ}�}�����A$N�����v�������������T\n"NOR,me);

    return 1;
}

int help(object me)
{
    write(@HELP
���O�榡�R recall [start]

�o�ӫ��O�i�H���A���t��^�����I�C�Y�[�Ѽ� start �h�|�^��Ův�����C
�ϥγo�ӫ��O�@�������^�m�@�ǻȨ⵹�ѯ��~��C

LV01 ~ LV20    ���ݭn�^�m
LV21 ~         �̷Ӥ��� LV * (LV/10) �Ӱ^�m�Ȩ�

�ҡGLV30   30*(30/10) = 30*3 = 90(�Ȩ�)
    LV55   55*(55/10) = 55*5 = 275(�Ȩ�)
HELP);
    return 1;
}
