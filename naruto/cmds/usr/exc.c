// �I�ƧI�����O by mouse 2009/2/17
// inherit "/adm/daemons/exchanged.c";
#include <ansi.h>
inherit F_CLEAN_UP;

void create()
{
    seteuid(getuid());
}

int auc_item(object item, int value, int amount)
{
    string name;
    object disco = new("/world/npc/disco.c");

    if( !wizardp(this_player()) ) return notify_fail("�u���Ův�~��W�[�s���I���ӫ~�C\n");
    if( item->query("money_id") ) return notify_fail("�u���v�O������ө����C\n");

    name = item->query("name");

    if( !EXC_D->do_stock(this_player(), item, value, amount) ) return notify_fail("�I�ưӦ��G���@���U�o�˪��~�C\n");

    CHANNEL_D->do_channel(disco, "aucc", "�����I���ӫ~"+name+"�H "YEL+value+NOR" �I�I���I�ƶ}�l�i��I�����ʡI("+CHINESE_D->chinese_date(time())+")");
    destruct(disco);
    return 1;
}

int do_list_aucer(string aucer)
{
    this_player()->start_more(EXC_D->do_list(aucer));
    return 1;
}

int do_search_goods(string name)
{
    this_player()->start_more(EXC_D->do_search_goods(name));
    return 1;
}

int do_identify(int id)
{
    this_player()->start_more(EXC_D->do_identify(id));
    return 1;
}

int main(object me, string arg)
{
    int id, amount, value;
    object item;
    string *tuned_ch;

    tuned_ch = me->link()->query("channels");

    // �ɥR�W aucc ���W�D
    if( !pointerp(tuned_ch) ) me->link()->set("channels", ( { "aucc"  } ) );
    else if( member_array("aucc", tuned_ch)==-1 ) me->link()->set("channels", tuned_ch + ( { "aucc" }) );

    // �˵��Ҧ���檫
    if( !arg ) return do_list_aucer(0);

    // ���ӫ~
    if( sscanf(arg, "sell %d %s value %d", amount, arg, value) == 3 ) {
        if( !(item = present(arg, me)) ) return notify_fail("�A�Q�n�N���򪫫~�W�[�H\n");
        if( amount <= 0 ) return notify_fail("�A�Q�n�N�X�Ӫ��~�W�[�H\n");
        if( !objectp(new(base_name(item))) ) return notify_fail("�A���G�L�k�N�o�˪��~�W�[�C\n");
        if( amount > 99999 ) return notify_fail("�I�����~�W���̰��u�� 99999 �ӡC\n");

        // �]���º�N���~��W�[�A�ۤv���~���|���l��
        // �ҥH�W�[���Ѥ]���ݦA�^�_����F��
        if( !auc_item(item, value, amount) ) {
            destruct(item);
        }
        return 1;
    }
    if( sscanf(arg, "sell %s value %d", arg, value) == 2 ) {
        if( !(item = present(arg, me)) ) return notify_fail("�A�Q�n�N���򪫫~�W�[�H\n");
        return auc_item(item, value, 1);
    }
    // �ʶR�ӫ~
    if( sscanf(arg, "buy %d %d", amount, id) == 2 ) {
        EXC_D->to_sell(this_player(), id, amount);
        return 1;
    }
    if( sscanf(arg, "buy %d", id) == 1 ) {
        EXC_D->to_sell(this_player(), id, 1);
        return 1;
    }
    // �j�M��檫�W��
    if( sscanf(arg, "/%s", arg) == 1 ) return do_search_goods(arg);

    // �˵��ӫ~
    if( sscanf(arg, "%d", id) == 1 ) return do_identify(id);

    // �R���i�I�����~
    if( sscanf(arg, "delete %s", arg) == 1 ) {
        object disco = new("/world/npc/disco.c");
        if( EXC_D->get_goods(this_player(), atoi(arg)) ) CHANNEL_D->do_channel(disco, "aucc", "�{���s�� " + arg + " ���ӫ~�H��ӧC�A�M�w�N���~�U�[�C");
        destruct(disco);
        return 1;
    }
    return notify_fail("���O���~�A�аѦ�<help exc>�C\n");
}

int help(object me)
{
  write(@HELP
���O�榡 : exc                                 �C�X�Ҧ��i�H�I�����I�ưӫ~
           exc <�s��>                          �˵��Ӫ��~����O

           exc /<����r>                       �d�߬Y�I���ӫ~����O
                                               �p�G exc /�C  ,  exc /blade

           exc buy <�s��>
           exc buy [�ƶq] <�s��>               �I���Y�s���I���ӫ~

           balance                             �d�ߥثe���h�֧I���I��

           (�H�U���O���Ův�M��)

           exc sell <���~> value <����>
           exc sell [�ƶq] <���~> value <����> �q�X�s���I���ӫ~
           exc delete <�s��>                   �N�I���ӫ~�R��

HELP);
    return 1;
}
