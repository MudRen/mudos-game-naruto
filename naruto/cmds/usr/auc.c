/* sell.c by -Acme-
*/
// inherit "/adm/daemons/aucd.c";

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int auc_item(object item, int value)
{
    string name;

    if( this_player()->query("level") < 20 )
        return notify_fail("�A�����Ť��� 20 �šA�L�k�Q�Ω�檫�~�C\n");
    if( item->query("money_id") )
        return notify_fail("�A�n���u���v�S\n");
    if( this_player()->query("bank") < 100 )
        return notify_fail("�A���Ȧ�̤���100��A�L�k���...\n");

    if( item->query("no_sell") || item->query("no_auc") )
        return notify_fail("�o�˪F�褣����C\n");

    if( item->query("keep_this") )
        return notify_fail("�o�˪F��A�w�g keep �L�k���C\n");
    
    if( item->query("equipped") )
        return notify_fail("�o�˪F��A�w�g�˳ƵۡA�L�k���C\n");

    name = ( item->query_amount() ? chinese_number(item->query_amount()) : "�@" );
    name += ( item->query("base_unit") ? item->query("base_unit") : 
            ( item->query("unit") ? item->query("unit") : "��" ) );
    name += item->query("name");

        if( !AUC_D->do_stock(this_player(), item, value) )
        return notify_fail("���Ӧ��G���@���U�o�˪��~�C\n");
    this_player()->add("bank",-100);

      CHANNEL_D->do_channel(
                this_player(),
                "aucc",
    "�H���" + chinese_number(value) + "��Ȥl�������}�l�i����" + name + "(" +  CHINESE_D->chinese_date(time()) + ")�C"

        );
    return 1;
}

int do_list_aucer(string aucer)
{
        this_player()->start_more(AUC_D->do_list(aucer));
        return 1;
}

int do_search_goods(string name)
{
    this_player()->start_more(AUC_D->do_search_goods(name));
    return 1;
}

int do_identify(int id)
{
        this_player()->start_more(AUC_D->do_identify(id));
        return 1;
}

int main(object me, string arg)
{
        int id, amount, value;
        object item;
            string *tuned_ch;

//     return notify_fail("�ͧJ�ʩ����ثe�Q�j�D�Y����A�A�S��k�ϥΡC\n");

        tuned_ch = me->link()->query("channels");
                /*      �ɥR�W aucc ���W�D */
        if( !pointerp(tuned_ch) ) me->link()->set("channels", ( { "aucc"  } ) );
        else if( member_array("aucc", tuned_ch)==-1 )
            me->link()->set("channels", tuned_ch + ( { "aucc"  }) );

    // �˵��Ҧ���檫
    if( !arg ) return do_list_aucer(0);

    // ���ӫ~
    if( sscanf(arg, "sell %d %s value %d", amount, arg, value) == 3 ) {
        object new_item;
        if( !(item = present(arg, me)) ) return notify_fail("�A�Q�n��椰�򪫫~�H\n");
        if( amount <= 0 )  return notify_fail("�A�Q�n���X�Ӫ��~�H\n");
        if( item->query_amount() < amount )
                return notify_fail("�A���W�S���o��h��" + item->query("name") + "�C\n");

        // �ۦP�ƶq
        if( amount == item->query_amount() ) return auc_item(item, value);

        if( !objectp(new_item = new(base_name(item))) )
                return notify_fail("�A���G�L�k���o�˪��~�C\n");

        new_item->set_amount(amount);
        item->add_amount(-amount);

        // �L�k��X�A�hdest new_item, �ñN�쥻��item amount��_
        if( !auc_item(new_item, value) ) {
                destruct(new_item);
                item->add_amount(amount);
        }

        return 1;
    }

    if( sscanf(arg, "sell %s value %d", arg, value) == 2 ) {
        if( !(item = present(arg, me)) )
            return notify_fail("�A�Q�n��椰�򪫫~�H\n");
        return auc_item(item, value);
    }

    // �ʶR�ӫ~
    if( sscanf(arg, "buy %d %d", amount, id) == 2 ) {
        AUC_D->to_sell(this_player(), id, amount);
        return 1;
    }

    if( sscanf(arg, "buy %d", id) == 1 ) {
        AUC_D->to_sell(this_player(), id, 1);
        return 1;
    }

    // �˵��ӤH��檫
    if( sscanf(arg, "?%s", arg) == 1 ) return do_list_aucer(arg);

    // �j�M��檫�W��
    if( sscanf(arg, "/%s", arg) == 1 ) return do_search_goods(arg);

    // �˵��ӫ~
    if( sscanf(arg, "%d", id) == 1 ) return do_identify(id);

    // ���^���~�Ϊ���
    if( sscanf(arg, "take %s", arg) == 1 ) {
        if( arg == "money" ) {
            AUC_D->get_money(this_player());
            return 1;
        } else {
            if( AUC_D->get_goods(this_player(), atoi(arg)) )
                CHANNEL_D->do_channel(this_player(), "aucc", "�N�s��" + arg + "���ӫ~�U�[�C");
            return 1;
        }
    }

    return 1;
}

int help(object me)
{
  write(@HELP
���O�榡 : auc                                 �C�X�Ҧ����b��檺���~
           auc <�s��>                          �˵��Ӫ��~����O

           auc ?<���aID>                       �d�߬Y���a��檺���~�C��
                                               �p�G auc ?acme
           auc /<����r>                       �d�߬Y�����b��檺���~�W��
                                               �p�G auc /�C  ,  auc /blade

           auc sell <���~> value <����>
           auc sell [�ƶq] <���~> value <����> �N���W�����~�i����ó]�w����

           auc buy <�s��>
           auc buy [�ƶq] <�s��>               �R�U���b��檺�Y�s�����~

           auc take <�s��>                     ���^���b��檺���~
           auc take money                      ���^���ұo

��檫�~�ɴ����C�ѡA�C�ѥ����X�h�A�|�q�D�C�����X(���٥i�H�R)
����ᤧ�����ݦb�C�Ѥ���^���~�A�Y����^���i��|�Q�S���C
�n��檫�~�H�����ݺ�20�Ť~��A�ӥB�C�H�����20�˪��~�C
��檫�~���ݦ���100���@�����C

���G�ثe���䴩�v�СA����Ҭ������ʶR���C

HELP);
    return 1;
}
