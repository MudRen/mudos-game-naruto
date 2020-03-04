#include <ansi.h>
#include <command.h>

inherit F_CLEAN_UP;

private void create() { seteuid(getuid()); }

int main(object me, string arg)
{
    int value;
    object ob;
    seteuid(geteuid(this_player(1)));

    if( me->is_busy() ) return notify_fail("�A�{�b�S�šI\n");

    if( !arg || arg=="" ) return notify_fail("�A�n�^�m����H\n");

    ob = present(arg, me);
    if( !ob ) ob = present(arg, environment(me));
    if( !ob ) return notify_fail("�o����S���o�˪F��...\n");
    if( ob->is_corpse() && ob->query("userp") ) return notify_fail("�A����^�m���a������C\n");
    if( ob->is_character() && !ob->is_corpse() ) return notify_fail("�A�u��^�m�u�F��v�C\n");
    if( ob->query("no_sac") ) return notify_fail("�o�˪F��L�k�^�m...\n");
    if( ob->query("money_id") ) return notify_fail("�o�˪F��L�k�^�m...\n");
    if( ob->query("no_get") ) return notify_fail("�o�˪F��L�k�^�m...\n");
    if( ob->query("equipped") ) return notify_fail("�n�^�m�o�˪F��A�Х������˳�...\n");
    if( ob->query("keep_this") ) return notify_fail("�o�˪F��w�gkeep�A�Х��Ѱ�keep�~��^�m�C\n");
    if( (!ob->query("value") || ob->query("value") == 0) && !ob->is_corpse() ) return notify_fail("�o�F��ӯ}�¤F�A�L�k�^�m�C\n");

    message_vision(YEL"$N�C�}�����A�L�̻��w�y�v(Acme)���W���A�C�C�a$n"+YEL"�Q�@�}�·ϥ]������F�C\n"NOR, me, ob);
 
    destruct(ob);
    if( ob ) {
        write("�A�L�k�N�o�Ӫ���j��R���C\n");
        return 1;
    } 

    value = random(10)+1;
    write("�A�Ȧ�W�[�F" + chinese_number(value) + "�Ȩ�C\n");
    me->add("bank",value);

    return 1;
}

int help()
{
    write(@TEXT
���O�榡�Gsac <���~>

�o�ӫ��O���A�N�S���Ϊ��F��^�m���j�a�A����o�@�ǻȨ�C

TEXT
    );
    return 1;
}
